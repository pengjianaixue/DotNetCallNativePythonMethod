#include "stdafx.h"
#include "MainWindows.h"

MainWindows::MainWindows(QWidget *parent)
	: QMainWindow(parent), m_pyeditorprocess(new QProcess(this)),
	  PythonHomeSet(new CaseandEditorhome(this)), m_RunPythonCaseprocess(nullptr)
{

	ui.setupUi(this);
	m_TheCurrentPath = QDir::currentPath();
	//TODO this absolutely path is only for  local test 
	m_strInitXmlFilePath = m_TheCurrentPath + R"(\Initloadfile\InitParam.xml)"; 
	m_hPycharmProcessid = 0;
	Init();
	ConnectSlots();
	LoadInitXmlConfigure();
	if (!m_strPyCaseFileHomePath.isEmpty())
	{
		m_TheCurrentPath = m_strPyCaseFileHomePath;
	}
}
bool MainWindows::openconfigform(int i)
{
	m_UICaseConfigure.show();
	return true;
}
MainWindows::~MainWindows()
{
	delete m_pyeditorprocess;
	if (m_RunPythonCaseprocess.IsRuning())
	{
		emit Signal_emitPyCaseStop();
	}
	m_CaseRunThread.wait(100);
	m_CaseRunThread.terminate();
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

bool MainWindows::Init()
{


	this->tabifyDockWidget(this->ui.dockWidget_Terminal, this->ui.dockWidget_Opeartioninfodisp);
	this->tabifyDockWidget(this->ui.dockWidget_Opeartioninfodisp,this->ui.dockWidget_ErrorInfo);
	this->ui.dockWidget_Terminal->raise();
	this->ui.PTE_TerimnalDisplayArea->setReadOnly(true);
	m_CaseRunThread.start();
	return true;
}

void MainWindows::closeEvent(QCloseEvent * event)
{
	QMessageBox::StandardButton rb = QMessageBox::information(this,"exit info","Are you sure to close RAT ?",QMessageBox::StandardButton::Cancel, QMessageBox::StandardButton::Apply);
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
		QMessageBox::warning(this, "Warning", "the  python editor  pycharm have opened!");
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
	if (!m_strPyCaseFileHomePath.isEmpty())
	{
		m_TheCurrentPath = m_strPyCaseFileHomePath;
		emit Signal_emitpycasefilehomepath(m_strPyCaseFileHomePath);
	}
	return true;
}

bool MainWindows::RecviPycharmhomepath(const QString & Pycharmhomepath)
{

	m_strPycharmBinPath = Pycharmhomepath;
	return true;
}

bool MainWindows::RunPyFileInTerminal()
{
	if (m_RunPythonCaseprocess.IsRuning())
	{
		
		emit Signal_emitPyCaseStop();
	}
	else
	{
		m_RunPythonCaseprocess.RegisterRunList(m_CaseExecListToFullPathList);
		m_RunPythonCaseprocess.moveToThread(&m_CaseRunThread);
		emit Signal_emitPyCaseRun();

	}
	return true;
}
//// Backup
void MainWindows::DisplayToTerminal(const QString &PyProcessRunInfor)
{
//	QByteArray messagebyte = this->m_RunPythonCaseprocess.m_Process.readAllStandardOutput();
//	QString messagestring = QString::fromLocal8Bit(messagebyte);
//#ifdef _DEBUG
//	std::string smsg = messagestring.toStdString();
//#endif // _DEBUG
	this->ui.PTE_TerimnalDisplayArea->appendPlainText(PyProcessRunInfor);
	this->ui.PTE_TerimnalDisplayArea->update();
	return;
}
//void MainWindows::DisplayToTerminal()
//{
//	QByteArray messagebyte = this->m_RunPythonCaseprocess.m_Process.readAllStandardOutput();
//	QString messagestring = QString::fromLocal8Bit(messagebyte);
//#ifdef _DEBUG
//	std::string smsg = messagestring.toStdString();
//#endif // _DEBUG
//	this->ui.PTE_TerimnalDisplayArea->appendPlainText(messagestring);
//	this->ui.PTE_TerimnalDisplayArea->update();
//	return;
//}


void MainWindows::GetExecuteCaseList()
{
	m_CaseExecListToFullPathList =  this->m_UICaseConfigure.GetCaseExecuteList();
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
				&& connect(this, &MainWindows::Signal_emitpycasefilehomepath, &this->m_UICaseConfigure, &CaseScriptConfigure::SetPyFilePath)
				&& connect(this->ui.Auto_Test, &QAction::triggered, this, &MainWindows::RunPyFileInTerminal)
				&& connect(&this->m_RunPythonCaseprocess, &CPyProcess::s_ProcessOutPutinfo, this, &MainWindows::DisplayToTerminal)
				&& connect(&this->m_UICaseConfigure, &CaseScriptConfigure::s_emitExceListChanged,this, &MainWindows::GetExecuteCaseList)
				&& connect(this->ui.pushButton_clearTerminal, &QPushButton::clicked, this->ui.PTE_TerimnalDisplayArea, &QPlainTextEdit::clear)
				&& connect(this, &MainWindows::Signal_emitPyCaseRun, &this->m_RunPythonCaseprocess, &CPyProcess::Start)
				&& connect(this, &MainWindows::Signal_emitPyCaseStop, &this->m_RunPythonCaseprocess, &CPyProcess::Stop)
				
			)
		)
	{

		throw(" connect signal and  slots faile in MainWindows ");

	}
	return true;
}
