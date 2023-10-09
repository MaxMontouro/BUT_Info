#ifndef CONVERTISSEURTEMP_H
#define CONVERTISSEURTEMP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ConvertisseurTemp; }
QT_END_NAMESPACE

class ConvertisseurTemp : public QMainWindow
{
    Q_OBJECT

public:
    ConvertisseurTemp(QWidget *parent = nullptr);
    ~ConvertisseurTemp();

private:
    Ui::ConvertisseurTemp *ui;
};
#endif // CONVERTISSEURTEMP_H
