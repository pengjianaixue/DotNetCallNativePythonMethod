#pragma once

#include <QMainWindow>
#include <QDir>
#include <QProcess>
#include <concurrent_unordered_map.h>
#include <thread>
#include <QPair>
#ifdef WIN32
	#include <Windows.h>
#endif // WIN32
#include "CaseScriptConfigure.h"
#include "ui_MainWindows.h"
#include "CaseandEditorhome.h"
#include "InitConfigLoader.h"
#include "Trace.h"
#include "PyScriptProcess.h"
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
	bool Init();
protected:
	void closeEvent(QCloseEvent* event) override;
public slots:
	bool openconfigform(int i);
	bool openpycharmIDE();
	bool SetPycaseFilehome();
	bool Recvipycasefilehomepath(const QString &pycasefilehomepath);
	bool RecviPycharmhomepath(const QString &Pycharmhomepath);
	//This is  Py Terminal test only
	bool RunPyFileInTerminal();
	void DisplayToTerminal(const QString &PyProcessRunInfor);
	void GetExecuteCaseList();
signals:
	void Signal_emitpycasefilehomepath(const QString &pycasefilehomepath);
	bool Signal_emitPyCaseRun();
	bool Signal_emitPyCaseStop();
private://ui vars
	Ui::MainWindows ui;
	CaseandEditorhome *PythonHomeSet;
private:
#ifdef WIN32

	DWORD m_hPycharmProcessid;
#else
	long m_hPycharmProcesshandle;
#endif // WIN32

	QThread								m_CaseRunThread;
	CaseScriptConfigure					m_UICaseConfigure;
	QProcess							*m_pyeditorprocess;
	QString								m_strPyCaseFileHomePath;
	QString								m_strPycharmBinPath;
	QString								m_strInitXmlFilePath;
	QString								m_TheCurrentPath;
	PyScriptProcess						m_RunPythonCaseprocess;
	QList<QPair<QString, QString>>		m_CaseExecListToFullPathList;
private:
	bool ConnectSlots();
	void uiInit();
	

};
