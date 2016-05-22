#ifndef RATIONNALLITERAL_H
#define RATIONNALLITERAL_H

#include "digital_literal.h"
#include "number_literal.h"

class RationalLiteral : public DigitalLiteral {
private:
    IntegerLiteral numerator;
    IntegerLiteral denominator;

    void simplify();

public:
    // Le choix du constructeur se fera dans la factory
    RationalLiteral(IntegerLiteral num = 0, IntegerLiteral den = 1) : DigitalLiteral(), numerator(num), denominator(den){
        simplify();
    }
    // Constructeur de recopie par défaut
    // Opérateur d'affectation par défaut
    // Destructeur par défaut

    // Accesseurs
    // Pas de setters
    const IntegerLiteral& getNumerator() const {return numerator;}
    const IntegerLiteral& getDenominator() const {return denominator;}

    // Opérateurs numériques

    // Opérateurs logiques

    // Autres
    QString toString() const;
    RealLiteral toReal() const;
};

#endif // RATIONNALLITERAL_H
