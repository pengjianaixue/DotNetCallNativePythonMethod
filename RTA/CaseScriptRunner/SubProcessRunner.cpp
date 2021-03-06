// SubProcessRunner.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "subProcessRunner.h"
SubProcessRunner::SubProcessRunner()
{
	m_bThreadQuit = false;
	InitializeCriticalSection(&m_critical_section);
	m_readSubProcessOutputThread = std::make_shared<std::thread>(&SubProcessRunner::readSubProcessOutput, this);
	m_processStatesNotifyThread  = std::make_shared<std::thread>(&SubProcessRunner::_isFinished, this);
	::SetThreadAffinityMask(m_processStatesNotifyThread->native_handle(), 0x00000001); //Set the thread CPU affinity to cpu.0
	::SetThreadAffinityMask(m_readSubProcessOutputThread->native_handle(), 0x0000000E);//Set the thread CPU affinity to cpu.1.2.3
	HMODULE	h_ntModule = LoadLibrary(L"ntdll.dll");
	if (h_ntModule)
	{
		m_ntSuspendProcessFun = (ntSuspendProcessFunPrototype)GetProcAddress(h_ntModule, "NtSuspendProcess");
		m_ntResumeProcessFun = (ntResumeProcessFunPrototype)GetProcAddress(h_ntModule, "NtResumeProcess");
	}
	
	
}

bool SubProcessRunner::startRun(const string &subprogrammcmd)
{	
	if (m_piProcInfo.hProcess)
	{
		return false;
	}
	if(!initMemberVar())
		return false;
	createStartUpInfo(&m_siStartInfo);
#ifdef UNICODE
	WCHAR szCommmandLine[512] = {0};
	::MultiByteToWideChar(CP_ACP, 0, subprogrammcmd.c_str(), subprogrammcmd.length() + 1, szCommmandLine,
		sizeof(szCommmandLine) / sizeof(szCommmandLine[0]));
#else
	CHAR wszClassName[512] = {0};
	::memcpy_s(wszClassName, subprogrammcmd.length(), subprogrammcmd.c_str(), m_strSubProgrammcmd.length());
#endif // UNICODE
	DWORD dwCreationFlags = (GetConsoleWindow() ? 0 : CREATE_NO_WINDOW);
	dwCreationFlags |= CREATE_UNICODE_ENVIRONMENT;
	if (!::CreateProcess(NULL,
		szCommmandLine, &m_saAttr, &m_saAttr, TRUE,
		dwCreationFlags, NULL, NULL,
		&m_siStartInfo, &m_piProcInfo))
	{
		CloseHandle(m_hReadChildStdOutRead);
		CloseHandle(m_hChildStdInWrite);
		m_hReadChildStdOutRead = NULL;
		m_hChildStdInWrite = NULL;
		DEBUGPRINT(string("CreateProcess fail ,error code:"+  std::to_string(GetLastError()) + "\r\n"));
		return false;
	}
	return true;
}

