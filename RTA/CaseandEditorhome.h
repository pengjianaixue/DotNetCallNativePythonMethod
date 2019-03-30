#pragma once

#include <QDialog>
#include "ui_CaseandEditorhome.h"

class CaseandEditorhome : public QDialog
{
	Q_OBJECT
public:
	CaseandEditorhome(QWidget *parent = Q_NULLPTR);
	~CaseandEditorhome();
	bool SetPypathExtra(const QString& pycasepath,const QString& pycharmbinpath);
private:
	bool connectslots();
	
signals:
	void Signal_eimtPythonFileHome(const QString &);
	void Signal_eimtPycharmHome(const QString &);
public slots:
	bool SelectPythonFileHome();
	bool SelectPycharmHome();
	//bool ChoosePythonFileHome();
	//bool ChoosePycharmHome();
	bool Accpet();
private:
	Ui::CaseandEditorhome ui;
	QString m_strpycasefilehomepath;
	QString m_strpycharmbinpath;
};
