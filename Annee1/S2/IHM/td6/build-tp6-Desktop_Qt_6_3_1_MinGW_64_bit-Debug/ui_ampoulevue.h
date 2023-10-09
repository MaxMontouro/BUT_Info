/********************************************************************************
** Form generated from reading UI file 'ampoulevue.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AMPOULEVUE_H
#define UI_AMPOULEVUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AmpouleVue
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *bAllumer;
    QPushButton *bEteindre;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AmpouleVue)
    {
        if (AmpouleVue->objectName().isEmpty())
            AmpouleVue->setObjectName(QString::fromUtf8("AmpouleVue"));
        AmpouleVue->resize(469, 304);
        centralwidget = new QWidget(AmpouleVue);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        bAllumer = new QPushButton(centralwidget);
        bAllumer->setObjectName(QString::fromUtf8("bAllumer"));

        gridLayout->addWidget(bAllumer, 3, 1, 1, 1);

        bEteindre = new QPushButton(centralwidget);
        bEteindre->setObjectName(QString::fromUtf8("bEteindre"));

        gridLayout->addWidget(bEteindre, 3, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        AmpouleVue->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AmpouleVue);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 469, 22));
        AmpouleVue->setMenuBar(menubar);
        statusbar = new QStatusBar(AmpouleVue);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AmpouleVue->setStatusBar(statusbar);

        retranslateUi(AmpouleVue);

        QMetaObject::connectSlotsByName(AmpouleVue);
    } // setupUi

    void retranslateUi(QMainWindow *AmpouleVue)
    {
        AmpouleVue->setWindowTitle(QCoreApplication::translate("AmpouleVue", "AmpouleVue", nullptr));
        bAllumer->setText(QCoreApplication::translate("AmpouleVue", "Allumer", nullptr));
        bEteindre->setText(QCoreApplication::translate("AmpouleVue", "\303\211teindre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AmpouleVue: public Ui_AmpouleVue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AMPOULEVUE_H
