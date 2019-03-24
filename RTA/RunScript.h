#pragma once

#include <QDialog>
#include <QtXml\qxml.h>
#include <qxmlstream.h>
#include "ui_RunScript.h"
#include "../CallPython/CallPython.h"

class CaseScriptConfigure : public QDialog
{

	Q_OBJECT
public:
	CaseScriptConfigure(QWidget *parent = Q_NULLPTR);
	~CaseScriptConfigure();
private:
	Ui::RunScript ui;
public slots:
	int TestRun();
	int Reset();
	bool ReSetPyFilePath(const QString &path);
	bool ReLoadPyFilePath();
private:
	std::string m_strRunres;
	CCallPython m_cpycaller;
	PARAMLIST   m_callpyparmlist;
	QString     m_strpythonfilehome;
};
