#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void cacherLesWidgets();

public slots:
        void demandeInitial();
private:
    Ui::MainWindow *ui;
    Dialog *maDlg;
};
#endif // MAINWINDOW_H