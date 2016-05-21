#ifndef INTEGERLITERAL_H
#define INTEGERLITERAL_H

#include "digital_literal.h"

class IntegerLiteral : public DigitalLiteral {
private:
    int value;

public:
    // Le choix du constructeur se fera dans la factory
    IntegerLiteral(int n = 0) : value(n){}
    // Constructeur de recopie par défaut
    // Opérateur d'affectation par défaut
    // Destructeur par défaut

    // Accesseurs
    // Pas de setters
    int getValue() const {return value;}

    // Opérateurs numériques

    // Opérateurs logiques

    // Autres
    QString toString() const;
};

#endif // INTEGERLITERAL_H
