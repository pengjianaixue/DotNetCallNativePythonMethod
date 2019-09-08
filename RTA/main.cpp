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
	mw.setWindowTitle("RTS");
	mw.show();

	/*QFile f(":qdarkstyle/style.qss");
	if (!f.exists())
	{
		printf("Unable to set stylesheet, file not found\n");
	}
	else
	{
		f.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&f);
		qApp->setStyleSheet(ts.readAll());
	}*/
	return a.exec();
}
