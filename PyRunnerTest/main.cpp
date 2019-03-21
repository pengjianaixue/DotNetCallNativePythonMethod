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
	icon.addFile(":/RTA/PyRunner/R.png");
	a.setWindowIcon(icon);
	mw.setWindowTitle("RATRunner");
	mw.show();
	return a.exec();
}
