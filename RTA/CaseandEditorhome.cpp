#include "stdafx.h"
#include "CaseandEditorhome.h"

CaseandEditorhome::CaseandEditorhome(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connectslots();
}

CaseandEditorhome::~CaseandEditorhome()
{

	
}

bool CaseandEditorhome::connectslots()
{
	if (!
		(
			/*connect(this->ui.LE_ProjectPath, &QLineEdit::textChanged, this, &CaseandEditorhome::ChoosePythonFileHome) &&
			connect(this->ui.LE_PycharmPath, &QLineEdit::textChanged, this, &CaseandEditorhome::ChoosePycharmHome) &&*/
			connect(this->ui.PB_ProjectPath, &QPushButton::clicked, this, &CaseandEditorhome::SelectPythonFileHome)&&
			connect(this->ui.PB_PycharmPath, &QPushButton::clicked, this, &CaseandEditorhome::SelectPycharmHome)&&
			connect(this->ui.buttonBox, &QDialogButtonBox::clicked, this, &CaseandEditorhome::Accpet)
		)
		)
	{

		throw(" connect signal and  slots faile in MainWindows ");

	}
	return true;
}

bool CaseandEditorhome::SelectPycharmHome()
{
	QFileDialog pycasefile(nullptr);
	pycasefile.setWindowTitle(tr("Set Python Editor home "));//
	pycasefile.setAcceptMode(QFileDialog::AcceptMode::AcceptOpen);//
	pycasefile.setFileMode(QFileDialog::FileMode::Directory);//
	pycasefile.setViewMode(QFileDialog::Detail);//
	if (pycasefile.exec() == QFileDialog::Accepted)
	{
		QString m_strpycharmbinpath;
		m_strpycharmbinpath = pycasefile.selectedFiles()[0];
		ui.LE_PycharmPath->setText(m_strpycharmbinpath);
		
	}
	return true;
}
//bool CaseandEditorhome::ChoosePythonFileHome()
//{
//
//	emit Signal_eimtPythonFileHome(this->ui.LE_ProjectPath->text());
//	return true;
//}
//bool CaseandEditorhome::ChoosePycharmHome()
//{
//	emit Signal_eimtPycharmHome(this->ui.LE_PycharmPath->text());
//	return true;
//}
bool CaseandEditorhome::Accpet()
{

	if (!this->ui.LE_PycharmPath->text().isEmpty())
	{
		emit Signal_eimtPycharmHome(this->ui.LE_PycharmPath->text());
	}
	if (!this->ui.LE_ProjectPath->text().isEmpty())
	{
		emit Signal_eimtPythonFileHome(this->ui.LE_ProjectPath->text());
	}
	this->close();
	return true;
}
bool CaseandEditorhome::SelectPythonFileHome()
{
	QFileDialog pycasefile(nullptr);
	pycasefile.setWindowTitle(tr("Set Python Case home "));//
	pycasefile.setAcceptMode(QFileDialog::AcceptMode::AcceptOpen);//
	pycasefile.setFileMode(QFileDialog::FileMode::Directory);//
	pycasefile.setViewMode(QFileDialog::Detail);//
	if (pycasefile.exec() == QFileDialog::Accepted)
	{
		QString m_strpycasefilehomepath;
		m_strpycasefilehomepath = pycasefile.selectedFiles()[0];
		ui.LE_ProjectPath->setText(m_strpycasefilehomepath);
		
	}
	return true;
}
