#include "stdafx.h"
#include "MainWindows.h"
MainWindows::MainWindows(QWidget *parent)
	: QMainWindow(parent), m_pyeditorprocess(new QProcess(this)),
	  PythonHomeSet(new CaseandEditorhome(this))
{
	m_hPycharmProcessid = 0;
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

	
	if (m_strpycasefilehomepath.isEmpty()|| m_strpycharmbinpath.isEmpty())
	{
		QMessageBox::critical(this, "File path error ", "Please Set Python case home ");
		return false;
	}
	if (m_pyeditorprocess->pid()!=nullptr && m_hPycharmProcessid == m_pyeditorprocess->pid()->dwProcessId)
	{
		QMessageBox::warning(this, "Warning", "the  python editor  pycharm have existing!");
	}
	QString pypath =   m_strpycasefilehomepath;
	QString program = m_strpycharmbinpath + R"(/pycharm64.exe)"; //R"(D:/SoftwareInstall/JetBrains/PyCharm 2018.1.1/bin/pycharm64.exe)";
	QFileInfo  pycasedir(program);
	if (!pycasedir.isExecutable())
	{
		QMessageBox::critical(this, "File path error", "the pycharm path have no pycharm64.exe file!");
	}
	QStringList arguments;
	arguments << pypath;
	qDebug() << program << "\n" << arguments;
	m_pyeditorprocess->start(program, arguments);
	m_pyeditorprocess->waitForStarted();
	m_hPycharmProcessid = m_pyeditorprocess->pid()->dwProcessId;
	this->ui.action_Script_Editor_Pycharm->setChecked(true);
	return true;
}

bool MainWindows::SetPycaseFilehome()
{

	PythonHomeSet->show();
	return true;
}

bool MainWindows::Recvipycasefilehomepath(const QString & pycasefilehomepath)
{

	m_strpycasefilehomepath = pycasefilehomepath;

	return true;
}

bool MainWindows::RecviPycharmhomepath(const QString & Pycharmhomepath)
{

	m_strpycharmbinpath = Pycharmhomepath;
	return true;
}

bool MainWindows::ConnectSlots()
{

	if (!
		(
			connect(this->ui.ScriptConfigure, &QAction::triggered, this, &MainWindows::openconfigform) &&
			connect(this->ui.action_SetPythonFileHome, &QAction::triggered, this, &MainWindows::SetPycaseFilehome) &&
			connect(this->ui.action_Script_Editor_Pycharm, &QAction::triggered, this, &MainWindows::openpycharmIDE) &&
			connect(this->PythonHomeSet, &CaseandEditorhome::Signal_eimtPythonFileHome, this, &MainWindows::Recvipycasefilehomepath) &&
			connect(this->PythonHomeSet, &CaseandEditorhome::Signal_eimtPycharmHome, this, &MainWindows::RecviPycharmhomepath) &&
			connect(this, &MainWindows::Signal_emitpycasefilehomepath, &this->m_uirunscript, &CaseScriptConfigure::ReSetPyFilePath)
		)
		)
	{

		throw(" connect signal and  slots faile in MainWindows ");

	}
	return true;
}
