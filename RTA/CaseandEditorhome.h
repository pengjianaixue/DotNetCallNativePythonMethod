#pragma once

#include <QDialog>
#include "ui_CaseandEditorhome.h"

class CaseandEditorhome : public QDialog
{
	Q_OBJECT
public:
	CaseandEditorhome(QWidget *parent = Q_NULLPTR);
	~CaseandEditorhome();
signals:
	void EmitPythonFileHome(QString);
	void EmitPycharmHome(QString);
public slots:
	bool SelectPythonFileHome();
	bool SelectPycharmHome();
private:
	Ui::CaseandEditorhome ui;
};
