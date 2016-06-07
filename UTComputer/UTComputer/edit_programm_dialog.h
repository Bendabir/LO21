#ifndef EDIT_PROGRAMM_DIALOG_H
#define EDIT_PROGRAMM_DIALOG_H

#include <QDialog>

class LiteralFactory;

namespace Ui {
class EditProgrammDialog;
}

/*!
 * \brief Classe permettant la mise en place d'une fenêtre secondaire pour gérer les programmes.
 */
class EditProgrammDialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur
     * \param f : Pointeur sur le manager des littérales de l'application
     * \param parent : Parent de la fenêtre
     */
    explicit EditProgrammDialog(LiteralFactory* f, QWidget *parent = 0);
    ~EditProgrammDialog();

private:
    Ui::EditProgrammDialog *ui;
    LiteralFactory* factory;

private slots:
    /*!
     * \brief Slot appellé lors du choix d'une variable. Il permet d'afficher son contenu dans la barre de saisie.
     */
    void showAtomContent();
    /*!
     * \brief Permet de mettre à jour la liste des variables de l'application. Appelé à chaque ouverture de la fenêtre.
     */
    void updateVariablesList();
    /*!
     * \brief Fonction show() améliorer. Elle envoie un signal isShown() à chaque fois que la fenêtre est ouverte.
     */
    void improvedShow();
    /*!
     * \brief Permet de mettre à jour la variable sélectionné par la valeur entrée dans la barre de saisie.
     */
    void editVariable();
    /*!
     * \brief Active le bouton "Appliquer"
     */
    void enableApply();

signals:
    /*!
     * \brief Signal émis à chaque fois que la fenêtre est ouverte.
     */
    void isShown();
};

#endif // EDIT_PROGRAMM_DIALOG_H
