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

    // Le handler du singleton
//    class Handler {
//        friend class Calculator;

//    private:
//        Calculator* instance;

//        Handler() : instance(0) {}
//        ~Handler(){delete instance;}
//    };

//    static Handler handler;

public:
    Calculator(); // En privé si Singleton
    ~Calculator(); // En privé si Singleton

    // Accesseurs
    Stack& getStack() {return *stack;}


//    static Calculator& start(); // getInstance
//    static void stop(); // freeInstance
};

#endif // CALCULATOR_H
