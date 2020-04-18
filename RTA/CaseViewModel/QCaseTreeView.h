#pragma once

#include <QWidget>

class QCaseTreeView : public QTreeView
{
	Q_OBJECT
	
public:
	QCaseTreeView(QWidget *parent);
	~QCaseTreeView();
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
