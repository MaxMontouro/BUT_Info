/********************************************************************************
** Form generated from reading UI file 'convertisseurtemp.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTISSEURTEMP_H
#define UI_CONVERTISSEURTEMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_convertisseurTemp
{
public:

    void setupUi(QWidget *convertisseurTemp)
    {
        if (convertisseurTemp->objectName().isEmpty())
            convertisseurTemp->setObjectName(QString::fromUtf8("convertisseurTemp"));
        convertisseurTemp->resize(800, 600);

        retranslateUi(convertisseurTemp);

        QMetaObject::connectSlotsByName(convertisseurTemp);
    } // setupUi

    void retranslateUi(QWidget *convertisseurTemp)
    {
        convertisseurTemp->setWindowTitle(QCoreApplication::translate("convertisseurTemp", "convertisseurTemp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class convertisseurTemp: public Ui_convertisseurTemp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTISSEURTEMP_H