bool SubProcessRunner::isFinished() const
{	
	return m_bThreadQuit;
}
int SubProcessRunner::waitForFinish(unsigned int timeoutMilliseconds)
{
	if (m_piProcInfo.hProcess)
	{
		if (WAIT_OBJECT_0 == ::WaitForSingleObject(m_piProcInfo.hProcess, timeoutMilliseconds))
		{
			DWORD dwExitCode = 0;
			::GetExitCodeProcess(m_piProcInfo.hProcess, &dwExitCode);
			return dwExitCode;
		}
		else
		{
			std::unique_lock<std::mutex> guard(m_threadSwitchmutext, std::try_to_lock);
			if (m_piProcInfo.hThread && m_piProcInfo.hProcess)
			{
				TerminateThread(m_piProcInfo.hThread, -1);
				TerminateProcess(m_piProcInfo.hProcess, -1);
				::CloseHandle(m_piProcInfo.hThread);
				::CloseHandle(m_piProcInfo.hProcess);
				::CloseHandle(m_hReadChildStdOutRead);
				::CloseHandle(m_hChildStdInWrite);
				m_piProcInfo.hThread = nullptr;
				m_piProcInfo.hProcess = nullptr;
				m_hReadChildStdOutRead = nullptr;
				m_hChildStdInWrite = nullptr;
			}

		}
	}
	return -1;
}
bool SubProcessRunner::registerReadCallBackFuntion(READSTDOUTCALLBACKFUN callBackfunction)
{
	if (callBackfunction)
	{
		m_readCallbackfun = callBackfunction;
		return true;
	}
	return false;
}
bool SubProcessRunner::pause()
{
	if (m_piProcInfo.hProcess && m_ntSuspendProcessFun)
	{
		return m_ntSuspendProcessFun(m_piProcInfo.hProcess);
	}
	return false;
}
bool SubProcessRunner::resume()
{
	if (m_piProcInfo.hProcess && m_ntResumeProcessFun)
	{
		return m_ntResumeProcessFun(m_piProcInfo.hProcess);
	}
	return false;
}
bool SubProcessRunner::stop()
{
	std::unique_lock<std::mutex> guard(m_threadSwitchmutext, std::try_to_lock);
	if (m_piProcInfo.hThread && m_piProcInfo.hProcess)
	{
		TerminateThread(m_piProcInfo.hThread,-1);
		TerminateProcess(m_piProcInfo.hProcess, -1);
		::CloseHandle(m_piProcInfo.hThread);
		::CloseHandle(m_piProcInfo.hProcess);
		::CloseHandle(m_hReadChildStdOutRead);
		::CloseHandle(m_hChildStdInWrite);
		m_piProcInfo.hThread = nullptr;
		m_piProcInfo.hProcess = nullptr;
		m_hReadChildStdOutRead = nullptr;
		m_hChildStdInWrite = nullptr;
	}
	return true;
}


SubProcessRunner::~SubProcessRunner()
{
	//if (m_ntModule)
	//{
	//	CloseHandle(m_ntModule);
	//}
	m_bThreadQuit = true;
	if (m_readSubProcessOutputThread && m_readSubProcessOutputThread->joinable())
	{
		m_readSubProcessOutputThread->join();
		m_readSubProcessOutputThread = nullptr;
	}
	if (m_processStatesNotifyThread && m_processStatesNotifyThread->joinable())
	{
		m_processStatesNotifyThread->join();
		m_processStatesNotifyThread = nullptr;
	}
	stop();
	::DeleteCriticalSection(&m_critical_section);
}

void SubProcessRunner::createSecurityAttributes(PSECURITY_ATTRIBUTES pSa)
{
	pSa->bInheritHandle = TRUE;
	pSa->lpSecurityDescriptor = NULL;
	pSa->nLength = sizeof(SECURITY_ATTRIBUTES);
}

bool SubProcessRunner::initMemberVar()
{
	createSecurityAttributes(&m_saAttr);
	if (!::CreatePipe(&m_hReadChildStdOutRead, &m_hChildStdInWrite, &m_saAttr, 0))
		return false;
	return true;
}

