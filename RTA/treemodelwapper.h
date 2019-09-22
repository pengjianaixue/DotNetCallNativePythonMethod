#pragma once

#include <QObject>
#include <QStandardItemModel>
#include <memory>
#include <map>
class treemodelwapper : public QObject
{
	Q_OBJECT
	using NODEPAIR = std::pair<int, QStandardItemModel*>;
public:
	treemodelwapper(QObject *parent);
	~treemodelwapper();
public slots:
	bool appendTreeNodeChildItem(QStandardItem *parentNode, QStandardItem *childItem);
	bool insertTreeNodeChildItem(QStandardItem *parentNode, QStandardItem *childItem, int arow);
	bool addTreeNode(QStandardItem *Node);
	bool setHorizontalHeaderLabels(const QStringList &labels);
	QStandardItemModel*  getModel();
	
private:
	std::shared_ptr<QStandardItemModel>		m_standardItemModel = {nullptr};
	QList<int>							    m_nodeChildCounter  = { 0 };
	std::map<QStandardItem*,int>			m_nodePostionRecordMap = {};
};
