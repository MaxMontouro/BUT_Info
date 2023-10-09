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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestBD
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *lTitre;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QPushButton *bQuitter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestBD)
    {
        if (TestBD->objectName().isEmpty())
            TestBD->setObjectName(QString::fromUtf8("TestBD"));
        TestBD->resize(514, 262);
        centralwidget = new QWidget(TestBD);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lTitre = new QLabel(centralwidget);
        lTitre->setObjectName(QString::fromUtf8("lTitre"));

        verticalLayout->addWidget(lTitre);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_2->addWidget(tableWidget);


        verticalLayout->addLayout(verticalLayout_2);

        bQuitter = new QPushButton(centralwidget);
        bQuitter->setObjectName(QString::fromUtf8("bQuitter"));

        verticalLayout->addWidget(bQuitter);

        TestBD->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestBD);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 514, 22));
        TestBD->setMenuBar(menubar);
        statusbar = new QStatusBar(TestBD);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TestBD->setStatusBar(statusbar);

        retranslateUi(TestBD);
        QObject::connect(bQuitter, &QPushButton::clicked, TestBD, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(TestBD);
    } // setupUi

    void retranslateUi(QMainWindow *TestBD)
    {
        TestBD->setWindowTitle(QCoreApplication::translate("TestBD", "TestBD", nullptr));
        lTitre->setText(QCoreApplication::translate("TestBD", "Interface Utilisateur ", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TestBD", "R\303\251f\303\251rence Article", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TestBD", "Libell\303\251 Article", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TestBD", "Prix unitaire HT", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TestBD", "Libell\303\251 Cat\303\251gorie", nullptr));
        bQuitter->setText(QCoreApplication::translate("TestBD", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestBD: public Ui_TestBD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTBD_H
