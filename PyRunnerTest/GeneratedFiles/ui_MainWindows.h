/********************************************************************************
** Form generated from reading UI file 'MainWindows.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWS_H
#define UI_MAINWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindows
{
public:
    QAction *ScirptRun;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindows)
    {
        if (MainWindows->objectName().isEmpty())
            MainWindows->setObjectName(QStringLiteral("MainWindows"));
        MainWindows->resize(594, 491);
        ScirptRun = new QAction(MainWindows);
        ScirptRun->setObjectName(QStringLiteral("ScirptRun"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/StartForm/Resources/startui.png"), QSize(), QIcon::Normal, QIcon::Off);
        ScirptRun->setIcon(icon);
        centralWidget = new QWidget(MainWindows);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindows->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindows);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 594, 21));
        MainWindows->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindows);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindows->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindows);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindows->setStatusBar(statusBar);

        mainToolBar->addAction(ScirptRun);

        retranslateUi(MainWindows);

        QMetaObject::connectSlotsByName(MainWindows);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindows)
    {
        MainWindows->setWindowTitle(QApplication::translate("MainWindows", "RTA", Q_NULLPTR));
        ScirptRun->setText(QApplication::translate("MainWindows", "ScirptRun", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        ScirptRun->setShortcut(QApplication::translate("MainWindows", "Ctrl+R", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
    } // retranslateUi

};

namespace Ui {
    class MainWindows: public Ui_MainWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWS_H
