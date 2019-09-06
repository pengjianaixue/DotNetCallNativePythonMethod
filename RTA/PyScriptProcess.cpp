#include "stdafx.h"
#include "PyScriptProcess.h"
#include <iostream>
//CPyProcess::CPyProcess(QObject *parent): QObject(parent), m_pRunThread(nullptr),m_ThreadHandle(nullptr), m_RunFlags(false)
//{
//
//	//this->m_Process->setProcessChannelMode(QProcess::MergedChannels);
//	connect(&this->m_Process, &QProcess::readyReadStandardOutput, this, &CPyProcess::ReadProcessOutputinfo);
//}
//
//CPyProcess::~CPyProcess()
//{
//	m_ThreadHandle = nullptr;
//}
//
//bool CPyProcess::RegisterRunList(const QList<QPair<QString, QString>>& CaseList)
//{
//	m_RegisterCaseList = CaseList;
//	return true;
//}
//
//bool CPyProcess::Start(THREADPRIORITY ThreadPriority)
//{
//	m_pRunThread = std::make_shared<std::thread>(&CPyProcess::ThreadRunFunction,this);
//	m_ThreadHandle = m_pRunThread->native_handle();
//	if (m_ThreadHandle)
//	{
//		::SetThreadPriority(m_ThreadHandle, ThreadPriority);
//	}
//	m_pRunThread->detach();
//	return true;
//}
//
//bool CPyProcess::Pause()
//{
//	if (m_ThreadHandle)
//	{
//		if (!::SuspendThread(m_ThreadHandle))
//		{
//			return true;
//		}
//		return false;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool CPyProcess::Resume()
//{
//	if (m_ThreadHandle)
//	{
//		if (!::ResumeThread(m_ThreadHandle))
//		{
//			return true;
//		}
//		return false;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool CPyProcess::Stop()
//{
//	if (m_ThreadHandle)
//	{
//		if (::TerminateThread(m_ThreadHandle, 1))
//		{
//			emit s_Processfinished(1);
//			return true;
//		}
//		return false;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool CPyProcess::IsRun() const
//{
//	return m_RunFlags;
//}
//
//
//void CPyProcess::ThreadRunFunction()
//{
//
//	//CPyProcess *threadparam = static_cast<CPyProcess*>(Param);
//	this->m_RunFlags = true;
//	QPair<QString, QString> Caseitem;
//	Q_FOREACH(Caseitem, this->m_RegisterCaseList)
//	{
//
//		this->m_Process->start(R"(python )" + Caseitem.second);
//		this->m_Process->waitForFinished();
//	}
//	this->m_RunFlags = false;
//	emit s_Processfinished(0);
//
//}
//
//void CPyProcess::ReadProcessOutputinfo()
//{	
//
//	QByteArray baStandardoutpt = m_Process->readAllStandardOutput();
//	QString msg = QString::fromLocal8Bit(baStandardoutpt);
//#ifdef _DEBUG
//	std::string smsg = msg.toStdString();
//#endif // _DEBUG
//	emit s_ProcessOutPutinfo(msg);
//	return;
//}
CPyProcess::CPyProcess(QObject *parent) 
	: QObject(parent), m_pRunThread(nullptr), 
	m_ThreadHandle(nullptr), m_RunFlags(false)
{

	this->m_Process.setReadChannel(QProcess::StandardOutput);
	this->m_pyRunner.registerReadCallBackFuntion(subProcessRunnerCallbackfun);
	connect(&this->m_Process, &QProcess::readyReadStandardOutput, this, &CPyProcess::ReadProcessOutputinfo);
}

CPyProcess::~CPyProcess()
{
	m_ThreadHandle = nullptr;
}

bool CPyProcess::RegisterRunList(const QList<QPair<QString, QString>>& CaseList)
{
	m_RegisterCaseList = CaseList;
	return true;
}

bool CPyProcess::Start()
{

	
	this->m_RunFlags = true;
	QPair<QString, QString> Caseitem;
	Q_FOREACH(Caseitem, this->m_RegisterCaseList)
	{
		if (this->m_RunFlags == false)
		{
			goto ProcessStop;
		}
		/*if(this->m_pyRunner.startRun(std::string(R"(python )") + R"(")" + Caseitem.second.toStdString() + R"(")"))
			this->m_pyRunner.waitForFinish();*/
		this->m_Process.start(QString(R"(python )") + R"(")" + Caseitem.second + R"(")");
		this->m_Process.waitForFinished();
		
	}
	ProcessStop:
		this->m_Process->terminate();
		this->m_RunFlags = false;
		emit s_Processfinished(0);
		return true;
}

bool CPyProcess::Pause()
{

	return true;
}

bool CPyProcess::Resume()
{
	return true;
}

bool CPyProcess::Stop()
{

	this->m_RunFlags = false;
	this->m_Process.terminate();
	return true;
}

bool CPyProcess::IsRuning() const
{
	return m_RunFlags;
}

bool CPyProcess::subProcessRunnerCallbackfun(const std::string &pyrunprint, void *classponiter)
{
	CPyProcess *classinstance = static_cast<CPyProcess*>(classponiter);
	emit classinstance->s_ProcessOutPutinfo(QString(pyrunprint.c_str()));
	return true;
}


void CPyProcess::ThreadRunFunction()
{

	//CPyProcess *threadparam = static_cast<CPyProcess*>(Param);
	return;
}

void CPyProcess::ReadProcessOutputinfo()
{

	QByteArray baStandardoutpt = m_Process.readAllStandardOutput();
	QString msg = QString::fromLocal8Bit(baStandardoutpt);
#ifdef _DEBUG
	std::string smsg = msg.toStdString();
#endif // _DEBUG
	emit s_ProcessOutPutinfo(msg);
	return;
}
