#include <QCoreApplication>

#include "settings.h"
#include "stack.h"
#include "literal_factory.h"

void Settings::saveSettingsToFile(const Stack& stack, const LiteralFactory& fact){
     QSettings settings(QCoreApplication::applicationDirPath() +  "/settings.ini", QSettings::IniFormat);

     settings.beginGroup("Settings");
     settings.setValue("sound", playSound);
     settings.setValue("Keyboard", displayKeyboard);
     settings.setValue("nbLiteralsOnStack", nbLiteralsOnStack);
     settings.endGroup();

     settings.beginGroup("Stack");
     int i = 0;
     for(Stack::const_iterator literal = stack.cbegin(); literal != stack.cend(); ++literal, i++){
         settings.setValue(QString::number(i), (*literal).toString());
     }
     settings.endGroup();
}

void Settings::loadSettingsFromFile(){
    QSettings settings (QCoreApplication::applicationDirPath() +  "/settings.ini", QSettings::IniFormat);

    settings.beginGroup("Settings");
    playSound = settings.value("sound","false").toBool();
    displayKeyboard = settings.value ("Keyboard","true").toBool();
    nbLiteralsOnStack = settings.value ("nbLiteralsOnStack","5").toUInt();

    if(nbLiteralsOnStack < 1)
        nbLiteralsOnStack = 1;

    if(nbLiteralsOnStack > 10)
        nbLiteralsOnStack = 10;

    settings.endGroup();
}
