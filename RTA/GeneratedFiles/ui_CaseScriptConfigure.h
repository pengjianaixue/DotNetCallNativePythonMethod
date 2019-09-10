/********************************************************************************
** Form generated from reading UI file 'CaseScriptConfigure.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASESCRIPTCONFIGURE_H
#define UI_CASESCRIPTCONFIGURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CaseScriptConfigure
{
public:
    QAction *action_AddToExeCutionList;
    QVBoxLayout *verticalLayout_9;
    QSplitter *splitter_loadandinfor;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *radioButton_PerformanceMode;
    QPushButton *pushButton_LoadCaseList;
    QSpacerItem *horizontalSpacer_2;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_case_tree;
    QSpacerItem *horizontalSpacer_CaseFileGroup;
    QTreeView *CaseFile_treeView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_caseList;
    QSpacerItem *horizontalSpacer_CaseSelectList;
    QTreeView *Case_exce_treeView;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_8;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_caseList_2;
    QSpacerItem *horizontalSpacer_CaseExecList;
    QListView *listView_Exec_list;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_case_detail;
    QSpacerItem *horizontalSpacer_5;
    QTextBrowser *case_detail_info_textBrowser;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ok;

    void setupUi(QDialog *CaseScriptConfigure)
    {
        if (CaseScriptConfigure->objectName().isEmpty())
            CaseScriptConfigure->setObjectName(QStringLiteral("CaseScriptConfigure"));
        CaseScriptConfigure->resize(1020, 826);
        action_AddToExeCutionList = new QAction(CaseScriptConfigure);
        action_AddToExeCutionList->setObjectName(QStringLiteral("action_AddToExeCutionList"));
        verticalLayout_9 = new QVBoxLayout(CaseScriptConfigure);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        splitter_loadandinfor = new QSplitter(CaseScriptConfigure);
        splitter_loadandinfor->setObjectName(QStringLiteral("splitter_loadandinfor"));
        splitter_loadandinfor->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(splitter_loadandinfor);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_10 = new QVBoxLayout(groupBox);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        radioButton_PerformanceMode = new QRadioButton(groupBox);
        radioButton_PerformanceMode->setObjectName(QStringLiteral("radioButton_PerformanceMode"));
        radioButton_PerformanceMode->setStyleSheet(QStringLiteral("font: 75 10pt \"Microsoft YaHei\";"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/RTA/PyRunner/Resources/performance.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_PerformanceMode->setIcon(icon);

        horizontalLayout_8->addWidget(radioButton_PerformanceMode);

        pushButton_LoadCaseList = new QPushButton(groupBox);
        pushButton_LoadCaseList->setObjectName(QStringLiteral("pushButton_LoadCaseList"));
        pushButton_LoadCaseList->setStyleSheet(QLatin1String("selection-background-color: rgb(0, 170, 127);\n"
"selection-color: rgb(31, 95, 95);\n"
"background-color: rgb(228, 246, 255);\n"
"QPushButton{\n"
"	outline none\n"
"};\n"
"focus {\n"
"border-width:2px;\n"
"border-color:rgb(170, 170, 255);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/RTA/PyRunner/Resources/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_LoadCaseList->setIcon(icon1);
        pushButton_LoadCaseList->setIconSize(QSize(32, 32));
        pushButton_LoadCaseList->setFlat(true);

        horizontalLayout_8->addWidget(pushButton_LoadCaseList);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        verticalLayout_8->addLayout(horizontalLayout_8);

        splitter_2 = new QSplitter(groupBox);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_case_tree = new QLabel(layoutWidget);
        label_case_tree->setObjectName(QStringLiteral("label_case_tree"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_case_tree->sizePolicy().hasHeightForWidth());
        label_case_tree->setSizePolicy(sizePolicy);
        label_case_tree->setMinimumSize(QSize(20, 20));
        label_case_tree->setStyleSheet(QStringLiteral("image: url(:/RTA/PyRunner/Resources/testcase-group.png);"));

        horizontalLayout_3->addWidget(label_case_tree);

        horizontalSpacer_CaseFileGroup = new QSpacerItem(188, 27, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_CaseFileGroup);


        verticalLayout_3->addLayout(horizontalLayout_3);

        CaseFile_treeView = new QTreeView(layoutWidget);
        CaseFile_treeView->setObjectName(QStringLiteral("CaseFile_treeView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(5);
        sizePolicy1.setHeightForWidth(CaseFile_treeView->sizePolicy().hasHeightForWidth());
        CaseFile_treeView->setSizePolicy(sizePolicy1);
        CaseFile_treeView->setMinimumSize(QSize(30, 0));

        verticalLayout_3->addWidget(CaseFile_treeView);

        splitter->addWidget(layoutWidget);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_11 = new QHBoxLayout(widget);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/RTA/PyRunner/Resources/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);

        horizontalLayout_5->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/RTA/PyRunner/Resources/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon3);

        horizontalLayout_5->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/RTA/PyRunner/Resources/leftArr.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon4);

        horizontalLayout_6->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/RTA/PyRunner/Resources/rightArr.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon5);

        horizontalLayout_6->addWidget(pushButton_4);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_11->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_caseList = new QLabel(widget);
        label_caseList->setObjectName(QStringLiteral("label_caseList"));
        sizePolicy.setHeightForWidth(label_caseList->sizePolicy().hasHeightForWidth());
        label_caseList->setSizePolicy(sizePolicy);
        label_caseList->setMinimumSize(QSize(20, 20));
        label_caseList->setStyleSheet(QStringLiteral("image: url(:/RTA/PyRunner/Resources/case-list.png);"));

        horizontalLayout->addWidget(label_caseList);

        horizontalSpacer_CaseSelectList = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_CaseSelectList);


        verticalLayout_2->addLayout(horizontalLayout);

        Case_exce_treeView = new QTreeView(widget);
        Case_exce_treeView->setObjectName(QStringLiteral("Case_exce_treeView"));

        verticalLayout_2->addWidget(Case_exce_treeView);


        horizontalLayout_11->addLayout(verticalLayout_2);

        splitter->addWidget(widget);
        splitter_2->addWidget(splitter);
        widget1 = new QWidget(splitter_2);
        widget1->setObjectName(QStringLiteral("widget1"));
        horizontalLayout_12 = new QHBoxLayout(widget1);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));

        verticalLayout_7->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        pushButton_8 = new QPushButton(widget1);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setIcon(icon5);

        horizontalLayout_10->addWidget(pushButton_8);


        verticalLayout_7->addLayout(horizontalLayout_10);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_4);


        horizontalLayout_12->addLayout(verticalLayout_7);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_caseList_2 = new QLabel(widget1);
        label_caseList_2->setObjectName(QStringLiteral("label_caseList_2"));
        sizePolicy.setHeightForWidth(label_caseList_2->sizePolicy().hasHeightForWidth());
        label_caseList_2->setSizePolicy(sizePolicy);
        label_caseList_2->setMinimumSize(QSize(20, 20));
        label_caseList_2->setStyleSheet(QStringLiteral("image: url(:/RTA/PyRunner/Resources/ExecList.png);"));

        horizontalLayout_7->addWidget(label_caseList_2);

        horizontalSpacer_CaseExecList = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_CaseExecList);


        verticalLayout_4->addLayout(horizontalLayout_7);

        listView_Exec_list = new QListView(widget1);
        listView_Exec_list->setObjectName(QStringLiteral("listView_Exec_list"));

        verticalLayout_4->addWidget(listView_Exec_list);


        horizontalLayout_12->addLayout(verticalLayout_4);

        splitter_2->addWidget(widget1);

        verticalLayout_8->addWidget(splitter_2);

        verticalLayout_8->setStretch(0, 1);
        verticalLayout_8->setStretch(1, 9);

        verticalLayout_10->addLayout(verticalLayout_8);

        splitter_loadandinfor->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter_loadandinfor);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_case_detail = new QLabel(groupBox_2);
        label_case_detail->setObjectName(QStringLiteral("label_case_detail"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_case_detail->sizePolicy().hasHeightForWidth());
        label_case_detail->setSizePolicy(sizePolicy3);
        label_case_detail->setMinimumSize(QSize(50, 0));
        label_case_detail->setStyleSheet(QLatin1String("image: url(:/RTA/PyRunner/Resources/detail-info.png);\n"
""));
        label_case_detail->setTextFormat(Qt::PlainText);
        label_case_detail->setWordWrap(false);

        horizontalLayout_4->addWidget(label_case_detail);

        horizontalSpacer_5 = new QSpacerItem(438, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(horizontalLayout_4);

        case_detail_info_textBrowser = new QTextBrowser(groupBox_2);
        case_detail_info_textBrowser->setObjectName(QStringLiteral("case_detail_info_textBrowser"));

        verticalLayout_5->addWidget(case_detail_info_textBrowser);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_ok = new QPushButton(groupBox_2);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));

        horizontalLayout_2->addWidget(pushButton_ok);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout_6->addLayout(verticalLayout_5);

        splitter_loadandinfor->addWidget(groupBox_2);

        verticalLayout_9->addWidget(splitter_loadandinfor);


        retranslateUi(CaseScriptConfigure);

        QMetaObject::connectSlotsByName(CaseScriptConfigure);
    } // setupUi

    void retranslateUi(QDialog *CaseScriptConfigure)
    {
        CaseScriptConfigure->setWindowTitle(QApplication::translate("CaseScriptConfigure", "Case  Configure", Q_NULLPTR));
        action_AddToExeCutionList->setText(QApplication::translate("CaseScriptConfigure", "AddToExeCutionList", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("CaseScriptConfigure", "Case Load", Q_NULLPTR));
        radioButton_PerformanceMode->setText(QApplication::translate("CaseScriptConfigure", "Performance Case Mode", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        pushButton_LoadCaseList->setWhatsThis(QApplication::translate("CaseScriptConfigure", "<html><head/><body><p>Load or refresh the case list</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        pushButton_LoadCaseList->setText(QString());
#ifndef QT_NO_WHATSTHIS
        label_case_tree->setWhatsThis(QApplication::translate("CaseScriptConfigure", "Case  File Group Form", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        label_case_tree->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
#ifndef QT_NO_WHATSTHIS
        label_caseList->setWhatsThis(QApplication::translate("CaseScriptConfigure", "Case List Form", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        label_caseList->setText(QString());
        pushButton_8->setText(QString());
#ifndef QT_NO_WHATSTHIS
        label_caseList_2->setWhatsThis(QApplication::translate("CaseScriptConfigure", "Case Execute  Group Item List", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        label_caseList_2->setText(QString());
        groupBox_2->setTitle(QApplication::translate("CaseScriptConfigure", "Case Information", Q_NULLPTR));
        label_case_detail->setText(QString());
        pushButton_ok->setText(QApplication::translate("CaseScriptConfigure", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CaseScriptConfigure: public Ui_CaseScriptConfigure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASESCRIPTCONFIGURE_H
