#include "convertisseurtemp.h"
#include "ui_convertisseurtemp.h"

convertisseurTemp::convertisseurTemp(QWidget *parent)
    : QWidget(parent)
{
    //1. Instancier les widgets

    lTitre = new QLabel(tr("Conversion Celsius vers Fahrenheit"), this);
    lTitre = new QLabel(tr("Convertisseur de température"), this);
    lCelsius = new QLabel(tr("degrés celsius"),this);
    lFahrenheit = new QLabel(tr("degrés Fahrenheit"), this);
    lResultat = new QLabel(this);
    bConvertir = new QPushButton(tr("Convertir"), this);
    bEffacer = new QPushButton(tr("Effacer"), this);
    bQuitter = new QPushButton(tr("Quitter"), this);
    eCelsius = new QLineEdit("",this);
    gLayout = new QGridLayout(this);

    //2. Positionner les widgets
    //lignes

    gLayout->setRowStretch(0,0);
    gLayout->setRowStretch(1,1);
    gLayout->setRowStretch(2,0);
    gLayout->setRowStretch(3,0);
    gLayout->setRowStretch(4,5);
    gLayout->setRowStretch(5,0);

    //colonnes
    gLayout->setColumnStretch(0,1);
    gLayout->setColumnStretch(1,0);
    gLayout->setColumnStretch(2,0);
    gLayout->setColumnStretch(3,0);
    gLayout->setColumnStretch(4,0);
    gLayout->setColumnStretch(5,1);

    //Placement
    gLayout->addWidget(lCelsius,2,1,1,1);
    gLayout->addWidget(lFahrenheit,2,3,1,1);
    gLayout->addWidget(lTitre,0,1,14,Qt::AlignCenter);
    gLayout->addWidget(lResultat,3,3,1,1);
    gLayout->addWidget(bEffacer,5,1,1,1,Qt::AlignBottom);
    gLayout->addWidget(bConvertir,5,2,1,1,Qt::AlignBottom);
    gLayout->addWidget(bQuitter,5,4,1,1,Qt::AlignBottom);
    gLayout->addWidget(eCelsius,3,1,1,2);

    QCoreApplication *instApp = QCoreApplication::instance();

    //Titre de la fenetre

    connect(bConvertir, SIGNAL(clicked()),this,SLOT(convertir()));
    connect(bQuitter, SIGNAL(clicked()), instApp, SLOT(quit()));
    connect(bEffacer, SIGNAL(clicked()), this, SLOT(effacer()));

}

convertisseurTemp::~convertisseurTemp()
{
}

void convertisseurTemp::convertir()
{

    float valeurSource;  // nbre décimal extrait de lValeurSource
    float resultat;     // résultat de la conversion
    bool ok = true ;    // indicateur de réussite de la conversion string--> float

    valeurSource = eCelsius->text().toFloat(&ok);  // devient false si conversion échoue
    if (ok == true)
        {
            // réalise la conversion et affiche le résultat
            resultat = celsiusToFahrenheit(valeurSource);
            QString chaineResultat;
            chaineResultat.setNum(resultat, 'f', 2);
            lResultat->setText(chaineResultat);

            // qDebug() << chaineResultat << Qt::endl;  // pour vérifier le contenu de la chaîne fabriquée
        }
    else
        {
            qDebug() << tr("la valeur n'est pas un nbre") << Qt::endl;       // version intermédiaire

            // Envoi d'un message indiquant la raison du NON calcul
            QMessageBox *msgBox = new QMessageBox();
            msgBox->setStandardButtons(QMessageBox::Ok);
            msgBox->setText("Il n'y pas de valeur à convertir, ou bien ce champ ne contient pas de valeur numérique.");
            msgBox->setWindowTitle("Calcul impossible");
            msgBox->exec();
        }

    // qDebug() << "bouton bConvertir cliqué :"  << Qt::endl ;  // version initiale
}

void convertisseurTemp::effacer()
{
    eCelsius->clear();
    lResultat->setText(tr("--:--"));
}

float celsiusToFahrenheit(float c)
{
    return (c*9/5)+32;
}

