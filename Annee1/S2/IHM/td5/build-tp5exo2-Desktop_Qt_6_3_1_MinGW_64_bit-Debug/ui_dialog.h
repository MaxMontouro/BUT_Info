/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lPrenom;
    QLineEdit *ePrenom;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *eNom;
    QLineEdit *lNom;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioButton;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *bOk;
    QPushButton *bAnnuler;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(412, 258);
        verticalLayout_2 = new QVBoxLayout(Dialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lPrenom = new QLabel(Dialog);
        lPrenom->setObjectName(QString::fromUtf8("lPrenom"));

        horizontalLayout_2->addWidget(lPrenom);

        ePrenom = new QLineEdit(Dialog);
        ePrenom->setObjectName(QString::fromUtf8("ePrenom"));

        horizontalLayout_2->addWidget(ePrenom);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        eNom = new QLabel(Dialog);
        eNom->setObjectName(QString::fromUtf8("eNom"));

        horizontalLayout->addWidget(eNom);

        lNom = new QLineEdit(Dialog);
        lNom->setObjectName(QString::fromUtf8("lNom"));

        horizontalLayout->addWidget(lNom);


        verticalLayout_3->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        radioButton = new QRadioButton(Dialog);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout_5->addWidget(radioButton);


        verticalLayout_2->addLayout(verticalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));

        horizontalLayout_4->addLayout(verticalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        bOk = new QPushButton(Dialog);
        bOk->setObjectName(QString::fromUtf8("bOk"));
        bOk->setEnabled(true);

        horizontalLayout_3->addWidget(bOk);

        bAnnuler = new QPushButton(Dialog);
        bAnnuler->setObjectName(QString::fromUtf8("bAnnuler"));

        horizontalLayout_3->addWidget(bAnnuler);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        lPrenom->setText(QCoreApplication::translate("Dialog", "Pr\303\251nom", nullptr));
        eNom->setText(QCoreApplication::translate("Dialog", "Nom", nullptr));
        radioButton->setText(QCoreApplication::translate("Dialog", "Avez vous plus de 18 ans ? ", nullptr));
        bOk->setText(QCoreApplication::translate("Dialog", "Ok", nullptr));
        bAnnuler->setText(QCoreApplication::translate("Dialog", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
