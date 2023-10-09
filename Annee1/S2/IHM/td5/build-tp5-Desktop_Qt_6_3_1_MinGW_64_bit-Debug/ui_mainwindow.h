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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
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
    QVBoxLayout *verticalLayout;
    QGroupBox *Connexion;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *lUser;
    QLineEdit *eUser;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lMdp;
    QLineEdit *eMdp;
    QPushButton *bConnexion;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(387, 259);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Connexion = new QGroupBox(centralwidget);
        Connexion->setObjectName(QString::fromUtf8("Connexion"));
        verticalLayout_2 = new QVBoxLayout(Connexion);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lUser = new QLabel(Connexion);
        lUser->setObjectName(QString::fromUtf8("lUser"));

        horizontalLayout->addWidget(lUser);

        eUser = new QLineEdit(Connexion);
        eUser->setObjectName(QString::fromUtf8("eUser"));

        horizontalLayout->addWidget(eUser);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lMdp = new QLabel(Connexion);
        lMdp->setObjectName(QString::fromUtf8("lMdp"));

        horizontalLayout_2->addWidget(lMdp);

        eMdp = new QLineEdit(Connexion);
        eMdp->setObjectName(QString::fromUtf8("eMdp"));
        eMdp->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(eMdp);


        verticalLayout_2->addLayout(horizontalLayout_2);

        bConnexion = new QPushButton(Connexion);
        bConnexion->setObjectName(QString::fromUtf8("bConnexion"));

        verticalLayout_2->addWidget(bConnexion);


        verticalLayout->addWidget(Connexion);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 387, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Connexion->setTitle(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
        lUser->setText(QCoreApplication::translate("MainWindow", "Utilisateur :  ", nullptr));
        lMdp->setText(QCoreApplication::translate("MainWindow", "Mot de Passe :", nullptr));
        bConnexion->setText(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
