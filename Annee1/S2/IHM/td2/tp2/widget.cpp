#include "widget.h"

ConvertisseurTemp::ConvertisseurTemp(QWidget *parent)
    : QWidget(parent)
{
    // Mise en place des Filtres

    QFont fTitre(tr("Arial"),14,QFont::Bold);
    QFont fResultat;
    fTitre.setFamily(tr("Arial"));
    fTitre.setPointSize(11);

    // 1. Instancier les widgets. Il sont tous enfants de la fenêtre

    lTitre = new QLabel(tr("Convertisseur de température"), this);
    lCelsius = new QLabel(tr("degrés celsius"),this);
    lFahrenheit = new QLabel(tr("degrés Fahrenheit"), this);
    lResultat = new QLabel(this);
    bConvertir = new QPushButton(tr("Convertir"), this);
    bQuitter = new QPushButton(tr("Quitter"), this);
    bEffacer = new QPushButton (tr("Effacer"), this);
    eCelsius = new QLineEdit("",this);
    eValeurSource = new QLineEdit(this);

    //2. Positionner les widgets

    lTitre -> setGeometry(16, 20, 430, 30);
    lCelsius -> setGeometry(116,70,101,20);
    lFahrenheit -> setGeometry(256,70,125,20);
    lResultat -> setGeometry(256, 93, 63, 20);
    bConvertir -> setGeometry(116, 160, 93, 29);
    bQuitter -> setGeometry(336, 160, 93, 29);
    bEffacer -> setGeometry (16, 160, 93, 29) ;
    eCelsius -> setGeometry(116,92,91,26);
    eValeurSource -> setGeometry(116,92,91,26);
    lTitre -> setFont(fTitre);
    lResultat -> setFont(fResultat);

    lResultat -> setText("--.--");

    QCoreApplication *instApp = QCoreApplication::instance();

    connect(bConvertir, SIGNAL(clicked()), this, SLOT(convertir()));
    connect(bEffacer, SIGNAL(clicked()), this, SLOT(effacer()));
    connect(bQuitter, SIGNAL(clicked()), instApp, SLOT(quit()));
}

ConvertisseurTemp::~ConvertisseurTemp()
{

}

void ConvertisseurTemp::convertir()
{

    float valeurSource;  // nbre décimal extrait de lValeurSource
    float resultat;     // résultat de la conversion
    bool ok = true ;    // indicateur de réussite de la conversion string--> float

    valeurSource = eValeurSource->text().toFloat(&ok);  // devient false si conversion échoue
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
            int ret = msgBox->exec();        // on ne prend pas en compte la valeur retournée
        }

    // qDebug() << "bouton bConvertir cliqué :"  << Qt::endl ;  // version initiale
}

void ConvertisseurTemp::effacer()
{
    eCelsius->clear();
    lResultat->setText(tr("--.--"));
}

float celsiusToFahrenheit(float c)
{
    return (c*(9/5))+32;
}
