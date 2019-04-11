#include "stdafx.h"
#include "CaseScriptConfigure.h"

CaseScriptConfigure::CaseScriptConfigure(QWidget *parent)
	: QDialog(parent), m_CaseTreeModel( new TreeModel)
{
	
	ui.setupUi(this);
	ParamInit();
	m_strpythonfilehome = QDir::currentPath() + R"(\CaseProject\)";
	m_cpycaller.SetPyPath(m_strpythonfilehome.toStdString());
	ConnectSlots();

}

int CaseScriptConfigure::TestRun()
{

	ui.pushButton_run->setIcon(QIcon(":/RTA/PyRunner/Resources/pause.png"));
	ui.pushButton_run->update();
	PyRun();
	ui.pushButton_run->setIcon(QIcon(":/RTA/PyRunner/Resources/start.png"));
	ui.pushButton_run->update();
	m_callpyparmlist.clear();
	return 0;
}
int CaseScriptConfigure::Reset()
{	

	ui.TB_RunInfodisp->clear();
	return 0;
}

bool CaseScriptConfigure::SetPyFilePath(const QString &path)
{

	m_strpythonfilehome = path;
	return true;
}

bool CaseScriptConfigure::ReLoadPyFilePath()
{
	m_cpycaller.SetPyPath(m_strpythonfilehome.toStdString());
	return true;
}

bool CaseScriptConfigure::LoadCaseFileListInfo(const QString &filepath)
{

	//TODO need finish this function
	QString str_FilePathRecord;
	bool   b_Dirpollflag;
	QSTRINGLISTPAIR temppair;
	QDir CaseHomePath(filepath);
	QFileInfo CaseFileInfo;
	temppair.first = filepath.split(R"(/)").last();
	Q_FOREACH(QFileInfo CaseFileInfo, CaseHomePath.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot))
	{
		 
		b_Dirpollflag = false;
		TRACE(CaseFileInfo.path());
		TRACE(CaseFileInfo.fileName());
		if (CaseFileInfo.isDir())
		{
			if (CaseFileInfo.fileName().endsWith("lib"))
			{
				continue;
			}
			bool checkignorepath = false;
			Q_FOREACH(QString dirname, m_ignorePyDirNameList)
			{
				if (dirname == CaseFileInfo.fileName())
				{
					checkignorepath = true;
					break;
				}
			}
			if (checkignorepath)
			{
				continue;
			}
			LoadCaseFileListInfo(CaseFileInfo.path() + R"(/)" + CaseFileInfo.fileName());
		}
		else if (CaseFileInfo.isFile() && CaseFileInfo.fileName().endsWith(".py"))
		{

			temppair.second.append(CaseFileInfo.fileName().split(".").first());
		}
	}
	m_pycasetreeinfostruct.append(temppair);
	return true;
}

bool CaseScriptConfigure::GetPyCasePathAndLaodCaseFile()
{

	m_CaseTreeModel->ClearData();
	LoadCaseFileListInfo(m_strpythonfilehome);
	m_CaseTreeModel->setModelData(m_pycasetreeinfostruct, "PythonCaseList");
	this->ui.CaseFile_treeView->setModel(m_CaseTreeModel);
	return true;
}

void CaseScriptConfigure::GetCaseListViewUserSelectItem(const QModelIndex & caseitem)
{
	//QModelIndex index = ui.CaseFile_treeView->currentIndex();
	if (caseitem.isValid())
	{
		QVariant Caseitem = caseitem.data();
		TRACE(Caseitem);
	}
	return;
}

CaseScriptConfigure::~CaseScriptConfigure()
{
	if (m_CaseTreeModel!= nullptr)
	{
		delete m_CaseTreeModel;
	}
	FinalizePyIter();
}
void CaseScriptConfigure::ParamInit()
{
	//Set the Stretch rate
	ui.top_splitter->setStretchFactor(0, 4);
	ui.top_splitter->setStretchFactor(1, 6);
	/*QPalette LoadPushbutton;
	LoadPushbutton.setColor(QPalette::ColorRole::Highlight, QColor(31, 95, 95));*/
	//ui.pushButton_LoadCaseList->setStyleSheet("QPushbutton:focus{border: 3px solid red;}");
	this->ui.CaseFile_treeView->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
	this->ui.CaseFile_treeView->setDragEnabled(true);
	m_ignorePyDirNameList.append(".idea");
	m_ignorePyDirNameList.append("__pycache__");

}
//TODO need to confrim the param
bool CaseScriptConfigure::PyRun()
{

	//Call Python function 
	PYPARAMPAIR param, param1;
	param.first = "i";
	param.second = "117";
	param1.first = "i";
	param1.second = "18800000";
	m_callpyparmlist.push_back(param);
	m_callpyparmlist.push_back(param1);
	m_strRunres = m_cpycaller.Runfunction(std::string("main"), std::string("main"), m_callpyparmlist);
	ui.TB_RunInfodisp->append(QString(m_strRunres.c_str()));
	return true;
}

void CaseScriptConfigure::ConnectSlots()
{
	if (!
			(

				connect(this->ui.pushButton_run, &QPushButton::clicked, this, &CaseScriptConfigure::TestRun) 
				&& connect(this->ui.pushButton_reset, &QPushButton::clicked, this, &CaseScriptConfigure::Reset) 
				&& connect(this->ui.pushButton_reload, &QPushButton::clicked, this, &CaseScriptConfigure::ReLoadPyFilePath)
				&& connect(this->ui.pushButton_LoadCaseList,&QPushButton::clicked,this,&CaseScriptConfigure::GetPyCasePathAndLaodCaseFile)
				/*&& connect(this->ui.CaseFile_treeView,&QTreeView::doubleClicked,this,&CaseScriptConfigure::GetCaseListViewUserSelectItem)*/
			
			)
		)
	{
		throw " Slots Connect Error";
	}
}

