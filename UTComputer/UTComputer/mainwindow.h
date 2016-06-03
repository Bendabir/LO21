#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>

#include "calculator.h"
#include "edit_atom_dialog.h"
#include "edit_programm_dialog.h"
#include "settings_dialog.h"

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
    EditProgrammDialog* editProgrammDialog;
    EditAtomDialog* editVariablesDialog;
    SettingsDialog* settingsDialog;

    void addTextToCommand(const QString& exp);
    void executeOperator(const QString& op);
    void setUserMessage(const QString& message);
    void refreshListView();

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
    void onClearPressed();

    void onDupPressed();
    void onSwapPressed();
    void onDropPressed();
    void onLastopPressed();
    void onLastargsPressed();
    void onUndoPressed();
    void onRedoPressed();
    void onWhilePressed();
    void onIftPressed();
    void onIftePressed();
    void onLeftBracketPressed();
    void onRightBracketPressed();
    void onAndPressed();
    void onOrPressed();
    void onNotPressed();
    void onEqualPressed();
    void onNotEqualPressed();
    void onLtPressed();
    void onLtePressed();
    void onGtPressed();
    void onGtePressed();
    void onDollarPressed();
    void onRePressed();
    void onImPressed();
    void onArgPressed();
    void onNormPressed();
    void onNumPressed();
    void onDenPressed();
    void onDivPressed();
    void onModPressed();
    void onCosPressed();
    void onSinPressed();
    void onTanPressed();
    void onArccosPressed();
    void onArcsinPressed();
    void onArctanPressed();
    void onPowPressed();
    void onSqrtPressed();
    void onExpPressed();
    void onLnPressed();
    void onQuotePressed();
    void onNegPressed();
    void onEditPressed();
    void onEvalPressed();
    void onDividePressed();
    void onTimesPressed();
    void onMinusPressed();
    void onPlusPressed();
    void onEnterPressed();

    void appendLiteralInStack();

    // Pour les raccourcis
    void save();
    void load();
};

#endif // MAINWINDOW_H
