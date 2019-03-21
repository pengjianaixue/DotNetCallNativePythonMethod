#pragma once

#include <QDialog>
#include "ui_RunScript.h"
#include "../CallPython/CallPython.h"

class RunScript : public QDialog
{
	Q_OBJECT

public:
	RunScript(QWidget *parent = Q_NULLPTR);
	~RunScript();

private:
	Ui::RunScript ui;
public slots:
	int TestRun();
	int Reset();
private:
	std::string m_strRunres;
	CCallPython m_cpycaller;
	PARAMLIST   m_callpyparmlist;
};
