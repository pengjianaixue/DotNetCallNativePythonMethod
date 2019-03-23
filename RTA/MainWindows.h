#pragma once

#include <QMainWindow>
#include "RunScript.h"
#include "ui_MainWindows.h"

class MainWindows : public QMainWindow
{
	Q_OBJECT
	
public:
	MainWindows(QWidget *parent = Q_NULLPTR);
	~MainWindows();

public slots:
	bool openconfigform(int i);

private:
	Ui::MainWindows ui;
private:
	CaseScriptConfigure m_uirunscript;
private:

};
