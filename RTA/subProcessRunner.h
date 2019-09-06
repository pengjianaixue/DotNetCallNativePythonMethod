#pragma once
#include <string>
#include <Windows.h>
#include <functional>
#include <thread>
#include <memory>
#include <mutex>
using std::string;
class subProcessRunner
{
public:
	using READSTDOUTCALLBACKFUN = std::function<bool(const string&,void *)>;
	subProcessRunner();
	//API 
	bool startRun(const string &subprogrammcmd);
	bool isFinished()const;
	int waitForFinish();
	bool registerReadCallBackFuntion(READSTDOUTCALLBACKFUN callBackfunction);
	bool pause();
	bool resume();
	bool stop();
	string wirteCmdtoSubprogramm();
	virtual ~subProcessRunner();
private:
	void createSecurityAttributes(PSECURITY_ATTRIBUTES pSa);
	bool initMemberVar();
	void createStartUpInfo(LPSTARTUPINFO lpStartUpInfo);
	void readSubProcessOutput();
	void _isFinished();
private:
	string	m_strSubProgrammcmd;
	bool    m_bisFinished				 = {true};
	HANDLE  m_hStdInRead				 = {nullptr};			
	HANDLE  m_hStdOutWrite				 = { nullptr };			
	HANDLE  m_hStdErrWrite				 = { nullptr };			
	STARTUPINFO m_siStartInfo			 = {};					
	SECURITY_ATTRIBUTES		m_saAttr	 = {};
	PROCESS_INFORMATION		m_piProcInfo = {};				
	READSTDOUTCALLBACKFUN			m_readCallbackfun			 = {nullptr};
	std::shared_ptr<std::thread>	m_readSubProcessOutputThread = { nullptr };
	std::shared_ptr<std::thread>	m_processStatesNotifyThread  = { nullptr };
	std::mutex						m_mutex					 = {};
};
class Mutex_guard 
{
public:
	explicit Mutex_guard(std::mutex &mutex) :m_guardmutex(mutex) { m_guardmutex.lock(); };
	~Mutex_guard() { m_guardmutex.unlock(); };
private:
	std::mutex &m_guardmutex;

};

