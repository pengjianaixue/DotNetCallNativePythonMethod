#pragma once

#include <QObject>
#include <QStandardItemModel>
#include <memory>
#include <map>
class TreeModelWapper : public QObject
{
	Q_OBJECT
	using NODEPAIR = std::pair<int, QStandardItemModel*>;
public:
	explicit TreeModelWapper(QObject *parent =nullptr);      
	~TreeModelWapper();
public slots:
	bool appendTreeNodeChildItem(QStandardItem *parentNode, QStandardItem *childItem);
	bool insertTreeNodeChildItem(QStandardItem *parentNode, QStandardItem *childItem, int row);
	bool appendTreeNode(QStandardItem *node);
	bool currentNodeAppendChildItem(QStandardItem *childItem);
	void setHorizontalHeaderLabels(const QStringList &labels);
	QStandardItemModel*  getModel();
	inline void clearTree() { m_standardItemModel->clear(); };
	
private:
	std::unique_ptr<QStandardItemModel>		m_standardItemModel{nullptr};
	QList<int>							    m_nodeChildCounter{ 0 };
	std::map<QStandardItem*,int>			m_nodePostionRecordMap{};
	QStandardItem							*m_currentNode{ nullptr };
};
