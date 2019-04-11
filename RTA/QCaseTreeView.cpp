#include "stdafx.h"
#include "QCaseTreeView.h"

QCaseTreeView::QCaseTreeView(QWidget *parent)
	: QTreeView(parent), m_RightClickSelectMenu( nullptr)
{


	/*pop_menu = new QMenu();*/
	QAction *add_to_exclist = new QAction(this);
	QAction *igrone_this_item = new QAction(this);
	QAction *open_this_item_in_edtior = new QAction(this);
	m_MenuActionList.append(add_to_exclist);
	m_MenuActionList.append(igrone_this_item);
	m_MenuActionList.append(open_this_item_in_edtior);
	/*connect(add_to_exclist, &QAction::triggered, this, &ImageTree::selectImages);
	connect(igrone_this_item, &QAction::triggered, this, &ImageTree::selectFolder);
	connect(open_this_item_in_edtior, &QAction::triggered, this, &ImageTree::removeSelectedImages);*/
}

QCaseTreeView::~QCaseTreeView()
{

	if (m_RightClickSelectMenu)
	{
		delete  m_RightClickSelectMenu;
		m_RightClickSelectMenu = nullptr;
	}
	for (size_t i = 0; i < m_MenuActionList.length(); ++i)
	{
		if (m_MenuActionList[i]!= nullptr)
		{
			delete m_MenuActionList[i];
			m_MenuActionList[i] = nullptr;
			
		}
	}
	m_MenuActionList.clear();
}
void QCaseTreeView::dragMoveEvent(QDragMoveEvent * event)
{

}
void QCaseTreeView::mousePressEvent(QMouseEvent *e)
{
	if (e->button() == Qt::RightButton)         
	{
		m_RightClickSelectMenu = new QMenu(this);

		QModelIndex index = indexAt(e->pos());  
		if (index.isValid())                   
		{
			QVariant data = index.data(Qt::UserRole + 1);
		}
	}
}

void QCaseTreeView::mouseReleaseEvent(QMouseEvent * event)
{

}

void QCaseTreeView::mouseDoubleClickEvent(QMouseEvent * event)
{


}

void QCaseTreeView::mouseMoveEvent(QMouseEvent * event)
{

}
