/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *bDemarrer;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lMonNom;
    QLabel *lAfficherNom;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lMonPrenom;
    QLabel *lAfficherPrenom;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lEtreMajeur;
    QLabel *lAfficherMajeur;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lEnfant;
    QLabel *lAfficherEnfant;
    QMenuBar *menubar;
    QMenu *menuMainWindow;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(496, 304);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        bDemarrer = new QPushButton(centralwidget);
        bDemarrer->setObjectName(QString::fromUtf8("bDemarrer"));

        verticalLayout->addWidget(bDemarrer);


        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lMonNom = new QLabel(centralwidget);
        lMonNom->setObjectName(QString::fromUtf8("lMonNom"));

        horizontalLayout_5->addWidget(lMonNom);

        lAfficherNom = new QLabel(centralwidget);
        lAfficherNom->setObjectName(QString::fromUtf8("lAfficherNom"));

        horizontalLayout_5->addWidget(lAfficherNom);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lMonPrenom = new QLabel(centralwidget);
        lMonPrenom->setObjectName(QString::fromUtf8("lMonPrenom"));

        horizontalLayout_6->addWidget(lMonPrenom);

        lAfficherPrenom = new QLabel(centralwidget);
        lAfficherPrenom->setObjectName(QString::fromUtf8("lAfficherPrenom"));

        horizontalLayout_6->addWidget(lAfficherPrenom);


        verticalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lEtreMajeur = new QLabel(centralwidget);
        lEtreMajeur->setObjectName(QString::fromUtf8("lEtreMajeur"));

        horizontalLayout_7->addWidget(lEtreMajeur);

        lAfficherMajeur = new QLabel(centralwidget);
        lAfficherMajeur->setObjectName(QString::fromUtf8("lAfficherMajeur"));

        horizontalLayout_7->addWidget(lAfficherMajeur);


        verticalLayout_5->addLayout(horizontalLayout_7);


        verticalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lEnfant = new QLabel(centralwidget);
        lEnfant->setObjectName(QString::fromUtf8("lEnfant"));

        horizontalLayout_8->addWidget(lEnfant);

        lAfficherEnfant = new QLabel(centralwidget);
        lAfficherEnfant->setObjectName(QString::fromUtf8("lAfficherEnfant"));

        horizontalLayout_8->addWidget(lAfficherEnfant);


        verticalLayout_6->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(verticalLayout_6);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 496, 22));
        menuMainWindow = new QMenu(menubar);
        menuMainWindow->setObjectName(QString::fromUtf8("menuMainWindow"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMainWindow->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        bDemarrer->setText(QCoreApplication::translate("MainWindow", "D\303\251marrer le Questionnaire", nullptr));
        lMonNom->setText(QCoreApplication::translate("MainWindow", "Mon Nom :", nullptr));
        lAfficherNom->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lMonPrenom->setText(QCoreApplication::translate("MainWindow", "Mon Pr\303\251nom : ", nullptr));
        lAfficherPrenom->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lEtreMajeur->setText(QCoreApplication::translate("MainWindow", "Majeur : ", nullptr));
        lAfficherMajeur->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lEnfant->setText(QCoreApplication::translate("MainWindow", "Nombre Enfant(s) : ", nullptr));
        lAfficherEnfant->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuMainWindow->setTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
