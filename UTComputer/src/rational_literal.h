#ifndef RATIONALLITERAL_H
#define RATIONALLITERAL_H

#include "digital_literal.h"
#include "number_literal.h"

class RationalLiteral : public DigitalLiteral {
private:
    IntegerLiteral numerator;
    IntegerLiteral denominator;

    void simplify();

public:
    // Le choix du constructeur se fera dans la factory
    // Il y a conversion implicite depuis IntegerLiteral
    RationalLiteral(IntegerLiteral num = 0, IntegerLiteral den = 1) : DigitalLiteral(), numerator(num), denominator(den){
        simplify();
    }
    // Constructeur de recopie par défaut
    // Opérateur d'affectation par défaut
    // Destructeur par défaut

    // Accesseurs
    const IntegerLiteral& getNumerator() const {return numerator;}
    const IntegerLiteral& getDenominator() const {return denominator;}
    void setNumerator(const IntegerLiteral& l){numerator = l; simplify();}
    void setDenominator(const IntegerLiteral& l){denominator = l; simplify();}

    // Opérateurs numériques
    RationalLiteral operator+(const RationalLiteral& q) const;
    RationalLiteral operator-(const RationalLiteral& q) const;
    RationalLiteral operator*(const RationalLiteral& q) const;
    RationalLiteral operator/(const RationalLiteral& q) const;
    RationalLiteral& operator++();
    RationalLiteral operator++(int);
    RationalLiteral& operator--();
    RationalLiteral operator--(int);

    // Opérateurs logiques

    // Autres
    QString toString() const;
    RealLiteral toReal() const;
};

#endif // RATIONALLITERAL_H
