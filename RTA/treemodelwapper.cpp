#include "stdafx.h"
#include "TreeModelWapper.h"

TreeModelWapper::TreeModelWapper(QObject *parent)
	: QObject(parent), 
	m_standardItemModel(new QStandardItemModel(this))
{

}

TreeModelWapper::~TreeModelWapper()
{

}

bool TreeModelWapper::insertTreeNodeChildItem(QStandardItem *parentNode, QStandardItem *childItem, int row)
{
	if (!parentNode && !childItem)
	{
		return false;
	}
	m_currentNode = parentNode;
	parentNode->insertRow(row,childItem);
	if (m_nodePostionRecordMap.find(parentNode) == m_nodePostionRecordMap.end())
	{
		m_standardItemModel->appendRow(parentNode);
		m_nodePostionRecordMap.insert({ parentNode ,m_standardItemModel->rowCount() });
	}
	return false;
}

bool TreeModelWapper::appendTreeNode(QStandardItem *node)
{
	if (node)
	{
		m_currentNode = node;
		m_standardItemModel->appendRow(node);
		m_nodePostionRecordMap.insert({ node ,m_standardItemModel->rowCount() });
		return true;
	}
	return false;
}

bool TreeModelWapper::currentNodeAppendChildItem(QStandardItem* childItem)
{
	if (childItem)
	{
		m_currentNode->appendRow(childItem);
		return true;
	}
	return false;
}

void TreeModelWapper::setHorizontalHeaderLabels(const QStringList &labels)
{
	m_standardItemModel->setHorizontalHeaderLabels(labels);
}
bool TreeModelWapper::appendTreeNodeChildItem(QStandardItem *parentNode, QStandardItem *childItem)
{
	if (!parentNode && !childItem)
	{
		return false;
	}
	m_currentNode = parentNode;
	parentNode->appendRow(childItem);
	if (m_nodePostionRecordMap.find(parentNode) == m_nodePostionRecordMap.end())
	{
		m_standardItemModel->appendRow(parentNode);
		m_nodePostionRecordMap.insert({ parentNode ,m_standardItemModel->rowCount() });
	}
	//m_standardItemModel->findItems();

}
QStandardItemModel* TreeModelWapper::getModel()
{
	return m_standardItemModel.get();
}
