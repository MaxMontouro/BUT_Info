#ifndef TESTBD_H
#define TESTBD_H

#include <QMainWindow>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TestBD; }
QT_END_NAMESPACE

class TestBD : public QMainWindow
{
    Q_OBJECT

public:
    TestBD(QWidget *parent = nullptr);
    ~TestBD();

private:
    Ui::TestBD *ui;
    DataBase *db;
};

#endif // TESTBD_H
