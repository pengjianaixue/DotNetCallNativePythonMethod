#pragma once
#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
 
typedef QPair<QString, QStringList> QSTRINGLISTPAIR;
typedef QList<QSTRINGLISTPAIR>      QCASEFILETREELIST;
class TreeItem;
class TreeModel : public QAbstractItemModel
{

	Q_OBJECT
	
public:
	explicit TreeModel(QObject *parent = 0);
	~TreeModel();
	QVariant data(const QModelIndex &index, int role) const override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;
	QVariant headerData(int section, Qt::Orientation orientation,
		int role = Qt::DisplayRole) const override;
	QModelIndex index(int row, int column,
		const QModelIndex &parent = QModelIndex()) const override;
	QModelIndex parent(const QModelIndex &index) const override;
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	// Self need function
	bool setModelData(const QCASEFILETREELIST &data, const QString &RootData);
	bool ClearData();


private:
	void setupModelData(const QCASEFILETREELIST &CaseTree, TreeItem *parent);
	//void setupModelData(const QStringList &lines, TreeItem *parent);

	TreeItem *rootItem;
};

#endif // TREEMODEL_H