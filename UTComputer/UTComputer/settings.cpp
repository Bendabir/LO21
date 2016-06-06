#include <QCoreApplication>
#include <QDebug>

#include "settings.h"
#include "stack.h"
#include "literal_factory.h"

void Settings::saveSettingsToFile(const Stack& stack, const LiteralFactory& fact){
     QSettings settings(QCoreApplication::applicationDirPath() +  "/settings.ini", QSettings::IniFormat);

     // On stockes les variables et les littérales
     QVector<const Literal*> programms;
     QVector<const Literal*> variables;

     for(LiteralFactory::const_iterator literal = fact.cbegin(); literal != fact.cend(); ++literal){
         if((*literal).isProgramm())
             programms.push_back(&*literal);

         if((*literal).isAtom())
             variables.push_back(&*literal);
     }

     // On sauvegarde les options de l'application
     settings.beginGroup("Settings");
     settings.setValue("sound", playSound);
     settings.setValue("keyboard", displayKeyboard);
     settings.setValue("nbLiteralsOnStack", nbLiteralsOnStack);
     settings.endGroup();

     // On supprime l'ancienne pile et on la resauvegarde si besoin
     settings.remove("Stack");
     if(stack.size() > 0){
         settings.beginWriteArray("Stack");
         int i = stack.size() - 1;

         for(Stack::const_iterator literal = stack.cbegin(); literal != stack.cend(); ++literal, --i){
            settings.setArrayIndex(i);
            settings.setValue("literal", (*literal).toString());
         }

         settings.endArray();
     }

//     // On supprime les programmes puis on les resauvegardes
//     settings.remove("Programms");
//     if(programms.size() > 0){
//        settings.beginWriteArray("Programms");
//        int i = 0;
//        for(QVector<const Literal*>::const_iterator literal = programms.cbegin(); literal != programms.cend(); ++literal, i++){
//            settings.setArrayIndex(i);
//            settings.setValue("programm", (**literal).toString());
//        }

//        settings.endArray();
//     }

     // On supprime les atomes puis on les resauvegardes
     settings.remove("Atoms");
     if(variables.size() > 0){
        settings.beginWriteArray("Atoms");
        int i = 0;
        for(QVector<const Literal*>::const_iterator literal = variables.cbegin(); literal != variables.cend(); ++literal, i++){
            settings.setArrayIndex(i);
            settings.setValue("name", (**literal).toString());
            settings.setValue("value", (**literal).eval());
        }

        settings.endArray();
     }
}

void Settings::loadSettingsFromFile(Stack &stack, LiteralFactory &fact){
    QSettings settings (QCoreApplication::applicationDirPath() +  "/settings.ini", QSettings::IniFormat);

    settings.beginGroup("Settings");
    playSound = settings.value("sound","false").toBool();
    displayKeyboard = settings.value ("keyboard","true").toBool();
    nbLiteralsOnStack = settings.value ("nbLiteralsOnStack","5").toUInt();

    if(nbLiteralsOnStack < 1)
        nbLiteralsOnStack = 1;

    if(nbLiteralsOnStack > 10)
        nbLiteralsOnStack = 10;

    settings.endGroup();

//    int programmsSize = settings.beginArray("Programms");
//    for(int i = 0; i < programmsSize; i++){
//        settings.setArrayIndex(i);
//        fact.addLiteral(settings.value("programm").toString()); // Mal géré, peut mieux faire
//    }

    int atomsSize = settings.beginReadArray("Atoms");
    for(int i = 0; i < atomsSize; i++){
        settings.setArrayIndex(i);
        try {
            QString targetValue = settings.value("value").toString();
            QString atomName = settings.value("name").toString();

            Literal& target = fact.addLiteralFromString(targetValue);
            fact.addLiteral(atomName, &target);
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }

    // On charge la pile
    int stackSize = settings.beginReadArray("Stack");
    for(int i = stackSize - 1; i >= 0; i--){
        settings.setArrayIndex(i);
        QString literal = settings.value("literal").toString();

        try {
            // On vérifie si c'est un atome
            if(fact.existsAtom(literal)){
                Literal& atom = fact.findLiteral(literal);
                stack.push(atom);
            }
            else{
                Literal& l = fact.addLiteralFromString(literal);
                stack.push(l);
            }
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
    settings.endArray();
}
