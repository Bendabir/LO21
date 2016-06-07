#ifndef SETTINGS_DIALOG_H
#define SETTINGS_DIALOG_H

#include <QDialog>

class Settings;

namespace Ui {
class SettingsDialog;
}

/*!
 * \brief Classe permettant l'affichage d'une fenêtre secondaire dédiée à la gestion des paramètres de l'application.
 */
class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur. Prend en paramètre un pointeur sur les options de l'application pour pouvoir les modifier.
     * \param s : Pointeur sur les options de l'application
     * \param parent : Parent de la fenêtre
     */
    explicit SettingsDialog(Settings* s, QWidget *parent = 0);
    ~SettingsDialog();

private:
    Ui::SettingsDialog *ui;
    Settings* settings;

public slots:
    /*!
     * \brief Slot permettant d'appliquer les modifications aux options.
     */
    void apply();
    /*!
     * \brief Slot permettant d'activer le bouton "Appliquer"
     */
    void enableApply();

signals:
    /*!
     * \brief Signal envoyé lors d'une modification des options de l'application
     */
    void settingsChanged();
};

#endif // SETTINGS_DIALOG_H
