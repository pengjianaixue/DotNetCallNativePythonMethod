#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PyRunner.h"
#include "../CallPython/CallPython.h"

class PyRunner : public QDialog
{
	Q_OBJECT

public:
	PyRunner(QDialog *parent = Q_NULLPTR);
	~PyRunner();
public slots:
	 int TestRun();
	 int Reset();

private:
	Ui::PyRunnerTestClass ui;
private:
	std::string m_strRunres;
	CCallPython m_cpycaller;
	PARAMLIST   m_callpyparmlist;
};
