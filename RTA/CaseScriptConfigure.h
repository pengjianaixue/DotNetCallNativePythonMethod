#pragma once

#include <QDialog>
#include <QtXml\qxml.h>
#include <qxmlstream.h>
#include "ui_CaseScriptConfigure.h"
#include "../CallPython/CallPython.h"

class CaseScriptConfigure : public QDialog
{

	Q_OBJECT
public:
	CaseScriptConfigure(QWidget *parent = Q_NULLPTR);
	~CaseScriptConfigure();
	void ParamInit();
	typedef QPair<QString, QStringList> QSTRINGLISTPAIR;
private:
	bool PyRun();
private:
	Ui::CaseScriptConfigure ui;
public slots:
	int TestRun();
	int Reset();
	bool ReSetPyFilePath(const QString &path);
	bool ReLoadPyFilePath();
	bool LoadCaseFileListInfo(const QString &filepath);
private:
	std::string							m_strRunres;
	CCallPython							m_cpycaller;
	PARAMLIST							m_callpyparmlist;
	QString								m_strpythonfilehome;
	QSTRINGLISTPAIR						m_pycasefileanddirinfo;
	QStringList							m_pycasefilenamelist;
	QList<QSTRINGLISTPAIR>				m_pycasetreeinfostruct;
	QList<QString>						m_ignorePyDirNameList;
};
