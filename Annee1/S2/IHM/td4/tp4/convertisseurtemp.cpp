#include "convertisseurtemp.h"
#include "ui_convertisseurtemp.h"

ConvertisseurTemp::ConvertisseurTemp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ConvertisseurTemp)
{
    ui->setupUi(this);
}

ConvertisseurTemp::~ConvertisseurTemp()
{
    delete ui;
}

