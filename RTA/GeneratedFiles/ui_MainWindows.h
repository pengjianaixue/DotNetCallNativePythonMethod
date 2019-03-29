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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindows
{
public:
    QAction *ScirptRun;
    QAction *ScriptConfigure;
    QAction *TestPlan;
    QAction *Test_Instrument;
    QAction *TestProduct;
    QAction *action_Script_Editor_Pycharm;
    QAction *action_SetPythonFileHome;
    QAction *actionNew_Project_File;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget_2;
    QWidget *tab;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QMenu *menuNew_Project_File;
    QMenu *menuOption;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *DW_ToolDock;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout_5;
    QToolBox *toolBox;
    QWidget *TB_Routerpage;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QWidget *TB_ConfigurePage;
    QDockWidget *DW_historyinfor;
    QWidget *dockWidgetContents_4;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_8;
    QDockWidget *DW_Proterty;
    QWidget *dockWidgetContents_6;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_10;
    QListView *LV_ProPerty;
    QLabel *label;
    QDockWidget *DW_Opeartioninfodisp;
    QWidget *dockWidgetContents_7;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_12;
    QTabWidget *TW_OpeationDisp;
    QWidget *tw_opeartioninfo;
    QWidget *tw_errorinfo;

    void setupUi(QMainWindow *MainWindows)
    {
        if (MainWindows->objectName().isEmpty())
            MainWindows->setObjectName(QStringLiteral("MainWindows"));
        MainWindows->resize(1197, 863);
        MainWindows->setStyleSheet(QLatin1String("QMainWindow::separator:horizontal {\n"
"    width: 3px;\n"
"    margin-top: 3px;\n"
"    margin-bottom: 3px;\n"
"}\n"
"\n"
"QMainWindow::separator:vertical {\n"
"    height: 3px;\n"
"    margin-left: 3px;\n"
"    margin-right: 3px;\n"
"}"));
        ScirptRun = new QAction(MainWindows);
        ScirptRun->setObjectName(QStringLiteral("ScirptRun"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/StartForm/Resources/startui.png"), QSize(), QIcon::Normal, QIcon::Off);
        ScirptRun->setIcon(icon);
        ScriptConfigure = new QAction(MainWindows);
        ScriptConfigure->setObjectName(QStringLiteral("ScriptConfigure"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/StartForm/Resources/config_script.png"), QSize(), QIcon::Normal, QIcon::Off);
        ScriptConfigure->setIcon(icon1);
        TestPlan = new QAction(MainWindows);
        TestPlan->setObjectName(QStringLiteral("TestPlan"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/StartForm/Resources/test plan.png"), QSize(), QIcon::Normal, QIcon::Off);
        TestPlan->setIcon(icon2);
        Test_Instrument = new QAction(MainWindows);
        Test_Instrument->setObjectName(QStringLiteral("Test_Instrument"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/StartForm/Resources/instrment.png"), QSize(), QIcon::Normal, QIcon::Off);
        Test_Instrument->setIcon(icon3);
        TestProduct = new QAction(MainWindows);
        TestProduct->setObjectName(QStringLiteral("TestProduct"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/StartForm/Resources/rru.png"), QSize(), QIcon::Normal, QIcon::Off);
        TestProduct->setIcon(icon4);
        action_Script_Editor_Pycharm = new QAction(MainWindows);
        action_Script_Editor_Pycharm->setObjectName(QStringLiteral("action_Script_Editor_Pycharm"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/StartForm/Resources/Pycharmicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Script_Editor_Pycharm->setIcon(icon5);
        action_SetPythonFileHome = new QAction(MainWindows);
        action_SetPythonFileHome->setObjectName(QStringLiteral("action_SetPythonFileHome"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/StartForm/Resources/Path.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_SetPythonFileHome->setIcon(icon6);
        actionNew_Project_File = new QAction(MainWindows);
        actionNew_Project_File->setObjectName(QStringLiteral("actionNew_Project_File"));
        centralWidget = new QWidget(MainWindows);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget_2->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget_2->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget_2, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        MainWindows->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindows);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1197, 23));
        menuBar->setStyleSheet(QStringLiteral(""));
        menuNew_Project_File = new QMenu(menuBar);
        menuNew_Project_File->setObjectName(QStringLiteral("menuNew_Project_File"));
        menuOption = new QMenu(menuBar);
        menuOption->setObjectName(QStringLiteral("menuOption"));
        MainWindows->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindows);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setStyleSheet(QLatin1String("QToolBar {\n"
"	\n"
"	background-color: rgb(244, 255, 240);\n"
"    border-bottom: 1px solid #19232D;\n"
"    padding: 2px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QToolBar QToolButton{\n"
"    background-color: rgb(244, 255, 240);\n"
"}"));
        MainWindows->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindows);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindows->setStatusBar(statusBar);
        DW_ToolDock = new QDockWidget(MainWindows);
        DW_ToolDock->setObjectName(QStringLiteral("DW_ToolDock"));
        DW_ToolDock->setStyleSheet(QLatin1String("\n"
"QDockWidget::title {\n"
"    padding: 3px;   /* better size for title bar */\n"
"    border: none;\n"
"    background-color: #f2fdee;\n"
"}\n"
"QDockWidget::dockWidgetContents {\n"
"	\n"
"	border: 1px solid black;\n"
"\n"
"}\n"
"QDockWidget::separator {\n"
"    width: 3px;\n"
"}\n"
"\n"
"\n"
""));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        gridLayout_5 = new QGridLayout(dockWidgetContents_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        toolBox = new QToolBox(dockWidgetContents_2);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setMinimumSize(QSize(100, 0));
        toolBox->setStyleSheet(QLatin1String("QToolBox {\n"
"    padding: 0px;\n"
"    border: 1px solid \n"
"}\n"
"\n"
"QToolBox::selected {\n"
"    padding: 0px;\n"
"    border: 2px solid #1464A0;\n"
"}\n"
"\n"
"QToolBox::tab {\n"
"    border: 1px solid \n"
"    color: #F0F0F0;\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"}\n"
"\n"
"QToolBox::tab:disabled {\n"
"    color: #787878;\n"
"}\n"
"\n"
"QToolBox::tab:selected {\n"
"    border-bottom: 2px solid\n"
"}\n"
"\n"
"QToolBox::tab:!selected {\n"
"    border-bottom: 2px solid \n"
"}\n"
"\n"
"QToolBox::tab:selected:disabled {\n"
"    border-bottom: 2px solid #14506E;\n"
"}\n"
"\n"
"QToolBox::tab:!selected:disabled {\n"
"    background-color: #19232D;\n"
"}\n"
"\n"
"QToolBox::tab:hover {\n"
"    border-color: #148CD2;\n"
"    border-bottom: 2px solid #148CD2;\n"
"}\n"
"\n"
"QToolBox QScrollArea QWidget QWidget {\n"
"    padding: 0px;\n"
"    background-color: #19232D;\n"
"}"));
        toolBox->setFrameShape(QFrame::NoFrame);
        toolBox->setLineWidth(5);
        toolBox->setMidLineWidth(3);
        TB_Routerpage = new QWidget();
        TB_Routerpage->setObjectName(QStringLiteral("TB_Routerpage"));
        TB_Routerpage->setGeometry(QRect(0, 0, 98, 419));
        gridLayout_6 = new QGridLayout(TB_Routerpage);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        pushButton_3 = new QPushButton(TB_Routerpage);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_6->addWidget(pushButton_3, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(TB_Routerpage);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_6->addWidget(pushButton_5, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(TB_Routerpage);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout_6->addWidget(pushButton_6, 2, 0, 1, 1);

        pushButton_7 = new QPushButton(TB_Routerpage);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_6->addWidget(pushButton_7, 3, 0, 1, 1);

        pushButton_8 = new QPushButton(TB_Routerpage);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout_6->addWidget(pushButton_8, 4, 0, 1, 1);

        toolBox->addItem(TB_Routerpage, QStringLiteral("Router Tool"));
        TB_ConfigurePage = new QWidget();
        TB_ConfigurePage->setObjectName(QStringLiteral("TB_ConfigurePage"));
        TB_ConfigurePage->setGeometry(QRect(0, 0, 98, 419));
        toolBox->addItem(TB_ConfigurePage, QStringLiteral("Configure Tool"));

        gridLayout_5->addWidget(toolBox, 0, 0, 1, 1);

        DW_ToolDock->setWidget(dockWidgetContents_2);
        MainWindows->addDockWidget(static_cast<Qt::DockWidgetArea>(1), DW_ToolDock);
        DW_historyinfor = new QDockWidget(MainWindows);
        DW_historyinfor->setObjectName(QStringLiteral("DW_historyinfor"));
        DW_historyinfor->setStyleSheet(QLatin1String("QDockWidget {\n"
"    outline: 1px solid #f2fdee;\n"
"    background-color: #19232D;\n"
"    border: 1px solid #f2fdee;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QDockWidget::title {\n"
"    padding: 6px;   /* better size for title bar */\n"
"    border: none;\n"
"    background-color: #f2fdee;\n"
"}"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        gridLayout_9 = new QGridLayout(dockWidgetContents_4);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));

        gridLayout_9->addLayout(gridLayout_8, 0, 0, 1, 1);

        DW_historyinfor->setWidget(dockWidgetContents_4);
        MainWindows->addDockWidget(static_cast<Qt::DockWidgetArea>(1), DW_historyinfor);
        DW_Proterty = new QDockWidget(MainWindows);
        DW_Proterty->setObjectName(QStringLiteral("DW_Proterty"));
        DW_Proterty->setStyleSheet(QLatin1String("QDockWidget {\n"
"    outline: 1px solid #32414B;\n"
"    background-color: #19232D;\n"
"    border: 1px solid #32414B;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QDockWidget::title {\n"
"    padding: 6px;   /* better size for title bar */\n"
"    border: none;\n"
"    background-color: #32414B;\n"
"}\n"
"\n"
"QDockWidget::close-button {\n"
"    background-color: #32414B;\n"
"    border-radius: 4px;\n"
"    border: none;\n"
"}\n"
"\n"
"QDockWidget::close-button:hover {\n"
"    border: 1px solid #32414B;\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed {\n"
"    border: 1px solid #32414B;\n"
"}\n"
"\n"
"QDockWidget::float-button {\n"
"    background-color: #32414B;\n"
"    border-radius: 4px;\n"
"    border: none;\n"
"}\n"
"\n"
"QDockWidget::float-button:hover {\n"
"    border: 1px solid #32414B;\n"
"}\n"
"\n"
"QDockWidget::float-button:pressed {\n"
"    border: 1px solid #32414B;\n"
"}"));
        dockWidgetContents_6 = new QWidget();
        dockWidgetContents_6->setObjectName(QStringLiteral("dockWidgetContents_6"));
        gridLayout_11 = new QGridLayout(dockWidgetContents_6);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        LV_ProPerty = new QListView(dockWidgetContents_6);
        LV_ProPerty->setObjectName(QStringLiteral("LV_ProPerty"));
        LV_ProPerty->setMinimumSize(QSize(80, 300));

        gridLayout_10->addWidget(LV_ProPerty, 1, 0, 1, 1);

        label = new QLabel(dockWidgetContents_6);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout_10->addWidget(label, 0, 0, 1, 1);


        gridLayout_11->addLayout(gridLayout_10, 0, 0, 1, 1);

        DW_Proterty->setWidget(dockWidgetContents_6);
        MainWindows->addDockWidget(static_cast<Qt::DockWidgetArea>(2), DW_Proterty);
        DW_Opeartioninfodisp = new QDockWidget(MainWindows);
        DW_Opeartioninfodisp->setObjectName(QStringLiteral("DW_Opeartioninfodisp"));
        DW_Opeartioninfodisp->setStyleSheet(QLatin1String("QDockWidget {\n"
"    outline: 1px solid #32414B;\n"
"    background-color: #19232D;\n"
"    border: 1px solid #32414B;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QDockWidget::title {\n"
"    padding: 6px;   /* better size for title bar */\n"
"    border: none;\n"
"    background-color: #32414B;\n"
"}\n"
"\n"
"QDockWidget::close-button {\n"
"    background-color: #32414B;\n"
"    border-radius: 4px;\n"
"    border: none;\n"
"}\n"
"\n"
"QDockWidget::close-button:hover {\n"
"    border: 1px solid #32414B;\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed {\n"
"    border: 1px solid #32414B;\n"
"}\n"
"\n"
"QDockWidget::float-button {\n"
"    background-color: #32414B;\n"
"    border-radius: 4px;\n"
"    border: none;\n"
"}\n"
"\n"
"QDockWidget::float-button:hover {\n"
"    border: 1px solid #32414B;\n"
"}\n"
"\n"
"QDockWidget::float-button:pressed {\n"
"    border: 1px solid #32414B;\n"
"}"));
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName(QStringLiteral("dockWidgetContents_7"));
        gridLayout_13 = new QGridLayout(dockWidgetContents_7);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        TW_OpeationDisp = new QTabWidget(dockWidgetContents_7);
        TW_OpeationDisp->setObjectName(QStringLiteral("TW_OpeationDisp"));
        TW_OpeationDisp->setMinimumSize(QSize(0, 80));
        TW_OpeationDisp->setStyleSheet(QStringLiteral(""));
        TW_OpeationDisp->setMovable(true);
        tw_opeartioninfo = new QWidget();
        tw_opeartioninfo->setObjectName(QStringLiteral("tw_opeartioninfo"));
        tw_opeartioninfo->setFont(font);
        tw_opeartioninfo->setStyleSheet(QStringLiteral("background-color: rgb(246, 255, 240);"));
        TW_OpeationDisp->addTab(tw_opeartioninfo, QString());
        tw_errorinfo = new QWidget();
        tw_errorinfo->setObjectName(QStringLiteral("tw_errorinfo"));
        tw_errorinfo->setFont(font);
        tw_errorinfo->setStyleSheet(QStringLiteral("background-color: rgb(255, 246, 222);"));
        TW_OpeationDisp->addTab(tw_errorinfo, QString());

        gridLayout_12->addWidget(TW_OpeationDisp, 0, 0, 1, 1);


        gridLayout_13->addLayout(gridLayout_12, 0, 0, 1, 1);

        DW_Opeartioninfodisp->setWidget(dockWidgetContents_7);
        MainWindows->addDockWidget(static_cast<Qt::DockWidgetArea>(8), DW_Opeartioninfodisp);

        menuBar->addAction(menuNew_Project_File->menuAction());
        menuBar->addAction(menuOption->menuAction());
        menuNew_Project_File->addAction(actionNew_Project_File);
        menuOption->addAction(action_SetPythonFileHome);
        mainToolBar->addAction(ScirptRun);
        mainToolBar->addAction(ScriptConfigure);
        mainToolBar->addAction(TestPlan);
        mainToolBar->addSeparator();
        mainToolBar->addAction(Test_Instrument);
        mainToolBar->addAction(TestProduct);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Script_Editor_Pycharm);

        retranslateUi(MainWindows);

        tabWidget_2->setCurrentIndex(0);
        toolBox->setCurrentIndex(1);
        TW_OpeationDisp->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindows);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindows)
    {
        MainWindows->setWindowTitle(QApplication::translate("MainWindows", "RTA", Q_NULLPTR));
        ScirptRun->setText(QApplication::translate("MainWindows", "ScirptRun", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        ScirptRun->setShortcut(QApplication::translate("MainWindows", "Ctrl+R", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        ScriptConfigure->setText(QApplication::translate("MainWindows", "ScriptConfigure", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        ScriptConfigure->setShortcut(QApplication::translate("MainWindows", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        TestPlan->setText(QApplication::translate("MainWindows", "TestPlan", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        TestPlan->setShortcut(QApplication::translate("MainWindows", "Ctrl+P", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        Test_Instrument->setText(QApplication::translate("MainWindows", "Test Instrument", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        Test_Instrument->setShortcut(QApplication::translate("MainWindows", "Ctrl+I", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        TestProduct->setText(QApplication::translate("MainWindows", "Test Product", Q_NULLPTR));
        action_Script_Editor_Pycharm->setText(QApplication::translate("MainWindows", "Script Editor(Pycharm)", Q_NULLPTR));
        action_SetPythonFileHome->setText(QApplication::translate("MainWindows", "SetPythonFileHome", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_SetPythonFileHome->setToolTip(QApplication::translate("MainWindows", "select  the python  file path which you want to choose  ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionNew_Project_File->setText(QApplication::translate("MainWindows", "New Project File", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QApplication::translate("MainWindows", "Tab 1", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("MainWindows", "Tab 2", Q_NULLPTR));
        menuNew_Project_File->setTitle(QApplication::translate("MainWindows", "File", Q_NULLPTR));
        menuOption->setTitle(QApplication::translate("MainWindows", "SetUp", Q_NULLPTR));
        pushButton_3->setText(QString());
        pushButton_5->setText(QApplication::translate("MainWindows", "PushButton", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindows", "PushButton", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindows", "PushButton", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindows", "PushButton", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(TB_Routerpage), QApplication::translate("MainWindows", "Router Tool", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(TB_ConfigurePage), QApplication::translate("MainWindows", "Configure Tool", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindows", "Property", Q_NULLPTR));
        TW_OpeationDisp->setTabText(TW_OpeationDisp->indexOf(tw_opeartioninfo), QApplication::translate("MainWindows", "Opeartion Info", Q_NULLPTR));
        TW_OpeationDisp->setTabText(TW_OpeationDisp->indexOf(tw_errorinfo), QApplication::translate("MainWindows", "Error Info", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindows: public Ui_MainWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWS_H
