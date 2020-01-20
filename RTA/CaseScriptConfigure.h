#pragma once

#include <QDialog>
#include <QtXml\qxml.h>
#include <qxmlstream.h>
#include <QPair>
#include <memory>
#include "Trace.h"
#include "treemodel.h"
#include "treeitem.h"
#include "ui_CaseScriptConfigure.h"
#include "../PyCaller/pyCaller.h"
#include "treemodelwapper.h"

class CaseScriptConfigure : public QDialog
{

	Q_OBJECT
public:
	CaseScriptConfigure(QWidget *parent = Q_NULLPTR);
	~CaseScriptConfigure();
	const QList<QPair<QString, QString>> &GetCaseExecuteList() const;
	typedef QPair<QString, QList<QStandardItem*>> QITEMPAIR;
private:
	bool PyRun();
	void ConnectSlots();
	void formInit();

signals:
	void s_emitCaseExecListChanged();
	void s_emitSelectCaseItemToExecList(const QString &SelectCaseItem);
	

public slots:
	int  TestRun();
	int  Reset();
	bool SetPyFilePath(const QString &path);
	bool ReLoadPyFilePath();
	bool GetPyCasePathAndLaodCaseFile();
	void GetCaseListViewUserSelectItem(const QModelIndex &caseitem);
	bool LoadCaseFileListInfo(const QString  &filepath);
	void AddSelectCaseToExceList(const QString &SelectCaseItem);


private:
	Ui::CaseScriptConfigure ui;
	std::string								m_strRunres;
	QString									m_strpythonfilehome;
	QITEMPAIR								m_pycasefileanddirinfo;
	QStringList								m_pycasefilenamelist;
	QList<QStandardItem*>					m_pycasetreeinfostruct;
	//QList<QSTRINGLISTPAIR>					m_pycasetreeinfostruct;
	QList<QString>							m_ignorePyDirNameList;
	std::unique_ptr<QStandardItemModel>		m_CaseTreeModel;
	QMap<QString, QString>					m_CaseNameMaptoFullyPath; // the search map
	std::unique_ptr<QStandardItemModel>		m_CaseExecListModel;
	QStringList								m_CaseExecList;
	QList<QPair<QString, QString>>			m_CaseExecListToFullPathList;
	TreeModelWapper							m_caseTreeModelWapper;
	
};
