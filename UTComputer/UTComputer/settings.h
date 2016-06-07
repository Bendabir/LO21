#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QWidget>
#include <QSettings>

class Stack;
class LiteralFactory;

/*!
 * \brief Classe permettant de gérer les différentes options de l'application
 */
class Settings {
private:
    bool playSound;
    unsigned int nbLiteralsOnStack;
    bool displayKeyboard;

public:
    /*!
     * \brief Constructeur. Charge les paramètres au démarrage de l'application grâce à loadSettingsFromFile(). Si l'objet n'arrive pas à charger les paramètres, des paramètres par défaut sont utilisés.
     */
    Settings() : playSound(true), nbLiteralsOnStack(5), displayKeyboard(true){}
    /*!
     * \brief Constructeur permettant de spécifier ses propres paramètres par défaut
     * \param sound : Son ou non
     * \param maxLiterals : Nombre maximum de littérales sur la vue graphique de la pile
     * \param keyboard : Clavier cliquable ou non
     */
    Settings (bool sound, unsigned int maxLiterals, bool keyboard):
        playSound(sound), nbLiteralsOnStack(maxLiterals), displayKeyboard(keyboard) {}

    //Accesseurs de PlaySound
    /*!
     * \brief Getter de l'option de son
     * \return Vrai si le son est activé, faux sinon
     */
    bool getPlaySound() const { return playSound; }
    /*!
     * \brief Setter de l'option de son
     * \param playsound : Vrai si l'on veut activer le son, faux sinon
     */
    void setPlaySound (bool playsound) { playSound = playsound; }

    //Accesseurs de nbLiteralsOnStack
    /*!
     * \brief Getter du nombre de littérales sur la vue graphique de la pile.
     * \return Nombre maximum de littérales affichées.
     */
    unsigned int getNbLiteralsOnStack() const { return nbLiteralsOnStack; }
    /*!
     * \brief Setter du nombre de littérales sur la vue graphique de la pile.
     * \param Nombre maximum de littérales à afficher.
     */
    void setNbLiteralsOnStack (unsigned int nb) { nbLiteralsOnStack = nb; }

    //Accesseurs de displayKeyboard
    /*!
     * \brief Getter de l'option de clavier
     * \return Vrai si le clavier cliquable est activé, faux sinon
     */
    bool getDisplayKeyboard() const { return displayKeyboard; }
    /*!
     * \brief Setter de l'option de clavier
     * \param playsound : Vrai si l'on veut activer le clavier cliquable, faux sinon
     */
    void setDisplayKeyboard (bool dK) { displayKeyboard = dK; }

    /*!
     * \brief Permet de charger le contexte de l'application depuis un fichier INI. Prend en paramètres une référence sur la pile de calcul pour la restaurer et une référence sur le manager de littérales pour restaurer les variables et programmes.
     * \param stack : Référence sur la pile de calcul
     * \param fact : Référence sur le manager de littérales
     */
    void loadSettingsFromFile(Stack& stack, LiteralFactory& fact);
    /*!
     * \brief Permet de sauvegarder le contexte de l'application vers un fichier INI. Prend en paramètres une référence sur la pile de calcul pour la sauvegarder et une référence sur le manager de littérales pour sauvegarder les variables et programmes.
     * \param stack : Référence sur la pile de calcul
     * \param fact : Référence sur le manager de littérales
     */
    void saveSettingsToFile(const Stack& stack, const LiteralFactory& fact);
};

#endif // SETTINGS_H
