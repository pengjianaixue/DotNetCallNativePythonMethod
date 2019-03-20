/********************************************************************************
** Form generated from reading UI file 'PyRunner.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PYRUNNER_H
#define UI_PYRUNNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PyRunnerTestClass
{
public:
    QWidget *centralWidget;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_infodisp;
    QTextBrowser *TB_RunInfodisp;
    QGroupBox *groupBox;
    QPushButton *pushButton_run;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_reset;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PyRunnerTestClass)
    {
        if (PyRunnerTestClass->objectName().isEmpty())
            PyRunnerTestClass->setObjectName(QStringLiteral("PyRunnerTestClass"));
        PyRunnerTestClass->resize(600, 400);
        centralWidget = new QWidget(PyRunnerTestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(10, 10, 571, 331));
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
        pushButton_run->setGeometry(QRect(10, 20, 31, 31));
        sizePolicy.setHeightForWidth(pushButton_run->sizePolicy().hasHeightForWidth());
        pushButton_run->setSizePolicy(sizePolicy);
        pushButton_run->setStyleSheet(QStringLiteral("border-image: url(:/RTA/PyRunner/Resources/start.png);"));
        pushButton_stop = new QPushButton(groupBox);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(50, 20, 31, 31));
        sizePolicy.setHeightForWidth(pushButton_stop->sizePolicy().hasHeightForWidth());
        pushButton_stop->setSizePolicy(sizePolicy);
        pushButton_stop->setStyleSheet(QStringLiteral("border-image: url(:/RTA/PyRunner/Resources/stop.png);"));
        pushButton_reset = new QPushButton(groupBox);
        pushButton_reset->setObjectName(QStringLiteral("pushButton_reset"));
        pushButton_reset->setGeometry(QRect(90, 20, 31, 31));
        sizePolicy.setHeightForWidth(pushButton_reset->sizePolicy().hasHeightForWidth());
        pushButton_reset->setSizePolicy(sizePolicy);
        splitter->addWidget(groupBox);
        PyRunnerTestClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PyRunnerTestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        PyRunnerTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PyRunnerTestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PyRunnerTestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PyRunnerTestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PyRunnerTestClass->setStatusBar(statusBar);

        retranslateUi(PyRunnerTestClass);

        QMetaObject::connectSlotsByName(PyRunnerTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *PyRunnerTestClass)
    {
        PyRunnerTestClass->setWindowTitle(QApplication::translate("PyRunnerTestClass", "PyRunnerTest", Q_NULLPTR));
        label_infodisp->setText(QApplication::translate("PyRunnerTestClass", "Runing info", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("PyRunnerTestClass", "Operation", Q_NULLPTR));
        pushButton_run->setText(QString());
        pushButton_stop->setText(QString());
        pushButton_reset->setText(QApplication::translate("PyRunnerTestClass", "reset", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PyRunnerTestClass: public Ui_PyRunnerTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PYRUNNER_H
