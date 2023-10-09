/********************************************************************************
** Form generated from reading UI file 'testbd.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTBD_H
#define UI_TESTBD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testBD
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *testBD)
    {
        if (testBD->objectName().isEmpty())
            testBD->setObjectName(QString::fromUtf8("testBD"));
        testBD->resize(800, 600);
        centralwidget = new QWidget(testBD);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        verticalLayout_2->addLayout(verticalLayout);

        testBD->setCentralWidget(centralwidget);
        menubar = new QMenuBar(testBD);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        testBD->setMenuBar(menubar);
        statusbar = new QStatusBar(testBD);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        testBD->setStatusBar(statusbar);

        retranslateUi(testBD);

        QMetaObject::connectSlotsByName(testBD);
    } // setupUi

    void retranslateUi(QMainWindow *testBD)
    {
        testBD->setWindowTitle(QCoreApplication::translate("testBD", "testBD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testBD: public Ui_testBD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTBD_H
