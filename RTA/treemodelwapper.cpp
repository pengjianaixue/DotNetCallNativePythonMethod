#include "stdafx.h"
#include "treemodelwapper.h"

treemodelwapper::treemodelwapper(QObject *parent)
	: QObject(parent), 
	m_standardItemModel(std::make_shared<QStandardItemModel>(parent))
{

}

treemodelwapper::~treemodelwapper()
{

}

bool treemodelwapper::insertTreeNodeChildItem(QStandardItem *parentNode, QStandardItem *childItem, int arow)
{
	if (!parentNode && !childItem)
	{
		return false;
	}
	parentNode->insertRow(arow,childItem);
	if (m_nodePostionRecordMap.find(parentNode) == m_nodePostionRecordMap.end())
	{
		m_standardItemModel->appendRow(parentNode);
		m_nodePostionRecordMap.insert({ parentNode ,m_standardItemModel->rowCount() });
	}
	return false;
}

bool treemodelwapper::addTreeNode(QStandardItem *Node)
{
	return false;
}

bool treemodelwapper::setHorizontalHeaderLabels(const QStringList &labels)
{
	return false;
}
bool treemodelwapper::appendTreeNodeChildItem(QStandardItem *parentNode, QStandardItem *childItem)
{
	if (!parentNode && !childItem)
	{
		return false;
	}
	parentNode->appendRow(childItem);
	if (m_nodePostionRecordMap.find(parentNode) == m_nodePostionRecordMap.end())
	{
		m_standardItemModel->appendRow(parentNode);
		m_nodePostionRecordMap.insert({ parentNode ,m_standardItemModel->rowCount() });
	}
	//m_standardItemModel->findItems();

}
QStandardItemModel* treemodelwapper::getModel()
{
	return m_standardItemModel.get();
}
