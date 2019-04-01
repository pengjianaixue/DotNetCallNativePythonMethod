#pragma once

#include <QMainWindow>
#include <QDir>
#include <QProcess>
#include "CaseScriptConfigure.h"
#include "ui_MainWindows.h"
#include "CaseandEditorhome.h"
#include "InitConfigLoader.h"
#include "Trace.h"
#include <concurrent_unordered_map.h>
#include <thread>
#ifdef WIN32
	#include <Windows.h>
#endif // WIN32
//TODO 
//This is  Py Terminal test only
//#include "../CallPython/CallPython.h"
class MainWindows : public QMainWindow
{
	Q_OBJECT
	
public:
	MainWindows(QWidget *parent = Q_NULLPTR);
	~MainWindows();
	bool LoadInitXmlConfigure();
	bool UiInitOption();
protected:
	void closeEvent(QCloseEvent* event);
public slots:
	bool openconfigform(int i);
	bool openpycharmIDE();
	bool SetPycaseFilehome();
	bool Recvipycasefilehomepath(const QString &pycasefilehomepath);
	bool RecviPycharmhomepath(const QString &Pycharmhomepath);
	//This is  Py Terminal test only
	bool RunPyFileInTerminal();
signals:
	void Signal_emitpycasefilehomepath(const QString &pycasefilehomepath);
private://ui vars
	Ui::MainWindows ui;
	CaseandEditorhome *PythonHomeSet;
private:
#ifdef WIN32
	DWORD m_hPycharmProcessid;
#else
	long m_hPycharmProcesshandle;
#endif // WIN32

	CaseScriptConfigure		m_uirunscript;
	QProcess				*m_pyeditorprocess;
	QString					m_strPyCaseFileHomePath;
	QString					m_strPycharmBinPath;
	QString					m_strInitXmlFilePath;
	QString					m_TheCurrentPath;
	//This is  Py Terminal test only
	QProcess				*m_RunPythonCaseprocess;
	QThread                 *m_QthreadPythonCaseprocess;
	 
private:
	bool ConnectSlots();
	

};
