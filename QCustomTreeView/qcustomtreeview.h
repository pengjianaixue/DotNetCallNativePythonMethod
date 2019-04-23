#ifndef QCUSTOMTREEVIEW_H
#define QCUSTOMTREEVIEW_H

#include <QTreeView>

class QCustomTreeView : public QTreeView
{
    Q_OBJECT

public:
    QCustomTreeView(QWidget *parent = 0);
};

#endif
