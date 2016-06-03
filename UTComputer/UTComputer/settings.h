#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QWidget>
#include <QSettings>

class Stack;
class LiteralFactory;

class Settings {
private:
    bool playSound;
    unsigned int nbLiteralsOnStack;
    bool displayKeyboard;

public:
    Settings() : playSound(true), nbLiteralsOnStack(5), displayKeyboard(true){}
    Settings (bool sound, unsigned int maxChar, bool keyboard):
        playSound(sound), nbLiteralsOnStack(maxChar), displayKeyboard(keyboard) {}
    //Accesseurs de PlaySound
    bool getPlaySound() const { return playSound; }
    void setPlaySound (bool playsound) { playSound = playsound; }

    //Accesseurs de nbLiteralsOnStack
    unsigned int getNbLiteralsOnStack() const { return nbLiteralsOnStack; }
    void setNbLiteralsOnStack (unsigned int nb) { nbLiteralsOnStack = nb; }

    //Accesseurs de displayKeyboard
    bool getDisplayKeyboard() const { return displayKeyboard; }
    void setDisplayKeyboard (bool dK) { displayKeyboard = dK; }

    void loadSettingsFromFile(Stack& stack, LiteralFactory& fact);
    void saveSettingsToFile(const Stack& stack, const LiteralFactory& fact);
};

#endif // SETTINGS_H
