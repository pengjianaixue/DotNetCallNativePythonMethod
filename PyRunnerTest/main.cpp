#include "stdafx.h"
#include "PyRunner.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PyRunner w;
	QIcon icon;
	QApplication::setStyle(QStyleFactory::create("Fusion"));
	icon.addFile(":/RTA/PyRunner/R.png");
	a.setWindowIcon(icon);
	w.setWindowTitle("RATRunner");
	w.show();
	return a.exec();
}
