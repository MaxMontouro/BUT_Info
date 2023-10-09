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

private:
    Ui::MainWindow *ui;

private :
    void cacherLesWidgets();
    // rend invisibles tous les widgets

    void montrerLesWidgets(bool dialNomOk, bool majeur);
    // rend visibles tous les widgets, en fonction de ce qu'il est possible de
    // rendre visible
    // dialNomOk : La fenêtre de Dialogue (Nom, Prénom, majeur) est exploitable, cad
    //             au moins un nom a été saisi et le dialogue a été validé
    // majeur : L'utilsiateur a indiqué qu'il est majeur

private slots:
    void ouvrirDialogue();

};
#endif // MAINWINDOW_H
