#pragma once

#include <QMainWindow>
#include <QDir>
#include <QProcess>
#include "RunScript.h"
#include "ui_MainWindows.h"
#include "CaseandEditorhome.h"
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

private:
	Ui::MainWindows ui;
	CaseandEditorhome *PythonHomeSet;
private:
	CaseScriptConfigure m_uirunscript;
	QString m_strpycasefilehomepath;
	QProcess *m_pyeditorprocess;
private:
	bool ConnectSlots();
	

};
