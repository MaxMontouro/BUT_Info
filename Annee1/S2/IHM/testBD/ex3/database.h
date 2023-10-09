#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>

#define DATABASE_NAME "mmontouro_bd"
#define CONNECT_TYPE "QODBC"

QT_BEGIN_NAMESPACE
namespace Ui { class DataBase; }
QT_END_NAMESPACE

class DataBase : public QMainWindow
{
    Q_OBJECT

public:
    DataBase(QWidget *parent = nullptr);
    ~DataBase();
    bool openDataBase();
    void closeDataBase();
    bool restoreDataBase();
    bool insertVilles();
private:
    QSqlDatabase mydb;
    Ui::DataBase *ui;
};
#endif // DATABASE_H
