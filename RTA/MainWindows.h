#pragma once

#include <QMainWindow>
#include <QDir>
#include <QProcess>
#include "RunScript.h"
#include "ui_MainWindows.h"
#include "CaseandEditorhome.h"
#ifdef WIN32
	#include <Windows.h>
#endif // WIN32
class MainWindows : public QMainWindow
{
	Q_OBJECT
	
public:
	MainWindows(QWidget *parent = Q_NULLPTR);
	~MainWindows();

public slots:
	bool openconfigform(int i);
	bool openpycharmIDE();
	bool SetPycaseFilehome();
	bool Recvipycasefilehomepath(const QString &pycasefilehomepath);
	bool RecviPycharmhomepath(const QString &Pycharmhomepath);
signals:
	void Signal_emitpycasefilehomepath(const QString &pycasefilehomepath);
private:
	Ui::MainWindows ui;
	CaseandEditorhome *PythonHomeSet;
private:
#ifdef WIN32
	DWORD m_hPycharmProcessid;
#else
	long m_hPycharmProcesshandle;
#endif // WIN32

	CaseScriptConfigure m_uirunscript;
	QProcess *m_pyeditorprocess;
	QString m_strpycasefilehomepath;
	QString m_strpycharmbinpath;
	 
private:
	bool ConnectSlots();
	

};
