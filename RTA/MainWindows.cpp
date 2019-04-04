#include "stdafx.h"
#include "MainWindows.h"
MainWindows::MainWindows(QWidget *parent)
	: QMainWindow(parent), m_pyeditorprocess(new QProcess(this)),
	  PythonHomeSet(new CaseandEditorhome(this)),m_RunPythonCaseprocess(new QProcess()),
	  m_QthreadPythonCaseprocess(nullptr)
{
	ui.setupUi(this);
	m_TheCurrentPath = QDir::currentPath();
	//TODO 
	//this absolutely path is only for  local test 
	m_strInitXmlFilePath = m_TheCurrentPath + R"(\Initloadfile\InitParam.xml)"; 
	m_hPycharmProcessid = 0;
	InitOption();
	ConnectSlots();
	LoadInitXmlConfigure();
	

	
}
bool MainWindows::openconfigform(int i)
{
	m_uirunscript.show();
	return true;
}
MainWindows::~MainWindows()
{
	m_RunPythonCaseprocess->terminate();
	delete m_RunPythonCaseprocess;
	delete m_pyeditorprocess;
}
bool MainWindows::LoadInitXmlConfigure()
{
	CXmlConfigureFileOperation Reader(this, m_strInitXmlFilePath, CXmlConfigureFileOperation::OPERATIONTYPE::READ);
	QString Pycharmpath;
	QString PycasePath;
	if (Reader.ReadInitXml("Pycharmpath", Pycharmpath)&&!Pycharmpath.isEmpty())
	{
		TRACE(Pycharmpath);
		m_strPycharmBinPath = Pycharmpath;
	}
	if (Reader.ReadInitXml("PyCasePath", PycasePath)&&!PycasePath.isEmpty())
	{
		TRACE(PycasePath);
		m_strPyCaseFileHomePath = PycasePath;
		emit Signal_emitpycasefilehomepath(m_strPyCaseFileHomePath);
	}
	PythonHomeSet->SetPypathExtra(m_strPyCaseFileHomePath, m_strPycharmBinPath);
	return true;
}

bool MainWindows::InitOption()
{
	m_RunPythonCaseprocess->setProcessChannelMode(QProcess::MergedChannels);
	this->ui.PTE_TerimnalDisplayArea->setReadOnly(true);
	return true;
}

void MainWindows::closeEvent(QCloseEvent * event)
{
	QMessageBox::StandardButton rb = QMessageBox::information(this,"exit info","Are you sure to close RTA ?",QMessageBox::StandardButton::Cancel, QMessageBox::StandardButton::Apply);
	if (rb == QMessageBox::StandardButton::Cancel)
	{
		event->ignore();
	}
	else
	{
		CXmlConfigureFileOperation Wirter(this, m_strInitXmlFilePath, CXmlConfigureFileOperation::OPERATIONTYPE::WRITE);
		Wirter.WirteInitXml("Pycharmpath", m_strPycharmBinPath);
		Wirter.WirteInitXml("PyCasePath", m_strPyCaseFileHomePath);
		Wirter.ForamtEndEleAndSave();
	}

}

bool MainWindows::openpycharmIDE()
{

	
	if (m_strPyCaseFileHomePath.isEmpty()|| m_strPycharmBinPath.isEmpty())
	{
		QMessageBox::critical(this, "File path error ", "Please Set Python case home ");
		return false;
	}
	if (m_pyeditorprocess->pid()!=nullptr && m_hPycharmProcessid == m_pyeditorprocess->pid()->dwProcessId)
	{
		QMessageBox::warning(this, "Warning", "the  python editor  pycharm have existing!");
	}
	QString pypath =   m_strPyCaseFileHomePath;
	QString program = m_strPycharmBinPath + R"(/pycharm64.exe)"; //R"(D:/SoftwareInstall/JetBrains/PyCharm 2018.1.1/bin/pycharm64.exe)";
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

	m_strPyCaseFileHomePath = pycasefilehomepath;

	return true;
}

bool MainWindows::RecviPycharmhomepath(const QString & Pycharmhomepath)
{

	m_strPycharmBinPath = Pycharmhomepath;
	return true;
}

bool MainWindows::RunPyFileInTerminal()
{
	this->ui.PTE_TerimnalDisplayArea->clear();
	QString PyPath = m_TheCurrentPath + R"(\CaseProject\main.py)";
	QString cmd = "python " + PyPath;
	m_RunPythonCaseprocess->start(R"(python )" + PyPath);
	m_RunPythonCaseprocess->waitForFinished();
	return true;
}

void MainWindows::DisplayToTerminal()
{
	QByteArray qbt = m_RunPythonCaseprocess->readAllStandardOutput();
	QString msg = QString::fromLocal8Bit(qbt);
#ifdef _DEBUG
	std::string smsg = msg.toStdString();
#endif // _DEBUG
	this->ui.PTE_TerimnalDisplayArea->appendPlainText(msg);
	this->ui.PTE_TerimnalDisplayArea->update();
	return;
}

bool MainWindows::ConnectSlots()
{

	if (
			!(
				connect(this->ui.ScriptConfigure, &QAction::triggered, this, &MainWindows::openconfigform) 
				&& connect(this->ui.action_SetPythonFileHome, &QAction::triggered, this, &MainWindows::SetPycaseFilehome) 
				&& connect(this->ui.action_Script_Editor_Pycharm, &QAction::triggered, this, &MainWindows::openpycharmIDE) 
				&& connect(this->PythonHomeSet, &CaseandEditorhome::Signal_eimtPythonFileHome, this, &MainWindows::Recvipycasefilehomepath) 
				&& connect(this->PythonHomeSet, &CaseandEditorhome::Signal_eimtPycharmHome, this, &MainWindows::RecviPycharmhomepath) 
				&& connect(this, &MainWindows::Signal_emitpycasefilehomepath, &this->m_uirunscript, &CaseScriptConfigure::SetPyFilePath)
				&& connect(this->ui.ScirptRun, &QAction::triggered, this, &MainWindows::RunPyFileInTerminal) 
				&& connect(this->m_RunPythonCaseprocess, &QProcess::readyReadStandardOutput,this,&MainWindows::DisplayToTerminal)
			)
		)
	{

		throw(" connect signal and  slots faile in MainWindows ");

	}
	return true;
}
