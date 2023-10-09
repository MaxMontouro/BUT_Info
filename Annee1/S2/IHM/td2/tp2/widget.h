#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget> //inclut les widgets
#include <QtWidgets>
#include <QPushButton>//inclut les boutons (enfin je crois)
#include <QLineEdit>//inclut quelque chose mais je sais pas quoi
#include <QLabel>//ca inclut un truc mais je sais pas quoi

class ConvertisseurTemp : public QWidget
{
    Q_OBJECT

public:
    ConvertisseurTemp(QWidget *parent = nullptr);
    ~ConvertisseurTemp();

public slots:
    void convertir();
    void effacer();

private:
    QLabel *lCelsius;
    QLabel *lTitre;
    QLineEdit *eCelsius;
    QLineEdit *eValeurSource;
    QLabel *lFahrenheit;
    QLabel *lFahrenheit_convertisseur;
    QLabel *lResultat;
    QPushButton *bQuitter;
    QPushButton *bEffacer;
    QPushButton *bConvertir;
};

float celsiusToFahrenheit(float);
//BUT: convertir le degre celsius en fareinheit

#endif // WIDGET_H
