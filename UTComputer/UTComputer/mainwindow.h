#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QUndoView>
#include <QUndoStack>

#include "calculator.h"
#include "edit_atom_dialog.h"
#include "edit_programm_dialog.h"
#include "settings_dialog.h"

namespace Ui {
class MainWindow;
}

/*!
 * \brief Fenêtre principale de l'application
 */
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

    /*!
     * \brief Permet d'ajouter du texte dans la commande. Utile pour le clavier cliquable, afin de séparer les chiffres etc.
     * \param exp : Texte à ajouter
     */
    void addTextToCommand(const QString& exp);
    /*!
     * \brief Ajoute un opérateur dans la barre de commande puis exécute la commande directement.
     * \param op : Opérateur à ajouter
     */
    void executeOperator(const QString& op);
    /*!
     * \brief Permet d'afficher un message à l'utilisateur (lors d'un retour d'erreur par exemple)."
     * \param message : Message à afficher
     */
    void setUserMessage(const QString& message);
    /*!
     * \brief Permet de mettre à jour la vue graphique de la pile de calcul à partir du contenu de la pile de calcul. Appelé à chaque exécution.
     */
    void refreshListView();

public slots:
    // Ce qui modifie la barre de commande
    /*!
     * \brief Permet d'ajouter 0 dans la barre de commande. Le principe est le même pour tous les autres slots non détaillés. Les slots relatifs aux opérateurs exécutent la commande (sauf si l'on est en train d'écrir un programme ou une expression).
     */
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
    void onDotPressed();
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
    void onCommaPressed();
    void onLeftParenthesisPressed();
    void onRightParenthesisPressed();
    void onStoPressed();
    void onForgetPressed();

    /*!
     * \brief Permet d'exécuter la commande écrite.
     */
    void execute();
    /*!
     * \brief Permet de mettre à jour les options de l'application
     */
    void updateSettings();
    /*!
     * \brief Permet d'exécuter la commande écrite lors de la frappe de +, -, *, / ou $.
     */
    void executeOnOperatorPressed();

    // Pour les raccourcis
    /*!
     * \brief Permet de sauvegarder le contexte de l'application dans un fichier INI. Sauvegarder automatique à la fermeture de l'application.
     */
    void save();
};

#endif // MAINWINDOW_H