void SubProcessRunner::createStartUpInfo(LPSTARTUPINFO lpStartUpInfo)
{
	ZeroMemory(lpStartUpInfo,sizeof(STARTUPINFO));	
	lpStartUpInfo->cb = sizeof(STARTUPINFO);
	lpStartUpInfo->lpReserved = 0;
	lpStartUpInfo->lpDesktop = 0;
	lpStartUpInfo->lpTitle = 0;
	lpStartUpInfo->dwX = (unsigned long)CW_USEDEFAULT;
	lpStartUpInfo->dwY = (unsigned long)CW_USEDEFAULT;
	lpStartUpInfo->dwXSize = (unsigned long)CW_USEDEFAULT;
	lpStartUpInfo->dwYSize = (unsigned long)CW_USEDEFAULT;
	lpStartUpInfo->dwXCountChars = 0;
	lpStartUpInfo->dwYCountChars = 0;
	lpStartUpInfo->dwFillAttribute = 0;
	lpStartUpInfo->dwFlags =	 STARTF_USESTDHANDLES;
	lpStartUpInfo->wShowWindow = SW_SHOWNORMAL;
	lpStartUpInfo->cbReserved2 = 0;
	lpStartUpInfo->lpReserved2 = 0;
	lpStartUpInfo->hStdInput = GetStdHandle(STD_INPUT_HANDLE);
	lpStartUpInfo->hStdOutput = m_hChildStdInWrite;
	lpStartUpInfo->hStdError = m_hChildStdInWrite;

}

void SubProcessRunner::readSubProcessOutput()
{

	char out_buffer[10000] = {0};
	while (!m_bThreadQuit)
	{
		if (m_piProcInfo.hProcess && m_hReadChildStdOutRead)
		{
			DWORD dwRead = 0;
			DWORD dwAvial = 0;
			DWORD dwLefe = 0;
			std::unique_lock<std::mutex> guard(m_threadSwitchmutext, std::try_to_lock);
			//CriticalSection_guard guard(m_critical_section);
			WaitForSingleObject(m_threadTriggerEventHandle, 10);
			BOOL bSuccess = ::ReadFile(m_hReadChildStdOutRead, out_buffer, sizeof(out_buffer), &dwRead, nullptr);
			if (bSuccess && dwRead > 0)
			{
				if (m_readCallbackfun)
				{
					DEBUGPRINT(string("Call user callback function\r\n"));
					m_readCallbackfun(string(out_buffer), this);
				}
				#ifdef QT_CORE_LIB
						emit signal_SendSubProcessStdoutContents(QString(out_buffer));
				#endif
				DEBUGPRINT(string("Subprocess output:" + string(out_buffer) + "\r\n"));
				ZeroMemory(out_buffer, sizeof(out_buffer));
			}
			else
			{
				string errorcode = std::to_string(GetLastError()).c_str();
				DEBUGPRINT(string("Read Pipe fail ,the error code :" + std::to_string(GetLastError()) + "\r\n"));
			}
			std::this_thread::yield();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	m_bTerminateFlag = true;
	return;
}

void SubProcessRunner::_isFinished()
{
	while (!m_bTerminateFlag)
	{
		if (m_piProcInfo.hProcess)
		{
			DWORD res =  ::WaitForSingleObject(m_piProcInfo.hThread, 0);
			if (res == WAIT_OBJECT_0)
			{	
				ResetEvent(m_threadTriggerEventHandle);
				if(CancelSynchronousIo(m_readSubProcessOutputThread->native_handle()))
				{
					std::unique_lock<std::mutex> guard(m_threadSwitchmutext, std::try_to_lock);
					//CriticalSection_guard guard(m_critical_section);
					::CloseHandle(m_piProcInfo.hThread);
					::CloseHandle(m_piProcInfo.hProcess);
					::CloseHandle(m_hReadChildStdOutRead);
					::CloseHandle(m_hChildStdInWrite);
					m_piProcInfo.hThread = nullptr;
					m_piProcInfo.hProcess = nullptr;
					m_hReadChildStdOutRead = nullptr;
					m_hChildStdInWrite = nullptr;
				}
				else 
				{
					DEBUGPRINT(string("CancelSynchronousIo Error code:" + std::to_string(GetLastError())));
					std::this_thread::yield();
				}
			}
			else if (res == WAIT_TIMEOUT)
			{
				SetEvent(m_threadTriggerEventHandle);
			}
			
		}
		else if (!m_bTerminateFlag)
		{
			ResetEvent(m_threadTriggerEventHandle);
			CancelSynchronousIo(m_readSubProcessOutputThread->native_handle());
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		
	}
	
}
