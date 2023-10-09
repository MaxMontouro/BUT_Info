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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConvertisseurTemp
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *lTitre;
    QGridLayout *gridLayout;
    QLineEdit *eCelsius;
    QLabel *lFahrenheit;
    QLabel *lFahrenhei_convertisseur;
    QLabel *lCelsius;
    QHBoxLayout *horizontalLayout;
    QPushButton *bConvertir;
    QPushButton *bEffacer;
    QSpacerItem *horizontalSpacer;
    QPushButton *bQuitter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ConvertisseurTemp)
    {
        if (ConvertisseurTemp->objectName().isEmpty())
            ConvertisseurTemp->setObjectName(QString::fromUtf8("ConvertisseurTemp"));
        ConvertisseurTemp->resize(486, 403);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConvertisseurTemp->sizePolicy().hasHeightForWidth());
        ConvertisseurTemp->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(ConvertisseurTemp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lTitre = new QLabel(centralwidget);
        lTitre->setObjectName(QString::fromUtf8("lTitre"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        lTitre->setFont(font);
        lTitre->setWordWrap(false);

        verticalLayout->addWidget(lTitre);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(7);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(20, -1, 40, 16);
        eCelsius = new QLineEdit(centralwidget);
        eCelsius->setObjectName(QString::fromUtf8("eCelsius"));
        QFont font1;
        font1.setItalic(true);
        eCelsius->setFont(font1);

        gridLayout->addWidget(eCelsius, 2, 0, 1, 1);

        lFahrenheit = new QLabel(centralwidget);
        lFahrenheit->setObjectName(QString::fromUtf8("lFahrenheit"));
        QFont font2;
        font2.setPointSize(13);
        lFahrenheit->setFont(font2);

        gridLayout->addWidget(lFahrenheit, 1, 1, 1, 1);

        lFahrenhei_convertisseur = new QLabel(centralwidget);
        lFahrenhei_convertisseur->setObjectName(QString::fromUtf8("lFahrenhei_convertisseur"));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        lFahrenhei_convertisseur->setFont(font3);

        gridLayout->addWidget(lFahrenhei_convertisseur, 2, 1, 1, 1);

        lCelsius = new QLabel(centralwidget);
        lCelsius->setObjectName(QString::fromUtf8("lCelsius"));
        lCelsius->setFont(font2);

        gridLayout->addWidget(lCelsius, 1, 0, 1, 1);

        gridLayout->setColumnStretch(0, 70);
        gridLayout->setColumnStretch(1, 70);

        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        bConvertir = new QPushButton(centralwidget);
        bConvertir->setObjectName(QString::fromUtf8("bConvertir"));

        horizontalLayout->addWidget(bConvertir);

        bEffacer = new QPushButton(centralwidget);
        bEffacer->setObjectName(QString::fromUtf8("bEffacer"));

        horizontalLayout->addWidget(bEffacer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bQuitter = new QPushButton(centralwidget);
        bQuitter->setObjectName(QString::fromUtf8("bQuitter"));

        horizontalLayout->addWidget(bQuitter);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        ConvertisseurTemp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ConvertisseurTemp);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 486, 22));
        ConvertisseurTemp->setMenuBar(menubar);
        statusbar = new QStatusBar(ConvertisseurTemp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ConvertisseurTemp->setStatusBar(statusbar);

        retranslateUi(ConvertisseurTemp);
        QObject::connect(bQuitter, &QPushButton::clicked, ConvertisseurTemp, qOverload<>(&QMainWindow::close));
        QObject::connect(bEffacer, &QPushButton::clicked, eCelsius, qOverload<>(&QLineEdit::clear));
        QObject::connect(bEffacer, &QPushButton::clicked, lFahrenhei_convertisseur, qOverload<>(&QLabel::clear));

        QMetaObject::connectSlotsByName(ConvertisseurTemp);
    } // setupUi

    void retranslateUi(QMainWindow *ConvertisseurTemp)
    {
        ConvertisseurTemp->setWindowTitle(QCoreApplication::translate("ConvertisseurTemp", "ConvertisseurTemp", nullptr));
        lTitre->setText(QCoreApplication::translate("ConvertisseurTemp", "Convertisseur de temp\303\251ratures", nullptr));
        eCelsius->setText(QCoreApplication::translate("ConvertisseurTemp", "Entre 1 et 999", nullptr));
        lFahrenheit->setText(QCoreApplication::translate("ConvertisseurTemp", "Degr\303\251s Fahrenheit", nullptr));
        lFahrenhei_convertisseur->setText(QCoreApplication::translate("ConvertisseurTemp", "         --.--", nullptr));
        lCelsius->setText(QCoreApplication::translate("ConvertisseurTemp", "Degr\303\251s Celsius", nullptr));
        bConvertir->setText(QCoreApplication::translate("ConvertisseurTemp", "Convertir", nullptr));
        bEffacer->setText(QCoreApplication::translate("ConvertisseurTemp", "Effacer", nullptr));
        bQuitter->setText(QCoreApplication::translate("ConvertisseurTemp", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConvertisseurTemp: public Ui_ConvertisseurTemp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTISSEURTEMP_H
