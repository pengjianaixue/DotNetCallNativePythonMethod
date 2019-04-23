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


class CPyProcess : public QObject
{
	Q_OBJECT

typedef enum
{
	lower  = -1,
	normal =  0,
	higher =  1,

}THREADPRIORITY;
public:
	CPyProcess(QObject *parent);
	~CPyProcess();
signals:
	void s_Processfinished(int finishcode);
	void s_ProcessOutPutinfo(const QString &outinfo);
// interface
public:
	bool Start(const QString &PyFileName, THREADPRIORITY ThreadPriority = THREADPRIORITY::normal);
	bool Pause();
	bool Resume();
	bool Stop();
	bool IsRun() const;
private:
	void ThreadRunFunction();
	void ReadProcessOutputinfo();
private:
	QProcessEnvironment						m_ProcessEnvir; //retention 
	QProcess								m_Process;
	std::atomic<bool>						m_RunFlags;
	std::shared_ptr<std::thread>			m_pRunThread;
	QString									m_PyFileName;

	//Windows specific
#ifdef _WIN32
	HANDLE									m_ThreadHandle;
#endif // _WIN32
	
};
