#ifndef QCUSTOMTREEVIEW_H
#define QCUSTOMTREEVIEW_H

#include <QTreeView>
#include <QAction>
#include <QList>
#include <QMenu>
class QCustomTreeView : public QTreeView
{
    Q_OBJECT

public:
    QCustomTreeView(QWidget *parent = 0);
    ~QCustomTreeView();
signals:
    void sig_Emittheselectrowvaule(const QVariant &rowvaule);
    void sig_EmitTheParantvaule(const QVariant &rowvaule);
protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void dragMoveEvent(QDragMoveEvent *event) Q_DECL_OVERRIDE;
private:
    QMenu					*m_RightClickSelectMenu;
    QList<QAction*>			 m_MenuActionList;
};

#endif
