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
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
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
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QSplitter *top_splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;
    QPushButton *pushButton_LoadCaseList;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_9;
    QTreeView *CaseFile_treeView;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer;
    QListView *listView;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_run;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_reload;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_infodisp;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_reset;
    QTextBrowser *TB_RunInfodisp;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CaseScriptConfigure)
    {
        if (CaseScriptConfigure->objectName().isEmpty())
            CaseScriptConfigure->setObjectName(QString::fromUtf8("CaseScriptConfigure"));
        CaseScriptConfigure->resize(1166, 644);
        gridLayout = new QGridLayout(CaseScriptConfigure);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        top_splitter = new QSplitter(CaseScriptConfigure);
        top_splitter->setObjectName(QString::fromUtf8("top_splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(top_splitter->sizePolicy().hasHeightForWidth());
        top_splitter->setSizePolicy(sizePolicy);
        top_splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(top_splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(228, 246, 255);"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Arial\";"));

        horizontalLayout->addWidget(checkBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Arial\";"));

        horizontalLayout->addWidget(label);

        pushButton_LoadCaseList = new QPushButton(groupBox_2);
        pushButton_LoadCaseList->setObjectName(QString::fromUtf8("pushButton_LoadCaseList"));
        pushButton_LoadCaseList->setStyleSheet(QString::fromUtf8("selection-color: rgb(255, 0, 127);\n"
"background-color: rgb(228, 246, 255);\n"
"QPushButton{\n"
"outline none\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/load.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_LoadCaseList->setIcon(icon);
        pushButton_LoadCaseList->setIconSize(QSize(32, 32));
        pushButton_LoadCaseList->setFlat(true);

        horizontalLayout->addWidget(pushButton_LoadCaseList);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        CaseFile_treeView = new QTreeView(layoutWidget);
        CaseFile_treeView->setObjectName(QString::fromUtf8("CaseFile_treeView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(5);
        sizePolicy2.setHeightForWidth(CaseFile_treeView->sizePolicy().hasHeightForWidth());
        CaseFile_treeView->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(CaseFile_treeView);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        horizontalLayout_7->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy3);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);

        horizontalLayout_7->addWidget(pushButton_2);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/left(3).png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon3);

        horizontalLayout_8->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/right(6).png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon4);

        horizontalLayout_8->addWidget(pushButton_4);


        verticalLayout_3->addLayout(horizontalLayout_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_9->addLayout(verticalLayout_3);

        listView = new QListView(layoutWidget);
        listView->setObjectName(QString::fromUtf8("listView"));

        horizontalLayout_9->addWidget(listView);

        horizontalLayout_9->setStretch(0, 20);
        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 20);

        verticalLayout_4->addLayout(horizontalLayout_9);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 7);
        top_splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(top_splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy4);
        groupBox->setMinimumSize(QSize(131, 61));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(228, 246, 255);"));
        horizontalLayout_6 = new QHBoxLayout(groupBox);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_run = new QPushButton(groupBox);
        pushButton_run->setObjectName(QString::fromUtf8("pushButton_run"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pushButton_run->sizePolicy().hasHeightForWidth());
        pushButton_run->setSizePolicy(sizePolicy5);
        pushButton_run->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_run->setIcon(icon5);
        pushButton_run->setIconSize(QSize(32, 32));
        pushButton_run->setAutoRepeat(false);
        pushButton_run->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_run);

        pushButton_stop = new QPushButton(groupBox);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        sizePolicy5.setHeightForWidth(pushButton_stop->sizePolicy().hasHeightForWidth());
        pushButton_stop->setSizePolicy(sizePolicy5);
        pushButton_stop->setStyleSheet(QString::fromUtf8(""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_stop->setIcon(icon6);
        pushButton_stop->setIconSize(QSize(32, 32));
        pushButton_stop->setAutoRepeat(false);
        pushButton_stop->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_stop);

        pushButton_reload = new QPushButton(groupBox);
        pushButton_reload->setObjectName(QString::fromUtf8("pushButton_reload"));
        sizePolicy5.setHeightForWidth(pushButton_reload->sizePolicy().hasHeightForWidth());
        pushButton_reload->setSizePolicy(sizePolicy5);
        pushButton_reload->setStyleSheet(QString::fromUtf8(""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_reload->setIcon(icon7);
        pushButton_reload->setIconSize(QSize(32, 32));
        pushButton_reload->setAutoRepeat(false);
        pushButton_reload->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_reload);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_2->addWidget(groupBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_infodisp = new QLabel(layoutWidget1);
        label_infodisp->setObjectName(QString::fromUtf8("label_infodisp"));
        label_infodisp->setFont(font);
        label_infodisp->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));

        horizontalLayout_3->addWidget(label_infodisp);

        horizontalSpacer_2 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_reset = new QPushButton(layoutWidget1);
        pushButton_reset->setObjectName(QString::fromUtf8("pushButton_reset"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pushButton_reset->sizePolicy().hasHeightForWidth());
        pushButton_reset->setSizePolicy(sizePolicy6);
        pushButton_reset->setStyleSheet(QString::fromUtf8(""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/clean up.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_reset->setIcon(icon8);

        horizontalLayout_3->addWidget(pushButton_reset);


        verticalLayout->addLayout(horizontalLayout_3);

        TB_RunInfodisp = new QTextBrowser(layoutWidget1);
        TB_RunInfodisp->setObjectName(QString::fromUtf8("TB_RunInfodisp"));
        TB_RunInfodisp->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 240);"));

        verticalLayout->addWidget(TB_RunInfodisp);


        verticalLayout_2->addLayout(verticalLayout);

        top_splitter->addWidget(layoutWidget1);

        verticalLayout_5->addWidget(top_splitter);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(CaseScriptConfigure);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy7);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout_5->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);


        retranslateUi(CaseScriptConfigure);

        QMetaObject::connectSlotsByName(CaseScriptConfigure);
    } // setupUi

    void retranslateUi(QDialog *CaseScriptConfigure)
    {
        CaseScriptConfigure->setWindowTitle(QApplication::translate("CaseScriptConfigure", "Run Script Configure", nullptr));
        groupBox_2->setTitle(QApplication::translate("CaseScriptConfigure", "Script File Configure", nullptr));
        checkBox->setText(QApplication::translate("CaseScriptConfigure", "function mode", nullptr));
        label->setText(QApplication::translate("CaseScriptConfigure", "Load Project Case", nullptr));
        pushButton_LoadCaseList->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        groupBox->setTitle(QApplication::translate("CaseScriptConfigure", "Operation", nullptr));
        pushButton_run->setText(QString());
#ifndef QT_NO_SHORTCUT
        pushButton_run->setShortcut(QApplication::translate("CaseScriptConfigure", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_stop->setText(QString());
#ifndef QT_NO_SHORTCUT
        pushButton_stop->setShortcut(QApplication::translate("CaseScriptConfigure", "Alt+F5", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_reload->setText(QString());
        label_infodisp->setText(QApplication::translate("CaseScriptConfigure", "Runing info ", nullptr));
        pushButton_reset->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CaseScriptConfigure: public Ui_CaseScriptConfigure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASESCRIPTCONFIGURE_H
