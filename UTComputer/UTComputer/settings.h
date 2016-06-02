#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QWidget>
#include <QSettings>

class Settings
{
private:
    bool playSound;
    unsigned int nbMaxCharOnStack;
    bool displayKeyboard;
public:
    Settings();
    Settings (bool sound, unsigned int maxChar, bool keyboard):
        playSound(sound), nbMaxCharOnStack(maxChar), displayKeyboard(keyboard) {}
    //Accesseurs de PlaySound
    bool getPlaySound() const { return playSound; }
    void setPlaySound (bool playsound) { playSound = playsound; }

    //Accesseurs de nbMaxCharOnStack
    unsigned int getNbMaxCharOnStack() const { return nbMaxCharOnStack; }
    void setNbMaxCharOnStack (unsigned int nb) { nbMaxCharOnStack = nb; }

    //Accesseurs de displayKeyboard
    bool getDisplayKeyboard() const { return displayKeyboard; }
    void setDisplayKeyboard (bool dK) { displayKeyboard = dK; }

    //pour sauvegarder https://openclassrooms.com/courses/enregistrer-vos-options-avec-qsettings
    //QSettings::QSettings ( const QString &amp; organization, const QString &amp; application = QString(), QObject * parent = 0 )

    /* Pour retrouver le fichier sous Windows:
    *  HKEY_CURRENT_USER\Software\sdz\MonProgramme
    * qui est un répertoire du registre système*/

    void loadSettingsFromFile ();
    void saveSettingsToFile();
};

#endif // SETTINGS_H
