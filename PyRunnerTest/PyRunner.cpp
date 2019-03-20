#include "stdafx.h"
#include "PyRunner.h"

PyRunner::PyRunner(QWidget *parent)
	: QMainWindow(parent)
{

	ui.setupUi(this);
	if (	!(
			connect(this->ui.pushButton_run, &QPushButton::clicked, this, &PyRunner::TestRun)&& 
			connect(this->ui.pushButton_reset, &QPushButton::clicked, this, &PyRunner::Reset)
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

int PyRunner::TestRun()
{

	ui.pushButton_run->setStyleSheet(QStringLiteral("border-image: url(::/RTA/PyRunner/Resources/pause.png);"));
	ui.pushButton_run->update();
	m_cpycaller.SetPyPath(R"(./Python/)");
	PARAMLIST paramlist;
	PARAMPAIR param, param1;
	param.first = "i";
	param.second = "117";
	param1.first = "s";
	param1.second = "18800000";
	paramlist.push_back(param);
	paramlist.push_back(param1);
	m_strRunres = m_cpycaller.Runfunction(std::string("main"), std::string("main"), paramlist);
	ui.TB_RunInfodisp->append(QString(m_strRunres.c_str()));
	ui.pushButton_run->setStyleSheet(QStringLiteral("border-image: url(::/RTA/PyRunner/Resources/start.png);"));
	ui.pushButton_run->update();
	return 0;
}

PyRunner::~PyRunner()
{
	FinalizePyIter();
}

int PyRunner::Reset()
{
	ui.TB_RunInfodisp->clear();
	return 0;
}
