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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RunScript
{
public:
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_infodisp;
    QTextBrowser *TB_RunInfodisp;
    QGroupBox *groupBox;
    QPushButton *pushButton_run;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_reset;

    void setupUi(QDialog *RunScript)
    {
        if (RunScript->objectName().isEmpty())
            RunScript->setObjectName(QStringLiteral("RunScript"));
        RunScript->resize(621, 375);
        splitter = new QSplitter(RunScript);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(10, 20, 571, 331));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_infodisp = new QLabel(layoutWidget);
        label_infodisp->setObjectName(QStringLiteral("label_infodisp"));

        verticalLayout->addWidget(label_infodisp);

        TB_RunInfodisp = new QTextBrowser(layoutWidget);
        TB_RunInfodisp->setObjectName(QStringLiteral("TB_RunInfodisp"));

        verticalLayout->addWidget(TB_RunInfodisp);

        splitter->addWidget(layoutWidget);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(131, 61));
        pushButton_run = new QPushButton(groupBox);
        pushButton_run->setObjectName(QStringLiteral("pushButton_run"));
        pushButton_run->setGeometry(QRect(12, 25, 31, 31));
        sizePolicy.setHeightForWidth(pushButton_run->sizePolicy().hasHeightForWidth());
        pushButton_run->setSizePolicy(sizePolicy);
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
        sizePolicy.setHeightForWidth(pushButton_stop->sizePolicy().hasHeightForWidth());
        pushButton_stop->setSizePolicy(sizePolicy);
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
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_reset->sizePolicy().hasHeightForWidth());
        pushButton_reset->setSizePolicy(sizePolicy1);
        pushButton_reset->setStyleSheet(QStringLiteral(""));
        splitter->addWidget(groupBox);

        retranslateUi(RunScript);

        QMetaObject::connectSlotsByName(RunScript);
    } // setupUi

    void retranslateUi(QDialog *RunScript)
    {
        RunScript->setWindowTitle(QApplication::translate("RunScript", "RunScript", Q_NULLPTR));
        label_infodisp->setText(QApplication::translate("RunScript", "Runing info", Q_NULLPTR));
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
    } // retranslateUi

};

namespace Ui {
    class RunScript: public Ui_RunScript {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNSCRIPT_H
