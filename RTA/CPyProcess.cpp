#include "stdafx.h"
#include "CPyProcess.h"

CPyProcess::CPyProcess(QObject *parent): QObject(parent), m_pRunThread(nullptr),m_ThreadHandle(nullptr), m_RunFlags(false)
{
	connect(&this->m_Process, &QProcess::readyReadStandardOutput, this, &CPyProcess::ReadProcessOutputinfo);
}

CPyProcess::~CPyProcess()
{
	m_ThreadHandle = nullptr;
}

bool CPyProcess::Start(const QString & PyFileName, THREADPRIORITY ThreadPriority)
{
	m_PyFileName = PyFileName;
	m_pRunThread = std::make_shared<std::thread>(&CPyProcess::ThreadRunFunction,this,this);
	m_ThreadHandle = m_pRunThread->native_handle();
	if (m_ThreadHandle)
	{
		::SetThreadPriority(m_ThreadHandle, ThreadPriority);
	}
	m_pRunThread->detach();
	return false;
}

bool CPyProcess::Pause()
{
	if (m_ThreadHandle)
	{
		if (!::SuspendThread(m_ThreadHandle))
		{
			return true;
		}
		return false;
	}
	else
	{
		return false;
	}
}

bool CPyProcess::Resume()
{
	if (m_ThreadHandle)
	{
		if (!::ResumeThread(m_ThreadHandle))
		{
			return true;
		}
		return false;
	}
	else
	{
		return false;
	}
}

bool CPyProcess::Stop()
{
	if (m_ThreadHandle)
	{
		if (::TerminateThread(m_ThreadHandle, 1))
		{
			return true;
		}
		return false;
	}
	else
	{
		return false;
	}
}

bool CPyProcess::IsRun() const
{
	return m_RunFlags;
}


void CPyProcess::ThreadRunFunction(CPyProcess *Param)
{

	CPyProcess *threadparam = static_cast<CPyProcess*>(Param);
	threadparam->m_RunFlags = true;
	threadparam->m_Process.start(R"(python )" + threadparam->m_PyFileName);
	threadparam->m_Process.waitForFinished();
	threadparam->m_RunFlags = false;

}

void CPyProcess::ReadProcessOutputinfo()
{
	QByteArray qbt = m_Process.readAllStandardOutput();
	QString msg = QString::fromLocal8Bit(qbt);
#ifdef _DEBUG
	std::string smsg = msg.toStdString();
#endif // _DEBUG
	emit s_ProcessOutPutinfo(msg);
	return;
}