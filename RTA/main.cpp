#include "stdafx.h"
#include "MainWindows.h"
#include <QtWidgets/QApplication>
//#include "vld.h"

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	QApplication::setStyle(QStyleFactory::create("Fusion"));
	MainWindows mw;
	QIcon icon;
	icon.addFile(":/StartForm/Resources/R.ico");
	a.setWindowIcon(icon);
	mw.setWindowTitle("RAT");
	mw.show();
	return a.exec();
}
