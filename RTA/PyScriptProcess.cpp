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
PyScriptProcess::PyScriptProcess(QObject *parent) : 
											QThread(parent), m_pRunThread(nullptr),
											m_ThreadHandle(nullptr), m_RunFlags(false), 
											m_Process(nullptr)
										  

{
	/*if (!m_Process)
	{
		m_Process = new QProcess(this);
	}*/
	//this->m_Process->setProcessChannelMode(QProcess::MergedChannels);
	
}

PyScriptProcess::~PyScriptProcess()
{
	if (m_Process)
	{
		delete m_Process;
		m_Process = nullptr;
	}
	m_ThreadHandle = nullptr;
}

void PyScriptProcess::run()
{


	/*while (true)
	{*/
	if (!m_Process)
	{
		m_Process = new QProcess();
	}
	connect(this->m_Process, &QProcess::readyReadStandardOutput, this, &PyScriptProcess::s_readyReadStandardOutput);
	this->m_RunFlags = true;
	QPair<QString, QString> Caseitem;
	for (size_t i = 0; i < this->m_RegisterCaseList.length(); i++)
	{
		if (this->m_RunFlags == false)
		{
			goto ProcessStop;
		}
		qDebug() <<"Case item Name :"<< m_RegisterCaseList[i].second;
		this->m_Process->start(R"(python )" + m_RegisterCaseList[i].second);
		this->m_Process->waitForFinished();

	}
	/*Q_FOREACH(Caseitem, this->m_RegisterCaseList)
	{

		if (this->m_RunFlags == false)
		{
			goto ProcessStop;
		}
		this->m_Process->start(R"(python )" + Caseitem.second);
		this->m_Process->waitForFinished();
	}*/
	ProcessStop:
		this->m_Process->terminate();
		this->m_RunFlags = false;
		emit s_Processfinished(0);


	//}


}

bool PyScriptProcess::RegisterRunList(const QList<QPair<QString, QString>>& CaseList)
{
	m_RegisterCaseList = CaseList;
	return true;
}

//bool PyScriptProcess::Start()
//{
//	this->m_RunFlags = true;
//	QPair<QString, QString> Caseitem;
//	Q_FOREACH(Caseitem, this->m_RegisterCaseList)
//	{
//		if (this->m_RunFlags == false)
//		{
//			goto ProcessStop;
//		}
//		this->m_Process->start(R"(python )" + Caseitem.second);
//		this->m_Process->waitForFinished();
//	}
//	ProcessStop:
//		this->m_Process->terminate();
//		this->m_RunFlags = false;
//		emit s_Processfinished(0);
//		return true;
//}

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
	this->m_Process->terminate();
	return true;
}

bool PyScriptProcess::IsRuning() const
{
	return m_RunFlags;
}


void PyScriptProcess::ThreadRunFunction()
{

	//CPyProcess *threadparam = static_cast<CPyProcess*>(Param);
	return;

}

void PyScriptProcess::ReadProcessOutputinfo()
{

	QByteArray baStandardoutpt = m_Process->readAllStandardOutput();
	QString msg = QString::fromLocal8Bit(baStandardoutpt);
#ifdef _DEBUG
	std::string smsg = msg.toStdString();
#endif // _DEBUG
	emit s_ProcessOutPutinfo(msg);
	//QMetaMethod::invoke(parent,"DisplayToTerminal",);
	return;
}
