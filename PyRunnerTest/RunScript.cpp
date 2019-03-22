#include "stdafx.h"
#include "RunScript.h"

CaseScriptConfigure::CaseScriptConfigure(QWidget *parent)
	: QDialog(parent)
{
	
	ui.setupUi(this);
	m_cpycaller.SetPyPath(R"(./Python/)");
	if (!
		(connect(this->ui.pushButton_run, &QPushButton::clicked, this, &CaseScriptConfigure::TestRun) &&
		connect(this->ui.pushButton_reset, &QPushButton::clicked, this, &CaseScriptConfigure::Reset))
	   )
	{
		qDebug() << "connect is fail" << endl;
	}
	else
	{
		qDebug() << "connect is Success" << endl;
	}

}

int CaseScriptConfigure::TestRun()
{

	QIcon iconPause;
	iconPause.addFile(":/RTA/PyRunner/Resources/pause.png");
	ui.pushButton_run->setIcon(iconPause);
	ui.pushButton_run->update();
	PARAMPAIR param, param1;
	param.first = "i";
	param.second = "117";
	param1.first = "s";
	param1.second = "18800000";
	m_callpyparmlist.push_back(param);
	m_callpyparmlist.push_back(param1);
	m_strRunres = m_cpycaller.Runfunction(std::string("main"), std::string("main"), m_callpyparmlist);
	ui.TB_RunInfodisp->append(QString(m_strRunres.c_str()));
	QIcon iconstart;
	iconstart.addFile(":/RTA/PyRunner/Resources/start.png");
	ui.pushButton_run->setIcon(iconstart);
	ui.pushButton_run->update();
	m_callpyparmlist.clear();
	return 0;
}
int CaseScriptConfigure::Reset()
{	

	ui.TB_RunInfodisp->clear();
	return 0;
}

CaseScriptConfigure::~CaseScriptConfigure()
{
	FinalizePyIter();
}
