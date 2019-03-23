#include "stdafx.h"
#include "MainWindows.h"

MainWindows::MainWindows(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	if (!connect(this->ui.ScriptConfigure, &QAction::triggered, this, &MainWindows::openconfigform))
	{


		throw(" connect signal and  slots faile in MainWindows ");

	}
}
bool MainWindows::openconfigform(int i)
{
	m_uirunscript.show();
	return true;
}
MainWindows::~MainWindows()
{

}
