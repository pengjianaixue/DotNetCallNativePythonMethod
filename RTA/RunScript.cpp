#include "stdafx.h"
#include "RunScript.h"

CaseScriptConfigure::CaseScriptConfigure(QWidget *parent)
	: QDialog(parent)
{
	
	ui.setupUi(this);
	//Set the Stretch rate
	ui.top_splitter->setStretchFactor(0, 4);
	ui.top_splitter->setStretchFactor(1, 6);
	//TODO 
	// reamind to  recover the relative path
	//m_strpythonfilehome = R"(./CaseProject/)";
	m_strpythonfilehome = R"(C:\Users\pengjian\Documents\GitHub\RTA\x64\Debug\CaseProject\)";
	m_cpycaller.SetPyPath(m_strpythonfilehome.toStdString());
	/*m_cpycaller.SetPyPath(R"(./Python/)");*/
	if (!
		(
			connect(this->ui.pushButton_run, &QPushButton::clicked, this, &CaseScriptConfigure::TestRun) &&
			connect(this->ui.pushButton_reset, &QPushButton::clicked, this, &CaseScriptConfigure::Reset) &&
			connect(this->ui.pushButton_reload, &QPushButton::clicked, this, &CaseScriptConfigure::ReLoadPyFilePath)
		)
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
	//Call Python function 
	PARAMPAIR param, param1;
	param.first = "i";
	param.second = "117";
	param1.first = "i";
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

bool CaseScriptConfigure::ReSetPyFilePath(const QString &path)
{

	m_strpythonfilehome = path;
	return true;
}

bool CaseScriptConfigure::ReLoadPyFilePath()
{
	m_cpycaller.SetPyPath(m_strpythonfilehome.toStdString());
	return true;
}

CaseScriptConfigure::~CaseScriptConfigure()
{
	FinalizePyIter();
}
