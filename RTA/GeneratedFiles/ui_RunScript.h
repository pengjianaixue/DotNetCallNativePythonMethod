/********************************************************************************
** Form generated from reading UI file 'RunScript.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNSCRIPT_H
#define UI_RUNSCRIPT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RunScript
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QTreeView *treeView;
    QWidget *layoutWidget2;
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

    void setupUi(QDialog *RunScript)
    {
        if (RunScript->objectName().isEmpty())
            RunScript->setObjectName(QString::fromUtf8("RunScript"));
        RunScript->resize(750, 521);
        gridLayout = new QGridLayout(RunScript);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        splitter = new QSplitter(RunScript);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
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
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 311, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(layoutWidget1);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(comboBox);


        verticalLayout_3->addWidget(groupBox_2);

        treeView = new QTreeView(layoutWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(5);
        sizePolicy3.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(treeView);

        splitter->addWidget(layoutWidget);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget2);
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_run->setIcon(icon);
        pushButton_run->setIconSize(QSize(32, 32));
        pushButton_run->setAutoRepeat(false);
        pushButton_run->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_run);

        pushButton_stop = new QPushButton(groupBox);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        sizePolicy5.setHeightForWidth(pushButton_stop->sizePolicy().hasHeightForWidth());
        pushButton_stop->setSizePolicy(sizePolicy5);
        pushButton_stop->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_stop->setIcon(icon1);
        pushButton_stop->setIconSize(QSize(32, 32));
        pushButton_stop->setAutoRepeat(false);
        pushButton_stop->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_stop);

        pushButton_reload = new QPushButton(groupBox);
        pushButton_reload->setObjectName(QString::fromUtf8("pushButton_reload"));
        sizePolicy5.setHeightForWidth(pushButton_reload->sizePolicy().hasHeightForWidth());
        pushButton_reload->setSizePolicy(sizePolicy5);
        pushButton_reload->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_reload->setIcon(icon2);
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
        label_infodisp = new QLabel(layoutWidget2);
        label_infodisp->setObjectName(QString::fromUtf8("label_infodisp"));
        label_infodisp->setFont(font);
        label_infodisp->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));

        horizontalLayout_3->addWidget(label_infodisp);

        horizontalSpacer_2 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_reset = new QPushButton(layoutWidget2);
        pushButton_reset->setObjectName(QString::fromUtf8("pushButton_reset"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pushButton_reset->sizePolicy().hasHeightForWidth());
        pushButton_reset->setSizePolicy(sizePolicy6);
        pushButton_reset->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/RTA/PyRunner/Resources/clean up.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_reset->setIcon(icon3);

        horizontalLayout_3->addWidget(pushButton_reset);


        verticalLayout->addLayout(horizontalLayout_3);

        TB_RunInfodisp = new QTextBrowser(layoutWidget2);
        TB_RunInfodisp->setObjectName(QString::fromUtf8("TB_RunInfodisp"));
        TB_RunInfodisp->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 240);"));

        verticalLayout->addWidget(TB_RunInfodisp);


        verticalLayout_2->addLayout(verticalLayout);

        splitter->addWidget(layoutWidget2);

        verticalLayout_4->addWidget(splitter);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(RunScript);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        sizePolicy6.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy6);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout_4->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);


        retranslateUi(RunScript);

        QMetaObject::connectSlotsByName(RunScript);
    } // setupUi

    void retranslateUi(QDialog *RunScript)
    {
        RunScript->setWindowTitle(QApplication::translate("RunScript", "Run Script Configure", nullptr));
        groupBox_2->setTitle(QApplication::translate("RunScript", "Script File Configure", nullptr));
        label->setText(QApplication::translate("RunScript", "TextLabel", nullptr));
        groupBox->setTitle(QApplication::translate("RunScript", "Operation", nullptr));
        pushButton_run->setText(QString());
#ifndef QT_NO_SHORTCUT
        pushButton_run->setShortcut(QApplication::translate("RunScript", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_stop->setText(QString());
#ifndef QT_NO_SHORTCUT
        pushButton_stop->setShortcut(QApplication::translate("RunScript", "Alt+F5", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_reload->setText(QString());
        label_infodisp->setText(QApplication::translate("RunScript", "Runing info ", nullptr));
        pushButton_reset->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RunScript: public Ui_RunScript {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNSCRIPT_H
