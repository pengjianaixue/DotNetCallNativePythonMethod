#pragma once

#include <QObject>
#include <QtCore\QProcess>
// C++ 11 stdanard library
#include <atomic>
#include <thread>
//Windows specific
#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32
#include "subProcessRunner.h"


//class PyScriptProcess : public QObject
//{
//
//	Q_OBJECT
//public:
//	typedef enum
//	{
//		lower  = -1,
//		normal =  0,
//		higher =  1,
//
//	}THREADPRIORITY;
//public:
//	PyScriptProcess(QObject *parent);
//	~PyScriptProcess();
//signals:
//	void s_Processfinished(int finishcode);
//	void s_ProcessOutPutinfo(const QString &outinfo);
//// interface
//public:
//	bool RegisterRunList(const QList<QPair<QString,QString>> &CaseList); //Only For Case 
//	bool Start(THREADPRIORITY ThreadPriority = THREADPRIORITY::normal);
//	bool Pause();
//	bool Resume();
//	bool Stop();
//	bool IsRun() const;
//private:
//	void ThreadRunFunction();
//	void ReadProcessOutputinfo();
//private:
//	QProcessEnvironment						m_ProcessEnvir; //retention 
//	QProcess								m_Process;
//	std::atomic<bool>						m_RunFlags;
//	std::shared_ptr<std::thread>			m_pRunThread;
//	//QString									m_PyFileName;
//	QList<QPair<QString, QString>>			m_RegisterCaseList;
//
//	//Windows specific
//#ifdef _WIN32
//	HANDLE									m_ThreadHandle;
//#endif // _WIN32
//	
//};
class PyScriptProcess : public QObject
{

	Q_OBJECT
public:
	typedef enum
	{
		lower = -1,
		normal = 0,
		higher = 1,

	}THREADPRIORITY;
	PyScriptProcess(QObject *parent = nullptr);
	~PyScriptProcess();
	void run();
signals:
	void s_Processfinished(int finishcode);
	void s_ProcessOutPutinfo(const QString &outinfo);
	void s_readyReadStandardOutput();
	// interface
public slots:
	bool RegisterRunList(const QList<QPair<QString, QString>> &CaseList); //Only For Case 
	bool Start();
	bool Pause();
	bool Resume();
	bool Stop();
	bool IsRuning() const;
	static bool subProcessRunnerCallbackfun(const std::string &pyrunprint,void *classponiter);
private:
	void ThreadRunFunction();
	void ReadProcessOutputinfo();
private:
	QProcessEnvironment						m_ProcessEnvir; //retention 
	std::atomic<bool>						m_RunFlags;
	std::shared_ptr<std::thread>			m_pRunThread;
	QList<QPair<QString, QString>>			m_RegisterCaseList;
	SubProcessRunner						m_pyRunner;
	//Windows specific
#ifdef _WIN32
	HANDLE									m_ThreadHandle;
#endif // _WIN32
public:
	QProcess								*m_process = { new QProcess };

};