#ifndef ATOMLITERAL_H
#define ATOMLITERAL_H

#include "literal.h"

class AtomLiteral : public Literal {
    friend class LiteralFactory;

private:
    QString atom;
    Literal* target; // A retravailler car doit pointer sur des opérandes aussi

    /*!
     * \brief Construit une littérale atome à partir d'un nom de variable et de la littérale sur laquelle on souhaite pointer. Provoque une erreur si le nom de la variable n'est pas correct.
     * \param m : Pointeur sur la factory qui a servi à créer la littérale atome
     * \param a : Nom de la variable.
     * \param t : Pointeur sur la littérale référencée par la variable créée
     */
    AtomLiteral(LiteralFactory* m, const QString& a, Literal* t);

public:

    // Accesseurs
    const QString& getAtom() const {return atom;}
    Literal& getTarget() const {return *target;}

    // Pour savoir ce que l'on traite
    bool isInteger() const;
    bool isReal() const;
    bool isRational() const;
    bool isComplex() const;
    bool isExpression() const;
    bool isProgramm() const;
    bool isAtom() const;

    // Opérateurs numériques
    Literal& operator+(const Literal& l) const;
    Literal& operator-(const Literal& l) const;
    Literal& operator*(const Literal& l) const;
    Literal& operator/(const Literal& l) const;
    Literal& div(const Literal& l) const;
    Literal& mod(const Literal& l) const;
    Literal& pow(const Literal& l) const;
    Literal& operator-() const;
    Literal& sin() const;
    Literal& arcsin() const;
    Literal& cos() const;
    Literal& arccos() const;
    Literal& tan() const;
    Literal& arctan() const;
    Literal& sqrt() const;
    Literal& ln() const;
    Literal& exp() const;
    Literal& num() const;
    Literal& den() const;
    Literal& re() const;
    Literal& im() const;
    Literal& arg() const;
    Literal& norm() const;

    // Opérateurs logiques
    bool operator==(const Literal& l) const;
    bool operator!=(const Literal& l) const;
    bool operator>=(const Literal& l) const;
    bool operator>(const Literal& l) const;
    bool operator<=(const Literal& l) const;
    bool operator<(const Literal& l) const;
    bool operator&&(const Literal& l) const;
    bool operator||(const Literal& l) const;
    bool operator!() const;

    QString operator*() const;
    QString toString() const;
};

#endif // ATOMLITERAL_H
