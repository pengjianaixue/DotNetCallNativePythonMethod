#include "qcustomtreeview.h"

QCustomTreeView::QCustomTreeView(QWidget *parent) :
    QTreeView(parent)
{
        QAction *add_to_exclist = new QAction(this);
        QAction *igrone_this_item = new QAction(this);
        QAction *open_this_item_in_edtior = new QAction(this);
        m_MenuActionList.append(add_to_exclist);
        m_MenuActionList.append(igrone_this_item);
        m_MenuActionList.append(open_this_item_in_edtior);
        m_RightClickSelectMenu = new QMenu(this);
        m_RightClickSelectMenu->hide();
}

QCustomTreeView::~QCustomTreeView()
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

void QCustomTreeView::mousePressEvent(QMouseEvent *event)
{

//    if(event->button() == Qt::LeftButton)
//    {

//        Q_D(QTreeView);
//        bool handled = false;
//        if (style()->styleHint(QStyle::SH_ListViewExpand_SelectMouseType, 0, this) == QEvent::MouseButtonPress)
//            handled = d->expandOrCollapseItemAtPos(event->pos());
//        if (!handled && d->itemDecorationAt(event->pos()) == -1)
//            QAbstractItemView::mousePressEvent(event);
//    }
    if (event->button() == Qt::RightButton)
    {

        m_RightClickSelectMenu->show();
        QModelIndex index = indexAt(event->pos());
        if (index.isValid())
        {
            QVariant data = index.data(Qt::UserRole + 1);
        }
    }
}

void QCustomTreeView::mouseReleaseEvent(QMouseEvent *event)
{

}

void QCustomTreeView::mouseDoubleClickEvent(QMouseEvent *event)
{

}

void QCustomTreeView::mouseMoveEvent(QMouseEvent *event)
{

}

void QCustomTreeView::dragMoveEvent(QDragMoveEvent *event)
{

}
