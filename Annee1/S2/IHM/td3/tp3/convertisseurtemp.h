#ifndef CONVERTISSEURTEMP_H
#define CONVERTISSEURTEMP_H

#include <QWidget>
#include <QtWidgets>


class convertisseurTemp : public QWidget
{
    Q_OBJECT

public:
    convertisseurTemp(QWidget *parent = nullptr);
    ~convertisseurTemp();

private:
    QLabel *lCelsius;
    QLabel *lTitre;
    QLineEdit *eCelsius;
    QLabel *lFahrenheit;
    QLabel *lFahrenheit_convertisseur;
    QPushButton *bQuitter;
    QPushButton *bEffacer;
    QPushButton *bConvertir;
    QLabel *lResultat;
    QGridLayout *gLayout;

public slots :
    void convertir();
    void effacer();
};

float celsiusToFahrenheit(float);
#endif // CONVERTISSEURTEMP_H
