#ifndef RATIONNALLITERAL_H
#define RATIONNALLITERAL_H

#include "digital_literal.h"

class RationalLiteral : public DigitalLiteral {
private:
    // Pour le moment, on fait du test sur du int
    int numerator;
    int denominator;

    void simplify();

public:
    // Le choix du constructeur se fera dans la factory
    RationalLiteral(int num = 0, int den = 1) : numerator(num), denominator(den){
        simplify();
    }
    // Constructeur de recopie par défaut
    // Opérateur d'affectation par défaut
    // Destructeur par défaut

    // Accesseurs
    // Pas de setters
    int getNumerator() const {return numerator;}
    int getDenominator() const {return denominator;}

    // Opérateurs numériques

    // Opérateurs logiques

    // Autres
    QString toString() const;
    double toReal() const;
};

#endif // RATIONNALLITERAL_H
