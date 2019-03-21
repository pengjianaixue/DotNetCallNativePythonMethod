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

private:
	Ui::MainWindows ui;
private:
	RunScript m_uirunscript;
};
