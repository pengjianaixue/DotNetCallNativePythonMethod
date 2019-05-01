/********************************************************************************
** Form generated from reading UI file 'CaseandEditorhome.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASEANDEDITORHOME_H
#define UI_CASEANDEDITORHOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CaseandEditorhome
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *LE_ProjectPath;
    QLineEdit *LE_PycharmPath;
    QVBoxLayout *verticalLayout_3;
    QPushButton *PB_ProjectPath;
    QPushButton *PB_PycharmPath;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CaseandEditorhome)
    {
        if (CaseandEditorhome->objectName().isEmpty())
            CaseandEditorhome->setObjectName(QStringLiteral("CaseandEditorhome"));
        CaseandEditorhome->resize(410, 181);
        gridLayout = new QGridLayout(CaseandEditorhome);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(CaseandEditorhome);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(CaseandEditorhome);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        LE_ProjectPath = new QLineEdit(CaseandEditorhome);
        LE_ProjectPath->setObjectName(QStringLiteral("LE_ProjectPath"));

        verticalLayout_2->addWidget(LE_ProjectPath);

        LE_PycharmPath = new QLineEdit(CaseandEditorhome);
        LE_PycharmPath->setObjectName(QStringLiteral("LE_PycharmPath"));

        verticalLayout_2->addWidget(LE_PycharmPath);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        PB_ProjectPath = new QPushButton(CaseandEditorhome);
        PB_ProjectPath->setObjectName(QStringLiteral("PB_ProjectPath"));
        PB_ProjectPath->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/StartForm/Resources/opendir.png"), QSize(), QIcon::Normal, QIcon::Off);
        PB_ProjectPath->setIcon(icon);

        verticalLayout_3->addWidget(PB_ProjectPath);

        PB_PycharmPath = new QPushButton(CaseandEditorhome);
        PB_PycharmPath->setObjectName(QStringLiteral("PB_PycharmPath"));
        PB_PycharmPath->setStyleSheet(QStringLiteral(""));
        PB_PycharmPath->setIcon(icon);

        verticalLayout_3->addWidget(PB_PycharmPath);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(CaseandEditorhome);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(CaseandEditorhome);
        QObject::connect(buttonBox, SIGNAL(rejected()), CaseandEditorhome, SLOT(close()));

        QMetaObject::connectSlotsByName(CaseandEditorhome);
    } // setupUi

    void retranslateUi(QDialog *CaseandEditorhome)
    {
        CaseandEditorhome->setWindowTitle(QApplication::translate("CaseandEditorhome", "Case Enviroment Configure", Q_NULLPTR));
        label->setText(QApplication::translate("CaseandEditorhome", "Case Project Path", Q_NULLPTR));
        label_2->setText(QApplication::translate("CaseandEditorhome", "Pycharm  Path", Q_NULLPTR));
        PB_ProjectPath->setText(QString());
        PB_PycharmPath->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CaseandEditorhome: public Ui_CaseandEditorhome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASEANDEDITORHOME_H
