/********************************************************************************
** Form generated from reading UI file 'RunScript.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNSCRIPT_H
#define UI_RUNSCRIPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
    QPushButton *pushButton_run;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_reset;
    QVBoxLayout *verticalLayout;
    QLabel *label_infodisp;
    QTextBrowser *TB_RunInfodisp;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RunScript)
    {
        if (RunScript->objectName().isEmpty())
            RunScript->setObjectName(QStringLiteral("RunScript"));
        RunScript->resize(750, 521);
        gridLayout = new QGridLayout(RunScript);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        splitter = new QSplitter(RunScript);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
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
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 311, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(layoutWidget1);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(comboBox);


        verticalLayout_3->addWidget(groupBox_2);

        treeView = new QTreeView(layoutWidget);
        treeView->setObjectName(QStringLiteral("treeView"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(5);
        sizePolicy3.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(treeView);

        splitter->addWidget(layoutWidget);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
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
        groupBox->setStyleSheet(QStringLiteral("background-color: rgb(228, 246, 255);"));
        pushButton_run = new QPushButton(groupBox);
        pushButton_run->setObjectName(QStringLiteral("pushButton_run"));
        pushButton_run->setGeometry(QRect(12, 25, 31, 31));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pushButton_run->sizePolicy().hasHeightForWidth());
        pushButton_run->setSizePolicy(sizePolicy5);
        pushButton_run->setStyleSheet(QLatin1String("border-image: url(:/RTA/PyRunner/Resources/start.png);\n"
"QpushButton:{\n"
"							width:20px;\n"
"							height:20px\n"
"						}\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/RTA/PyRunner/Resources/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_run->setIcon(icon);
        pushButton_run->setIconSize(QSize(32, 32));
        pushButton_stop = new QPushButton(groupBox);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(54, 21, 44, 40));
        sizePolicy5.setHeightForWidth(pushButton_stop->sizePolicy().hasHeightForWidth());
        pushButton_stop->setSizePolicy(sizePolicy5);
        pushButton_stop->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/RTA/PyRunner/Resources/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_stop->setIcon(icon1);
        pushButton_stop->setIconSize(QSize(32, 32));
        pushButton_stop->setAutoRepeat(true);
        pushButton_stop->setFlat(true);
        pushButton_reset = new QPushButton(groupBox);
        pushButton_reset->setObjectName(QStringLiteral("pushButton_reset"));
        pushButton_reset->setGeometry(QRect(100, 30, 75, 23));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pushButton_reset->sizePolicy().hasHeightForWidth());
        pushButton_reset->setSizePolicy(sizePolicy6);
        pushButton_reset->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(groupBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_infodisp = new QLabel(layoutWidget2);
        label_infodisp->setObjectName(QStringLiteral("label_infodisp"));
        label_infodisp->setFont(font);
        label_infodisp->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));

        verticalLayout->addWidget(label_infodisp);

        TB_RunInfodisp = new QTextBrowser(layoutWidget2);
        TB_RunInfodisp->setObjectName(QStringLiteral("TB_RunInfodisp"));
        TB_RunInfodisp->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 240);"));

        verticalLayout->addWidget(TB_RunInfodisp);


        verticalLayout_2->addLayout(verticalLayout);

        splitter->addWidget(layoutWidget2);

        verticalLayout_4->addWidget(splitter);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(328, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(RunScript);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        sizePolicy2.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy2);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout_4->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);


        retranslateUi(RunScript);

        QMetaObject::connectSlotsByName(RunScript);
    } // setupUi

    void retranslateUi(QDialog *RunScript)
    {
        RunScript->setWindowTitle(QApplication::translate("RunScript", "Run Script Configure", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("RunScript", "Script File Configure", Q_NULLPTR));
        label->setText(QApplication::translate("RunScript", "TextLabel", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("RunScript", "Operation", Q_NULLPTR));
        pushButton_run->setText(QString());
#ifndef QT_NO_SHORTCUT
        pushButton_run->setShortcut(QApplication::translate("RunScript", "F5", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        pushButton_stop->setText(QString());
#ifndef QT_NO_SHORTCUT
        pushButton_stop->setShortcut(QApplication::translate("RunScript", "Alt+F5", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        pushButton_reset->setText(QApplication::translate("RunScript", "reset", Q_NULLPTR));
        label_infodisp->setText(QApplication::translate("RunScript", "Runing info ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RunScript: public Ui_RunScript {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNSCRIPT_H
