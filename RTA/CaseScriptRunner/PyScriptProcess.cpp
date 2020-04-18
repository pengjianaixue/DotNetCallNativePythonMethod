#include "stdafx.h"
#include "PyScriptProcess.h"
#include <iostream>

#pragma region BackupCode
//PyScriptProcess::PyScriptProcess(QObject *parent): QObject(parent), m_pRunThread(nullptr),m_ThreadHandle(nullptr), m_RunFlags(false)
//{
//
//	//this->m_Process->setProcessChannelMode(QProcess::MergedChannels);
//	connect(&this->m_Process, &QProcess::readyReadStandardOutput, this, &PyScriptProcess::ReadProcessOutputinfo);
//}
//
//PyScriptProcess::~PyScriptProcess()
//{
//	m_ThreadHandle = nullptr;
//}
//
//bool PyScriptProcess::RegisterRunList(const QList<QPair<QString, QString>>& CaseList)
//{
//	m_RegisterCaseList = CaseList;
//	return true;
//}
//
//bool PyScriptProcess::Start(THREADPRIORITY ThreadPriority)
//{
//	m_pRunThread = std::make_shared<std::thread>(&PyScriptProcess::ThreadRunFunction,this);
//	m_ThreadHandle = m_pRunThread->native_handle();
//	if (m_ThreadHandle)
//	{
//		::SetThreadPriority(m_ThreadHandle, ThreadPriority);
//	}
//	m_pRunThread->detach();
//	return true;
//}
//
//bool PyScriptProcess::Pause()
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
//bool PyScriptProcess::Resume()
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
//bool PyScriptProcess::Stop()
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
//bool PyScriptProcess::IsRun() const
//{
//	return m_RunFlags;
//}
//
//
//void PyScriptProcess::ThreadRunFunction()
//{
//
//	//PyScriptProcess *threadparam = static_cast<PyScriptProcess*>(Param);
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
//void PyScriptProcess::ReadProcessOutputinfo()
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
#pragma endregion
PyScriptProcess::PyScriptProcess(QObject *parent)
	: QObject(parent), m_pRunThread(nullptr),
	m_ThreadHandle(nullptr), m_RunFlags(false)
{
	m_process->setParent(this);
	//this->m_pyRunner.registerReadCallBackFuntion(subProcessRunnerCallbackfun);
	
}

PyScriptProcess::~PyScriptProcess()
{
	m_ThreadHandle = nullptr;
}

bool PyScriptProcess::RegisterRunList(const QList<QPair<QString, QString>>& CaseList)
{
	m_RegisterCaseList = CaseList;
	return true;
}

bool PyScriptProcess::Start()
{

	/*QProcess m_Process;
	m_Process.setProcessChannelMode(QProcess::MergedChannels);
	this->m_Process = &m_Process;
	connect(&m_Process, &QProcess::readyReadStandardOutput,this, &PyScriptProcess::ReadProcessOutputinfo);*/
	/*if (!this->m_Process)
	{
		this->m_Process = new QProcess;
		this->m_Process->setReadChannel(QProcess::ProcessChannel::StandardOutput);
		this->m_Process->setReadChannelMode(QProcess::ProcessChannelMode::ForwardedChannels);
		connect(this->m_Process, &QProcess::readyReadStandardOutput, this, &PyScriptProcess::ReadProcessOutputinfo);
	}*/
	SubProcessRunner	pyRunner;
	pyRunner.registerReadCallBackFuntion(subProcessRunnerCallbackfun);
	this->m_RunFlags = true;
	QPair<QString, QString> Caseitem;
	Q_FOREACH(Caseitem, this->m_RegisterCaseList)
	{    
		if (this->m_RunFlags == false)
		{
			goto ProcessStop;
		}  
		/*if(pyRunner.startRun(std::string(R"(python )") + R"(")" + Caseitem.second.toStdString() + R"(")"))
			pyRunner.waitForFinish();*/
		this->m_process->start(QString(R"(python )") + R"(")" + Caseitem.second + R"(")");
		this->m_process->waitForFinished();
	}
	ProcessStop:
		pyRunner.stop();
		this->m_RunFlags = false;
		emit s_Processfinished(0);
		return true;
}

bool PyScriptProcess::Pause()
{

	return true;
}

bool PyScriptProcess::Resume()
{
	return true;
}

bool PyScriptProcess::Stop()
{

	this->m_RunFlags = false;
	if (this->m_process)
	{
		this->m_process->terminate();
	}
	
	return true;
}

bool PyScriptProcess::IsRuning() const
{
	return m_RunFlags;
}

bool PyScriptProcess::subProcessRunnerCallbackfun(const std::string &pyrunprint, void *classponiter)
{
	PyScriptProcess *classinstance = static_cast<PyScriptProcess*>(classponiter);
	qDebug() << pyrunprint.c_str();
	//emit classinstance->s_ProcessOutPutinfo(QString(pyrunprint.c_str()));
	return true;
}


void PyScriptProcess::ThreadRunFunction()
{

	//PyScriptProcess *threadparam = static_cast<PyScriptProcess*>(Param);
	return;
}

void PyScriptProcess::ReadProcessOutputinfo()
{

	QByteArray baStandardoutpt = this->m_process->readAllStandardOutput();
	QString msg = QString::fromLocal8Bit(baStandardoutpt);
#ifdef _DEBUG
	std::string smsg = msg.toStdString();
#endif // _DEBUG
	emit s_ProcessOutPutinfo(msg);
	return;
}
