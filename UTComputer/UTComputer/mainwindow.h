#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>

#include "calculator.h"
#include "edit_atom_dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Calculator
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QDialog* editProgrammDialog;
    EditAtomDialog* editVariablesDialog;

    void addTextToCommand(const QString& exp);

public slots:
    // Ce qui modifie la barre de commande
    void on0Pressed();
    void on1Pressed();
    void on2Pressed();
    void on3Pressed();
    void on4Pressed();
    void on5Pressed();
    void on6Pressed();
    void on7Pressed();
    void on8Pressed();
    void on9Pressed();
    void onCommaPressed();
    void onBackspacePressed();


};

#endif // MAINWINDOW_H
