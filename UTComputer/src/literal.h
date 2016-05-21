#ifndef LITERAL_H
#define LITERAL_H

#include "exceptions.h"

/*!
 * \brief The Literal class
 */

class Literal {
private:

public:
    // Constructeurs/Destructeur
    Literal(){}
    Literal(const Literal l){}
    virtual ~Literal(){}

    // Accesseurs

    // Opérateurs numériques
    virtual Literal operator+(const Literal& l) = 0;
    virtual Literal operator-(const Literal& l);
    virtual Literal operator*(const Literal& l) = 0;
    virtual Literal operator/(const Literal& l) = 0;
    virtual Literal div(const Literal& l);
    virtual Literal operator%(const Literal& l) = 0; // MOD
    virtual Literal pow(const Literal& l) = 0;
    virtual Literal operator-() = 0; // NEG
    virtual Literal sin() = 0;
    virtual Literal arcsin() = 0;
    virtual Literal cos() = 0;
    virtual Literal arccos() = 0;
    virtual Literal tan() = 0;
    virtual Literal arctan() = 0;
    virtual Literal sqrt() = 0;
    virtual Literal exp() = 0;
    virtual Literal ln() = 0;
    virtual Literal num() = 0;
    virtual Literal den() = 0;
    virtual Literal re() = 0;
    virtual Literal im() = 0;
    virtual Literal arg() = 0;
    virtual Literal norm() = 0;

    // Opérateurs logiques
    virtual bool operator==(const Literal& l) = 0;
    virtual bool operator!=(const Literal& l) = 0;
    virtual bool operator<(const Literal& l) = 0;
    virtual bool operator<=(const Literal& l) = 0;
    virtual bool operator>(const Literal& l) = 0;
    virtual bool operator>=(const Literal& l) = 0;
    virtual bool operator&&(const Literal& l) = 0; // AND
    virtual bool operator||(const Literal& l) = 0; // OR
    virtual bool operator!(const Literal& l) = 0; // NOT

    // Autres
    const std::string& toString() const = 0;
};

#endif // LITERAL_H
