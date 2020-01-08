#include "stdafx.h"
#include "CaseScriptConfigure.h"

CaseScriptConfigure::CaseScriptConfigure(QWidget *parent)
	: QDialog(parent), m_CaseTreeModel( std::make_shared<QStandardItemModel>())
{
	
	ui.setupUi(this);
	formInit();
	m_strpythonfilehome = QApplication::applicationFilePath() + QString(R"(\CaseProject\)");
	ConnectSlots();

}

int CaseScriptConfigure::TestRun()
{
	return 0;
}
int CaseScriptConfigure::Reset()
{	
	return 0;
}

bool CaseScriptConfigure::SetPyFilePath(const QString &path)
{

	m_strpythonfilehome = path;
	return true;
}

bool CaseScriptConfigure::ReLoadPyFilePath()
{
	return true;
}
bool CaseScriptConfigure::LoadCaseFileListInfo(const QString &filepath)
{

	QString str_FilePathRecord;
	bool   b_Dirpollflag;
	QStandardItem *rowitem = new QStandardItem;
	//rowitem->setIcon(QIcon(":/RTA/PyRunner/Resources/tree-node-right.png"));
	rowitem->setText(filepath.split(R"(/)").last());
	QDir CaseHomePath(filepath);
	QFileInfo CaseFileInfo;
	int rowcounter = 0;
	Q_FOREACH(QFileInfo CaseFileInfo, CaseHomePath.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot))
	{

		b_Dirpollflag = false;
		//TRACE(CaseFileInfo.path());
		//TRACE(CaseFileInfo.fileName());
		if (CaseFileInfo.isDir())
		{
			if (CaseFileInfo.fileName().toLower().endsWith("lib"))
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

			QStandardItem *pyFileItem = new QStandardItem;
			pyFileItem->setIcon(QIcon(":/RTA/PyRunner/Resources/testCase.png"));
			pyFileItem->setText(CaseFileInfo.fileName().split(".").first());
			rowitem->setChild(rowcounter, pyFileItem);
			rowcounter++;
			m_CaseNameMaptoFullyPath.insert(CaseFileInfo.fileName().split(".").first(), CaseFileInfo.path() + R"(/)" + CaseFileInfo.fileName());

		}
	}
	m_pycasetreeinfostruct.append(rowitem);
	return true;
}

bool CaseScriptConfigure::GetPyCasePathAndLaodCaseFile()
{


	m_CaseTreeModel->clear();
	QStringList headerlable;
	headerlable <<"Case Tree";
	this->m_CaseTreeModel->setHorizontalHeaderLabels(headerlable);
	m_pycasetreeinfostruct.clear();
	LoadCaseFileListInfo(m_strpythonfilehome);
	for (auto &item: m_pycasetreeinfostruct)
	{
		this->m_CaseTreeModel->appendRow(item);
	}
	return true;
}
void CaseScriptConfigure::GetCaseListViewUserSelectItem(const QModelIndex & caseitem)
{

	QModelIndex index = ui.CaseFile_treeView->currentIndex();
	if (caseitem.isValid())
	{
		/*TreeItem *parentItem;*/
		QStandardItem *Selectitem = nullptr;
		Selectitem = static_cast<QStandardItem*>(caseitem.internalPointer());
		Selectitem = Selectitem->child(caseitem.row());
		if (Selectitem)
		{
			if (!Selectitem->hasChildren())
			{
				QVariant Caseitem = caseitem.data();
				emit s_emitSelectCaseItemToExecList(Caseitem.toString());
				TRACE(Caseitem);
			}
			else
			{
				for (size_t i = 0; i < Selectitem->rowCount(); i++)
				{
					QVariant Caseitem = Selectitem->child(i)->data(0);
					emit s_emitSelectCaseItemToExecList(Caseitem.toString());

				}

			}
		}
		/*QMessageBox::information(this, "Case SelectName", Caseitem.toString());*/

	}
	return;
}

void CaseScriptConfigure::AddSelectCaseToExceList(const QString &SelectCaseItem)
{
	Q_FOREACH(QString item, this->m_CaseExecList)
	{
		if (item == SelectCaseItem)
		{
			return;
		}
	}
	this->m_CaseExecList.append(SelectCaseItem);
	//Add the full path to the execute list
	QPair<QString, QString> piaritem;
	piaritem.first = SelectCaseItem;
	QMap<QString, QString>::iterator it = this->m_CaseNameMaptoFullyPath.find(SelectCaseItem);
	if (it != this->m_CaseNameMaptoFullyPath.end())
	{
		piaritem.second = it.value();
	}
	this->m_CaseExecListToFullPathList.append(piaritem);
	emit s_emitCaseExecListChanged();

	//this->m_CaseExecListModel->setStringList(m_CaseExecList);
	

}

CaseScriptConfigure::~CaseScriptConfigure()
{

}
const QList<QPair<QString, QString>>& CaseScriptConfigure::GetCaseExecuteList() const
{
	return this->m_CaseExecListToFullPathList;
}
void CaseScriptConfigure::formInit()
{

	//Set the Stretch rate
	this->ui.frame_caseFile_tree->setStyleSheet("background-color: rgb(0, 170, 255);");
	this->ui.frame_case_select_list->setStyleSheet("background-color: rgb(0, 170, 255);");
	this->ui.frame_execute_group_list->setStyleSheet("background-color: rgb(0, 170, 255);");
	this->ui.splitter_loadandinfor->setStretchFactor(0, 7);
	this->ui.splitter_loadandinfor->setStretchFactor(1, 3);
	this->ui.CaseFile_treeView->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
	this->ui.CaseFile_treeView->setDragEnabled(true);
	this->ui.CaseFile_treeView->setContextMenuPolicy(Qt::CustomContextMenu);
	this->ui.CaseFile_treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
	this->ui.Case_exce_treeView->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
	this->ui.CaseFile_treeView->setModel(m_CaseTreeModel.get());
	this->ui.Case_exce_treeView->setModel(this->m_CaseExecListModel.get());
	m_ignorePyDirNameList.append(".idea");
	m_ignorePyDirNameList.append("__pycache__");
	m_ignorePyDirNameList.append("venv");
	m_ignorePyDirNameList.append(".vscode");

}
//TODO: need to confrim the param
bool CaseScriptConfigure::PyRun()
{

	//Call Python function 
	return true;
}

void CaseScriptConfigure::ConnectSlots()
{
	if (!
			(
				connect(this->ui.pushButton_LoadCaseList,&QPushButton::clicked,this,&CaseScriptConfigure::GetPyCasePathAndLaodCaseFile)
				&& connect(this->ui.CaseFile_treeView,&QTreeView::doubleClicked,this,&CaseScriptConfigure::GetCaseListViewUserSelectItem)
				&& connect(this, &CaseScriptConfigure::s_emitSelectCaseItemToExecList, this, &CaseScriptConfigure::AddSelectCaseToExceList)
				&& connect(this->ui.pushButton_ok, &QPushButton::clicked, this, &CaseScriptConfigure::close)
			)
		)
	{
		throw " Slots Connect Error";
	}
}

