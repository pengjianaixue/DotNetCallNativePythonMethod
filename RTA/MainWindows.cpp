#include "stdafx.h"
#include "MainWindows.h"

MainWindows::MainWindows(QWidget *parent)
	: QMainWindow(parent), m_pyeditorprocess(new QProcess(this)),
	  PythonHomeSet(new CaseandEditorhome(this))
{
	ui.setupUi(this);
	ConnectSlots();

	
}
bool MainWindows::openconfigform(int i)
{
	m_uirunscript.show();
	return true;
}
MainWindows::~MainWindows()
{
	delete m_pyeditorprocess;
}

bool MainWindows::openpycharmIDE()
{

	QDir pycasedir;
	if (m_strpycasefilehomepath.isEmpty())
	{
		QMessageBox::critical(this, "File path error ", "Please Set Python case home ");
		return false;
	}
	if (m_pyeditorprocess->isOpen())
	{
		QMessageBox::warning(this, "Warning", "the  python editor  pycharm have existing!");
	}
	QString pypath =   m_strpycasefilehomepath;
	QString program = R"(D:/SoftwareInstall/JetBrains/PyCharm 2018.1.1/bin/pycharm64.exe)";
	QStringList arguments;
	arguments << pypath;
	qDebug() << program << "\n" << arguments;
	m_pyeditorprocess->start(program, arguments);
	m_pyeditorprocess->waitForStarted();
	this->ui.action_Script_Editor_Pycharm->setChecked(true);
	return true;
}

bool MainWindows::SetPycaseFilehome()
{

	PythonHomeSet->show();
	//QFileDialog pycasefile(nullptr);
	//pycasefile.setWindowTitle(tr("Set Python  case home "));//
	//pycasefile.setAcceptMode(QFileDialog::AcceptMode::AcceptOpen);//
	//pycasefile.setFileMode(QFileDialog::FileMode::Directory);//
	//pycasefile.setViewMode(QFileDialog::Detail);//
	//if (pycasefile.exec() == QFileDialog::Accepted)
	//{
	//	m_strpycasefilehomepath = pycasefile.selectedFiles()[0];
	//}
	//return true;
	return true;
}

bool MainWindows::ConnectSlots()
{

	if (!
		(
			connect(this->ui.ScriptConfigure, &QAction::triggered, this, &MainWindows::openconfigform)&&
			connect(this->ui.action_SetPythonFileHome,&QAction::triggered,this,&MainWindows::SetPycaseFilehome)&&
			connect(this->ui.action_Script_Editor_Pycharm, &QAction::triggered, this, &MainWindows::openpycharmIDE)
		)
		)
	{

		throw(" connect signal and  slots faile in MainWindows ");

	}
	return true;
}
