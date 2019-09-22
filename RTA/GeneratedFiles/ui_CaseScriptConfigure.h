/********************************************************************************
** Form generated from reading UI file 'CaseScriptConfigure.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASESCRIPTCONFIGURE_H
#define UI_CASESCRIPTCONFIGURE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
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
    QGridLayout *gridLayout_8;
    QSplitter *splitter_loadandinfor;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_caseload;
    QGridLayout *gridLayout_6;
    QRadioButton *radioButton_PerformanceMode;
    QPushButton *pushButton_LoadCaseList;
    QSpacerItem *horizontalSpacer_2;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_caseFile_tree;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_CaseFileGroup;
    QLabel *label_case_tree;
    QTreeView *CaseFile_treeView;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_case_select_list;
    QGridLayout *gridLayout_5;
    QLabel *label_caseList;
    QSpacerItem *horizontalSpacer_CaseSelectList;
    QTreeView *Case_exce_treeView;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_8;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_execute_group_list;
    QGridLayout *gridLayout_4;
    QLabel *label_caseList_2;
    QSpacerItem *horizontalSpacer_CaseExecList;
    QListView *listView_Exec_list;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_caseinformation;
    QGridLayout *gridLayout_2;
    QLabel *label_case_detail;
    QSpacerItem *horizontalSpacer_5;
    QTextBrowser *case_detail_info_textBrowser;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ok;

    void setupUi(QDialog *CaseScriptConfigure)
    {
        if (CaseScriptConfigure->objectName().isEmpty())
            CaseScriptConfigure->setObjectName(QString::fromUtf8("CaseScriptConfigure"));
        CaseScriptConfigure->resize(1020, 826);
        action_AddToExeCutionList = new QAction(CaseScriptConfigure);
        action_AddToExeCutionList->setObjectName(QString::fromUtf8("action_AddToExeCutionList"));
        gridLayout_8 = new QGridLayout(CaseScriptConfigure);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        splitter_loadandinfor = new QSplitter(CaseScriptConfigure);
        splitter_loadandinfor->setObjectName(QString::fromUtf8("splitter_loadandinfor"));
        splitter_loadandinfor->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(splitter_loadandinfor);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        frame_caseload = new QFrame(groupBox);
        frame_caseload->setObjectName(QString::fromUtf8("frame_caseload"));
        frame_caseload->setFrameShape(QFrame::NoFrame);
        frame_caseload->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_caseload);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        radioButton_PerformanceMode = new QRadioButton(frame_caseload);
        radioButton_PerformanceMode->setObjectName(QString::fromUtf8("radioButton_PerformanceMode"));
        radioButton_PerformanceMode->setStyleSheet(QString::fromUtf8("font: 75 10pt \"Microsoft YaHei\";"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/performance.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_PerformanceMode->setIcon(icon);

        gridLayout_6->addWidget(radioButton_PerformanceMode, 0, 0, 1, 1);

        pushButton_LoadCaseList = new QPushButton(frame_caseload);
        pushButton_LoadCaseList->setObjectName(QString::fromUtf8("pushButton_LoadCaseList"));
        pushButton_LoadCaseList->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(0, 170, 127);\n"
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
        icon1.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_LoadCaseList->setIcon(icon1);
        pushButton_LoadCaseList->setIconSize(QSize(32, 32));
        pushButton_LoadCaseList->setFlat(true);

        gridLayout_6->addWidget(pushButton_LoadCaseList, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(710, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        verticalLayout_6->addWidget(frame_caseload);

        splitter_2 = new QSplitter(groupBox);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_caseFile_tree = new QFrame(layoutWidget);
        frame_caseFile_tree->setObjectName(QString::fromUtf8("frame_caseFile_tree"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_caseFile_tree->sizePolicy().hasHeightForWidth());
        frame_caseFile_tree->setSizePolicy(sizePolicy);
        frame_caseFile_tree->setStyleSheet(QString::fromUtf8(""));
        frame_caseFile_tree->setFrameShape(QFrame::NoFrame);
        frame_caseFile_tree->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_caseFile_tree);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_CaseFileGroup = new QSpacerItem(230, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_CaseFileGroup, 0, 1, 1, 1);

        label_case_tree = new QLabel(frame_caseFile_tree);
        label_case_tree->setObjectName(QString::fromUtf8("label_case_tree"));
        sizePolicy.setHeightForWidth(label_case_tree->sizePolicy().hasHeightForWidth());
        label_case_tree->setSizePolicy(sizePolicy);
        label_case_tree->setMinimumSize(QSize(20, 20));
        label_case_tree->setStyleSheet(QString::fromUtf8("image: url(:/RTA/PyRunner/Resources/testcase-group.png);"));

        gridLayout->addWidget(label_case_tree, 0, 0, 1, 1);


        verticalLayout_3->addWidget(frame_caseFile_tree);

        CaseFile_treeView = new QTreeView(layoutWidget);
        CaseFile_treeView->setObjectName(QString::fromUtf8("CaseFile_treeView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(5);
        sizePolicy1.setHeightForWidth(CaseFile_treeView->sizePolicy().hasHeightForWidth());
        CaseFile_treeView->setSizePolicy(sizePolicy1);
        CaseFile_treeView->setMinimumSize(QSize(30, 0));

        verticalLayout_3->addWidget(CaseFile_treeView);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);

        horizontalLayout_5->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon3);

        horizontalLayout_5->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/leftArr.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon4);

        horizontalLayout_6->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget1);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/rightArr.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon5);

        horizontalLayout_6->addWidget(pushButton_4);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame_case_select_list = new QFrame(layoutWidget1);
        frame_case_select_list->setObjectName(QString::fromUtf8("frame_case_select_list"));
        frame_case_select_list->setFrameShape(QFrame::NoFrame);
        frame_case_select_list->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_case_select_list);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_caseList = new QLabel(frame_case_select_list);
        label_caseList->setObjectName(QString::fromUtf8("label_caseList"));
        sizePolicy.setHeightForWidth(label_caseList->sizePolicy().hasHeightForWidth());
        label_caseList->setSizePolicy(sizePolicy);
        label_caseList->setMinimumSize(QSize(20, 20));
        label_caseList->setStyleSheet(QString::fromUtf8("image: url(:/RTA/PyRunner/Resources/stream list.png);"));

        gridLayout_5->addWidget(label_caseList, 0, 0, 1, 1);

        horizontalSpacer_CaseSelectList = new QSpacerItem(237, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_CaseSelectList, 0, 1, 1, 1);


        verticalLayout_5->addWidget(frame_case_select_list);

        Case_exce_treeView = new QTreeView(layoutWidget1);
        Case_exce_treeView->setObjectName(QString::fromUtf8("Case_exce_treeView"));

        verticalLayout_5->addWidget(Case_exce_treeView);


        horizontalLayout->addLayout(verticalLayout_5);

        splitter->addWidget(layoutWidget1);
        splitter_2->addWidget(splitter);
        layoutWidget2 = new QWidget(splitter_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));

        verticalLayout_7->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pushButton_8 = new QPushButton(layoutWidget2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setIcon(icon5);

        horizontalLayout_10->addWidget(pushButton_8);


        verticalLayout_7->addLayout(horizontalLayout_10);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_4);


        horizontalLayout_3->addLayout(verticalLayout_7);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        frame_execute_group_list = new QFrame(layoutWidget2);
        frame_execute_group_list->setObjectName(QString::fromUtf8("frame_execute_group_list"));
        frame_execute_group_list->setFrameShape(QFrame::NoFrame);
        frame_execute_group_list->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_execute_group_list);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_caseList_2 = new QLabel(frame_execute_group_list);
        label_caseList_2->setObjectName(QString::fromUtf8("label_caseList_2"));
        sizePolicy.setHeightForWidth(label_caseList_2->sizePolicy().hasHeightForWidth());
        label_caseList_2->setSizePolicy(sizePolicy);
        label_caseList_2->setMinimumSize(QSize(20, 20));
        label_caseList_2->setStyleSheet(QString::fromUtf8("image: url(:/RTA/PyRunner/Resources/ExecList.png);"));

        gridLayout_4->addWidget(label_caseList_2, 0, 0, 1, 1);

        horizontalSpacer_CaseExecList = new QSpacerItem(236, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_CaseExecList, 0, 1, 1, 1);


        verticalLayout_4->addWidget(frame_execute_group_list);

        listView_Exec_list = new QListView(layoutWidget2);
        listView_Exec_list->setObjectName(QString::fromUtf8("listView_Exec_list"));

        verticalLayout_4->addWidget(listView_Exec_list);


        horizontalLayout_3->addLayout(verticalLayout_4);

        splitter_2->addWidget(layoutWidget2);

        verticalLayout_6->addWidget(splitter_2);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 9);

        gridLayout_7->addLayout(verticalLayout_6, 0, 0, 1, 1);

        splitter_loadandinfor->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter_loadandinfor);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_caseinformation = new QFrame(groupBox_2);
        frame_caseinformation->setObjectName(QString::fromUtf8("frame_caseinformation"));
        frame_caseinformation->setFrameShape(QFrame::NoFrame);
        frame_caseinformation->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_caseinformation);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_case_detail = new QLabel(frame_caseinformation);
        label_case_detail->setObjectName(QString::fromUtf8("label_case_detail"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_case_detail->sizePolicy().hasHeightForWidth());
        label_case_detail->setSizePolicy(sizePolicy3);
        label_case_detail->setMinimumSize(QSize(50, 0));
        label_case_detail->setStyleSheet(QString::fromUtf8("image: url(:/RTA/PyRunner/Resources/detail-info.png);\n"
""));
        label_case_detail->setTextFormat(Qt::PlainText);
        label_case_detail->setWordWrap(false);

        gridLayout_2->addWidget(label_case_detail, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(901, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 1, 1, 1);


        verticalLayout_2->addWidget(frame_caseinformation);

        case_detail_info_textBrowser = new QTextBrowser(groupBox_2);
        case_detail_info_textBrowser->setObjectName(QString::fromUtf8("case_detail_info_textBrowser"));

        verticalLayout_2->addWidget(case_detail_info_textBrowser);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_ok = new QPushButton(groupBox_2);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));

        horizontalLayout_2->addWidget(pushButton_ok);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 8);
        verticalLayout_2->setStretch(2, 1);

        gridLayout_3->addLayout(verticalLayout_2, 0, 0, 1, 1);

        splitter_loadandinfor->addWidget(groupBox_2);

        gridLayout_8->addWidget(splitter_loadandinfor, 0, 0, 1, 1);


        retranslateUi(CaseScriptConfigure);

        QMetaObject::connectSlotsByName(CaseScriptConfigure);
    } // setupUi

    void retranslateUi(QDialog *CaseScriptConfigure)
    {
        CaseScriptConfigure->setWindowTitle(QApplication::translate("CaseScriptConfigure", "Case  Configure", nullptr));
        action_AddToExeCutionList->setText(QApplication::translate("CaseScriptConfigure", "AddToExeCutionList", nullptr));
        groupBox->setTitle(QApplication::translate("CaseScriptConfigure", "Case Load", nullptr));
        radioButton_PerformanceMode->setText(QApplication::translate("CaseScriptConfigure", "Performance Case Mode", nullptr));
#ifndef QT_NO_WHATSTHIS
        pushButton_LoadCaseList->setWhatsThis(QApplication::translate("CaseScriptConfigure", "<html><head/><body><p>Load or refresh the case list</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_LoadCaseList->setText(QString());
#ifndef QT_NO_WHATSTHIS
        label_case_tree->setWhatsThis(QApplication::translate("CaseScriptConfigure", "Case  File Group Form", nullptr));
#endif // QT_NO_WHATSTHIS
        label_case_tree->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
#ifndef QT_NO_WHATSTHIS
        label_caseList->setWhatsThis(QApplication::translate("CaseScriptConfigure", "Case List Form", nullptr));
#endif // QT_NO_WHATSTHIS
        label_caseList->setText(QString());
        pushButton_8->setText(QString());
#ifndef QT_NO_WHATSTHIS
        label_caseList_2->setWhatsThis(QApplication::translate("CaseScriptConfigure", "Case Execute  Group Item List", nullptr));
#endif // QT_NO_WHATSTHIS
        label_caseList_2->setText(QString());
        groupBox_2->setTitle(QApplication::translate("CaseScriptConfigure", "Case Information", nullptr));
        label_case_detail->setText(QString());
        pushButton_ok->setText(QApplication::translate("CaseScriptConfigure", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CaseScriptConfigure: public Ui_CaseScriptConfigure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASESCRIPTCONFIGURE_H
