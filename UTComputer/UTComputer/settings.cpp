#include "settings.h"

void Settings::saveSettingsToFile(){
     QSettings settings("sdz", "OptionsProjetLO21");
     settings.setValue("sound", playSound);
     settings.setValue("Keyboard", displayKeyboard);
     settings.setValue("nbMaxCharOnStack", nbMaxCharOnStack);
}

void Settings::loadSettingsFromFile(){
    QSettings settings ("sdz", "OptionsProjetLO21");
    playSound = settings.value("sound","false").toBool();
    displayKeyboard = settings.value ("Keyboard","true").toBool();
    nbMaxCharOnStack = settings.value ("nbMaxCharOnStack","4").toUInt();
}
