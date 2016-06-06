#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "stack.h"
#include "settings.h"

/*!
 * \brief La classe Calculator est la classe principale de l'application. C'est elle qui gère les calculs.
 * \brief C'est un singleton.
 */
class Calculator {
protected:
    Stack* stack;
    Settings* settings;
    LiteralFactory factory;

    // On empêche la recopie et l'affectation
    Calculator(const Calculator& c);
    Calculator& operator=(const Calculator& c);

public:
    Calculator(); // En privé si Singleton
    ~Calculator(); // En privé si Singleton

    void command(const QString& c);
    void commandTest(const QString& commantText);

    // Accesseurs
    Stack& getStack() {return *stack;}

};

unsigned int getArity(const QString &c);

#endif // CALCULATOR_H
