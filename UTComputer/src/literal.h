#ifndef LITERAL_H
#define LITERAL_H

#include <QString>
#include <cmath>

#include "exceptions.h"

/*!
 * \brief The Literal class
 */

class Literal {
private:

public:
    // Constructeurs/Destructeur
    Literal(){}
    // Constructeur de recopie par défaut
    // Opérateur d'affectation par défaut
    virtual ~Literal(){}

    // Accesseurs

    // Opérateurs numériques
    // Pour le moment, on fait des retours par pointeur un peu dégueu
    // A terme, tout sera géré par la factory
//    virtual const Literal& operator+(const Literal& l) const = 0;
//    virtual Literal* operator-(const Literal& l) = 0;
//    virtual Literal* operator*(const Literal& l) = 0;
//    virtual Literal* operator/(const Literal& l) = 0;
//    virtual Literal* div(const Literal& l) = 0;
//    virtual Literal* operator%(const Literal& l) = 0; // MOD
//    virtual Literal* pow(const Literal& l) = 0;
//    virtual Literal* operator-() = 0; // NEG
//    virtual Literal* sin() = 0;
//    virtual Literal* arcsin() = 0;
//    virtual Literal* cos() = 0;
//    virtual Literal* arccos() = 0;
//    virtual Literal* tan() = 0;
//    virtual Literal* arctan() = 0;
//    virtual Literal* sqrt() = 0;
//    virtual Literal* exp() = 0;
//    virtual Literal* ln() = 0;
//    virtual Literal* num() = 0;
//    virtual Literal* den() = 0;
//    virtual Literal* re() = 0;
//    virtual Literal* im() = 0;
//    virtual Literal* arg() = 0;
//    virtual Literal* norm() = 0;

    // Opérateurs logiques
    // On retourne des bool mais ne serait-il pas mieux de retourner des NumberLiteral<int>(1) ou NumberLiteral<int>(0) ?
//    virtual Literal* operator==(const Literal& l) = 0;
//    virtual Literal* operator!=(const Literal& l) = 0;
//    virtual Literal* operator<(const Literal& l) = 0;
//    virtual Literal* operator<=(const Literal& l) = 0;
//    virtual Literal* operator>(const Literal& l) = 0;
//    virtual Literal* operator>=(const Literal& l) = 0;
//    virtual Literal* operator&&(const Literal& l) = 0; // AND
//    virtual Literal* operator||(const Literal& l) = 0; // OR
//    virtual Literal* operator!() = 0; // NOT

    // Autres
    virtual QString toString() const = 0;
};

// Prototypes
std::ostream& operator<<(std::ostream& f, const Literal& l);

#endif // LITERAL_H
