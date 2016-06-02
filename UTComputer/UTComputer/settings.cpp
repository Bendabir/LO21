#include "settings.h"

void Settings::saveSettingsToFile(){
     QSettings settings("sdz", "OptionsProjetLO21");
     settings.setValue("sound", playSound);
     settings.setValue("Keyboard", displayKeyboard);
     settings.setValue("nbLiteralsOnStack", nbLiteralsOnStack);
}

void Settings::loadSettingsFromFile(){
    QSettings settings ("sdz", "OptionsProjetLO21");
    playSound = settings.value("sound","false").toBool();
    displayKeyboard = settings.value ("Keyboard","true").toBool();
    nbLiteralsOnStack = settings.value ("nbLiteralsOnStack","5").toUInt();
}
