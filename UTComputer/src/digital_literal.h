#ifndef DIGITAL_LITERAL_H
#define DIGITAL_LITERAL_H

#include "literal.h"

/*!
 * \brief The DigitalLiteral class
 */

// Classe tampon pour faire du test
class DigitalLiteral : public Literal {
private:
//    double value;
public:
    // Constructeurs/Destructeur
    // On conserve la conversion implicite de double vers DigitalLiteral
//    DigitalLiteral(double v = 0) : value(v){}
    DigitalLiteral(){}
    // Constructeur de recopie par défaut
    // Opérateur d'affectation par défaut
    virtual ~DigitalLiteral(){}

    // Accesseurs
//    double getValue() const {return value;}

    // Opérateurs numériques
//    DigitalLiteral* operator+(const DigitalLiteral& l);
//    DigitalLiteral* operator-(const DigitalLiteral& l);
//    DigitalLiteral* operator*(const DigitalLiteral& l);
//    DigitalLiteral* operator/(const DigitalLiteral& l);
//    DigitalLiteral* div(const DigitalLiteral& l);
//    DigitalLiteral* operator%(const DigitalLiteral& l); // MOD
//    DigitalLiteral* pow(const DigitalLiteral& l);
//    DigitalLiteral* operator-(); // NEG
//    DigitalLiteral* sin();
//    DigitalLiteral* arcsin();
//    DigitalLiteral* cos();
//    DigitalLiteral* arccos();
//    DigitalLiteral* tan();
//    DigitalLiteral* arctan();
//    DigitalLiteral* sqrt();
//    DigitalLiteral* exp();
//    DigitalLiteral* ln();
//    DigitalLiteral* num();
//    DigitalLiteral* den();
//    DigitalLiteral* re();
//    DigitalLiteral* im();
//    DigitalLiteral* arg();
//    DigitalLiteral* norm();

    // Opérateurs logiques
//    DigitalLiteral* operator==(const DigitalLiteral& l);
//    DigitalLiteral* operator!=(const DigitalLiteral& l);
//    DigitalLiteral* operator<(const DigitalLiteral& l);
//    DigitalLiteral* operator<=(const DigitalLiteral& l);
//    DigitalLiteral* operator>(const DigitalLiteral& l);
//    DigitalLiteral* operator>=(const DigitalLiteral& l);
//    DigitalLiteral* operator&&(const DigitalLiteral& l); // AND
//    DigitalLiteral* operator||(const DigitalLiteral& l); // OR
//    DigitalLiteral* operator!(); // NOT

    // Autres
//    QString toString() const;
};

#endif // DIGITAL_LITERAL_H
