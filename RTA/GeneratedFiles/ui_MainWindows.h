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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindows
{
public:
    QAction *Auto_Test;
    QAction *ScriptConfigure;
    QAction *TestPlan;
    QAction *Test_Instrument;
    QAction *TestProduct;
    QAction *action_Script_Editor_Pycharm;
    QAction *action_SetPythonFileHome;
    QAction *actionNew_Project_File;
    QAction *actionOpen_Project;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget_main;
    QWidget *Home;
    QWidget *Auto_test;
    QGridLayout *gridLayout;
    QFrame *Auto_test_frame;
    QGridLayout *gridLayout_8;
    QTreeView *Run_case_status_tree;
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
    QDockWidget *DW_Proterty;
    QWidget *dockWidgetContents_6;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_10;
    QListView *LV_ProPerty;
    QLabel *label;
    QDockWidget *dockWidget_Opeartioninfodisp;
    QWidget *dockWidgetContents_7;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_12;
    QTabWidget *TW_OpeationDisp;
    QWidget *tw_opeartioninfo;
    QDockWidget *dockWidget_ErrorInfo;
    QWidget *dockWidgetContents_5;
    QGridLayout *gridLayout_2;
    QTabWidget *TW_OpeationDisp_ErrorInfo;
    QWidget *tw_errorinfo_2;
    QDockWidget *dockWidget_Terminal;
    QWidget *dockWidgetContents_8;
    QGridLayout *gridLayout_14;
    QTabWidget *TW_OpeationDisp_2;
    QWidget *tw_Terminal;
    QGridLayout *gridLayout_7;
    QSpacerItem *horizontalSpacer;
    QPlainTextEdit *PTE_TerimnalDisplayArea;
    QPushButton *pushButton_clearTerminal;

    void setupUi(QMainWindow *MainWindows)
    {
        if (MainWindows->objectName().isEmpty())
            MainWindows->setObjectName(QStringLiteral("MainWindows"));
        MainWindows->resize(1302, 806);
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
        Auto_Test = new QAction(MainWindows);
        Auto_Test->setObjectName(QStringLiteral("Auto_Test"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/StartForm/Resources/auto_test.png"), QSize(), QIcon::Normal, QIcon::Off);
        Auto_Test->setIcon(icon);
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
        icon5.addFile(QStringLiteral(":/StartForm/Resources/ide-data.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Script_Editor_Pycharm->setIcon(icon5);
        action_SetPythonFileHome = new QAction(MainWindows);
        action_SetPythonFileHome->setObjectName(QStringLiteral("action_SetPythonFileHome"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/StartForm/Resources/Path.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_SetPythonFileHome->setIcon(icon6);
        actionNew_Project_File = new QAction(MainWindows);
        actionNew_Project_File->setObjectName(QStringLiteral("actionNew_Project_File"));
        actionOpen_Project = new QAction(MainWindows);
        actionOpen_Project->setObjectName(QStringLiteral("actionOpen_Project"));
        centralWidget = new QWidget(MainWindows);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tabWidget_main = new QTabWidget(centralWidget);
        tabWidget_main->setObjectName(QStringLiteral("tabWidget_main"));
        Home = new QWidget();
        Home->setObjectName(QStringLiteral("Home"));
        tabWidget_main->addTab(Home, QString());
        Auto_test = new QWidget();
        Auto_test->setObjectName(QStringLiteral("Auto_test"));
        gridLayout = new QGridLayout(Auto_test);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Auto_test_frame = new QFrame(Auto_test);
        Auto_test_frame->setObjectName(QStringLiteral("Auto_test_frame"));
        Auto_test_frame->setFrameShape(QFrame::StyledPanel);
        Auto_test_frame->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(Auto_test_frame);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        Run_case_status_tree = new QTreeView(Auto_test_frame);
        Run_case_status_tree->setObjectName(QStringLiteral("Run_case_status_tree"));

        gridLayout_8->addWidget(Run_case_status_tree, 0, 0, 1, 1);


        gridLayout->addWidget(Auto_test_frame, 0, 0, 1, 1);

        tabWidget_main->addTab(Auto_test, QString());

        gridLayout_3->addWidget(tabWidget_main, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        MainWindows->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindows);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1302, 23));
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
"    padding:6px 1px 1px;   /* better size for title bar */\n"
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
        DW_ToolDock->setFeatures(QDockWidget::AllDockWidgetFeatures);
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
        TB_Routerpage->setGeometry(QRect(0, 0, 98, 311));
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
        TB_ConfigurePage->setGeometry(QRect(0, 0, 98, 311));
        toolBox->addItem(TB_ConfigurePage, QStringLiteral("Configure Tool"));

        gridLayout_5->addWidget(toolBox, 0, 0, 1, 1);

        DW_ToolDock->setWidget(dockWidgetContents_2);
        MainWindows->addDockWidget(static_cast<Qt::DockWidgetArea>(1), DW_ToolDock);
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
"    padding:6px 1px 1px;   /* better size for title bar */\n"
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
        DW_Proterty->setFeatures(QDockWidget::AllDockWidgetFeatures);
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
        dockWidget_Opeartioninfodisp = new QDockWidget(MainWindows);
        dockWidget_Opeartioninfodisp->setObjectName(QStringLiteral("dockWidget_Opeartioninfodisp"));
        dockWidget_Opeartioninfodisp->setStyleSheet(QLatin1String("QDockWidget {\n"
"    outline: 1px solid #32414B;\n"
"    background-color: #19232D;\n"
"    border: 1px solid #32414B;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QDockWidget::title {\n"
"    padding:7px 1px 1px;   /* better size for title bar */\n"
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
        dockWidget_Opeartioninfodisp->setFloating(false);
        dockWidget_Opeartioninfodisp->setFeatures(QDockWidget::AllDockWidgetFeatures);
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
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/StartForm/Resources/operation.png"), QSize(), QIcon::Normal, QIcon::Off);
        TW_OpeationDisp->addTab(tw_opeartioninfo, icon7, QString());

        gridLayout_12->addWidget(TW_OpeationDisp, 0, 0, 1, 1);


        gridLayout_13->addLayout(gridLayout_12, 0, 0, 1, 1);

        dockWidget_Opeartioninfodisp->setWidget(dockWidgetContents_7);
        MainWindows->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_Opeartioninfodisp);
        dockWidget_ErrorInfo = new QDockWidget(MainWindows);
        dockWidget_ErrorInfo->setObjectName(QStringLiteral("dockWidget_ErrorInfo"));
        dockWidget_ErrorInfo->setStyleSheet(QLatin1String("QDockWidget {\n"
"    outline: 1px solid #32414B;\n"
"    background-color: #19232D;\n"
"    border: 1px solid #32414B;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QDockWidget::title {\n"
"    padding:7px 1px 1px;   /* better size for title bar */\n"
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
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QStringLiteral("dockWidgetContents_5"));
        gridLayout_2 = new QGridLayout(dockWidgetContents_5);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        TW_OpeationDisp_ErrorInfo = new QTabWidget(dockWidgetContents_5);
        TW_OpeationDisp_ErrorInfo->setObjectName(QStringLiteral("TW_OpeationDisp_ErrorInfo"));
        TW_OpeationDisp_ErrorInfo->setMinimumSize(QSize(0, 80));
        TW_OpeationDisp_ErrorInfo->setStyleSheet(QStringLiteral("background-color: rgb(65, 65, 65);"));
        TW_OpeationDisp_ErrorInfo->setMovable(true);
        tw_errorinfo_2 = new QWidget();
        tw_errorinfo_2->setObjectName(QStringLiteral("tw_errorinfo_2"));
        tw_errorinfo_2->setFont(font);
        tw_errorinfo_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 246, 222);"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/StartForm/Resources/Error.png"), QSize(), QIcon::Normal, QIcon::Off);
        TW_OpeationDisp_ErrorInfo->addTab(tw_errorinfo_2, icon8, QString());

        gridLayout_2->addWidget(TW_OpeationDisp_ErrorInfo, 0, 0, 1, 1);

        dockWidget_ErrorInfo->setWidget(dockWidgetContents_5);
        MainWindows->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_ErrorInfo);
        dockWidget_Terminal = new QDockWidget(MainWindows);
        dockWidget_Terminal->setObjectName(QStringLiteral("dockWidget_Terminal"));
        dockWidget_Terminal->setStyleSheet(QLatin1String("QDockWidget {\n"
"    outline: 1px solid #32414B;\n"
"    background-color: #19232D;\n"
"    border: 1px solid #32414B;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QDockWidget::title {\n"
"    padding:7px 1px 1px;   /* better size for title bar */\n"
"	border:  none;\n"
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
        dockWidgetContents_8 = new QWidget();
        dockWidgetContents_8->setObjectName(QStringLiteral("dockWidgetContents_8"));
        gridLayout_14 = new QGridLayout(dockWidgetContents_8);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        TW_OpeationDisp_2 = new QTabWidget(dockWidgetContents_8);
        TW_OpeationDisp_2->setObjectName(QStringLiteral("TW_OpeationDisp_2"));
        TW_OpeationDisp_2->setMinimumSize(QSize(0, 80));
        TW_OpeationDisp_2->setStyleSheet(QStringLiteral(""));
        TW_OpeationDisp_2->setMovable(true);
        tw_Terminal = new QWidget();
        tw_Terminal->setObjectName(QStringLiteral("tw_Terminal"));
        gridLayout_7 = new QGridLayout(tw_Terminal);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        horizontalSpacer = new QSpacerItem(617, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer, 0, 0, 1, 1);

        PTE_TerimnalDisplayArea = new QPlainTextEdit(tw_Terminal);
        PTE_TerimnalDisplayArea->setObjectName(QStringLiteral("PTE_TerimnalDisplayArea"));
        PTE_TerimnalDisplayArea->setStyleSheet(QLatin1String("background-color: rgb(65, 65, 65);\n"
"font: 75 12pt \"Consolas\";\n"
"color: rgb(255, 255, 255);\n"
""));
        PTE_TerimnalDisplayArea->setReadOnly(false);

        gridLayout_7->addWidget(PTE_TerimnalDisplayArea, 1, 0, 1, 2);

        pushButton_clearTerminal = new QPushButton(tw_Terminal);
        pushButton_clearTerminal->setObjectName(QStringLiteral("pushButton_clearTerminal"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/StartForm/Resources/clean up.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_clearTerminal->setIcon(icon9);

        gridLayout_7->addWidget(pushButton_clearTerminal, 0, 1, 1, 1);

        QIcon icon10;
        icon10.addFile(QStringLiteral(":/StartForm/Resources/terminal.png"), QSize(), QIcon::Normal, QIcon::Off);
        TW_OpeationDisp_2->addTab(tw_Terminal, icon10, QString());

        gridLayout_14->addWidget(TW_OpeationDisp_2, 0, 0, 1, 1);

        dockWidget_Terminal->setWidget(dockWidgetContents_8);
        MainWindows->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_Terminal);

        menuBar->addAction(menuNew_Project_File->menuAction());
        menuBar->addAction(menuOption->menuAction());
        menuNew_Project_File->addAction(actionNew_Project_File);
        menuNew_Project_File->addAction(actionOpen_Project);
        menuOption->addAction(action_SetPythonFileHome);
        mainToolBar->addAction(Auto_Test);
        mainToolBar->addAction(ScriptConfigure);
        mainToolBar->addAction(TestPlan);
        mainToolBar->addSeparator();
        mainToolBar->addAction(Test_Instrument);
        mainToolBar->addAction(TestProduct);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Script_Editor_Pycharm);

        retranslateUi(MainWindows);

        tabWidget_main->setCurrentIndex(1);
        toolBox->setCurrentIndex(0);
        TW_OpeationDisp->setCurrentIndex(0);
        TW_OpeationDisp_ErrorInfo->setCurrentIndex(0);
        TW_OpeationDisp_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindows);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindows)
    {
        MainWindows->setWindowTitle(QApplication::translate("MainWindows", "RTA", Q_NULLPTR));
        Auto_Test->setText(QApplication::translate("MainWindows", "Auto Test", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        Auto_Test->setToolTip(QApplication::translate("MainWindows", "Auto Test", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        Auto_Test->setShortcut(QApplication::translate("MainWindows", "Ctrl+R", Q_NULLPTR));
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
        actionNew_Project_File->setText(QApplication::translate("MainWindows", "New Project", Q_NULLPTR));
        actionOpen_Project->setText(QApplication::translate("MainWindows", "Open Project", Q_NULLPTR));
        tabWidget_main->setTabText(tabWidget_main->indexOf(Home), QApplication::translate("MainWindows", "Home", Q_NULLPTR));
        tabWidget_main->setTabText(tabWidget_main->indexOf(Auto_test), QApplication::translate("MainWindows", "Auto Test", Q_NULLPTR));
        menuNew_Project_File->setTitle(QApplication::translate("MainWindows", "File", Q_NULLPTR));
        menuOption->setTitle(QApplication::translate("MainWindows", "Setup", Q_NULLPTR));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindows", "Tool Bar", Q_NULLPTR));
        DW_ToolDock->setWindowTitle(QApplication::translate("MainWindows", "Operation", Q_NULLPTR));
        pushButton_3->setText(QString());
        pushButton_5->setText(QApplication::translate("MainWindows", "PushButton", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindows", "PushButton", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindows", "PushButton", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindows", "PushButton", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(TB_Routerpage), QApplication::translate("MainWindows", "Router Tool", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(TB_ConfigurePage), QApplication::translate("MainWindows", "Configure Tool", Q_NULLPTR));
        DW_Proterty->setWindowTitle(QApplication::translate("MainWindows", "Property", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindows", "Property", Q_NULLPTR));
        dockWidget_Opeartioninfodisp->setWindowTitle(QApplication::translate("MainWindows", "Operation  Information", Q_NULLPTR));
        TW_OpeationDisp->setTabText(TW_OpeationDisp->indexOf(tw_opeartioninfo), QApplication::translate("MainWindows", "Opeartion Info", Q_NULLPTR));
        dockWidget_ErrorInfo->setWindowTitle(QApplication::translate("MainWindows", "Error Info", Q_NULLPTR));
        TW_OpeationDisp_ErrorInfo->setTabText(TW_OpeationDisp_ErrorInfo->indexOf(tw_errorinfo_2), QApplication::translate("MainWindows", "Error Info", Q_NULLPTR));
        dockWidget_Terminal->setWindowTitle(QApplication::translate("MainWindows", "Run Terminal", Q_NULLPTR));
        pushButton_clearTerminal->setText(QString());
        TW_OpeationDisp_2->setTabText(TW_OpeationDisp_2->indexOf(tw_Terminal), QApplication::translate("MainWindows", "Terminal", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindows: public Ui_MainWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWS_H
