/********************************************************************************
** Form generated from reading UI file 'database.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASE_H
#define UI_DATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataBase
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pOk;
    QPushButton *pushButton_2;
    QPushButton *bQuitter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DataBase)
    {
        if (DataBase->objectName().isEmpty())
            DataBase->setObjectName(QString::fromUtf8("DataBase"));
        DataBase->resize(587, 369);
        centralwidget = new QWidget(DataBase);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        horizontalLayout->addWidget(tableWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pOk = new QPushButton(centralwidget);
        pOk->setObjectName(QString::fromUtf8("pOk"));

        verticalLayout_2->addWidget(pOk);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        bQuitter = new QPushButton(centralwidget);
        bQuitter->setObjectName(QString::fromUtf8("bQuitter"));

        verticalLayout_2->addWidget(bQuitter);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        DataBase->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DataBase);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 587, 22));
        DataBase->setMenuBar(menubar);
        statusbar = new QStatusBar(DataBase);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DataBase->setStatusBar(statusbar);

        retranslateUi(DataBase);

        QMetaObject::connectSlotsByName(DataBase);
    } // setupUi

    void retranslateUi(QMainWindow *DataBase)
    {
        DataBase->setWindowTitle(QCoreApplication::translate("DataBase", "DataBase", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DataBase", "Code Postal", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DataBase", "NomVille", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DataBase", "NombreHabitants", nullptr));
        pOk->setText(QCoreApplication::translate("DataBase", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DataBase", "PushButton", nullptr));
        bQuitter->setText(QCoreApplication::translate("DataBase", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataBase: public Ui_DataBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASE_H
