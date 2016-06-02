#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "stack.h"

/*!
 * \brief La classe Calculator est la classe principale de l'application. C'est elle qui gère les calculs.
 * \brief C'est un singleton.
 */
class Calculator {
private:
    Stack* stack;
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

	//methode command qui permet d'ajouter et de gerer la creation et destruction des literal et l'ajout dans la pile 
	//en fonction de ce qui est rentrant dans la ligne de commande de la calculatrice
	//Quel est le type renvoyé par cette ligne de commande? C'est bien une référence sur un sting?

	void command(const string& c);


//    static Calculator& start(); // getInstance
//    static void stop(); // freeInstance
};

#endif // CALCULATOR_H
