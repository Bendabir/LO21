#ifndef STRINGLITERAL_H
#define STRINGLITERAL_H

#include <QString>
#include <QStringList>
#include <QStack>
#include <QRegularExpression>

#include "literal.h"

#define MAX_LENGTH 150

class StringLiteral : public Literal {
protected:
    QString expression;

    virtual QString concat(const QString& op) const = 0;
    virtual QString concat(const QString& op, const Literal& l) const = 0;

public:
    StringLiteral(LiteralFactory* m, const QString& exp) : Literal(m), expression(exp){}
    virtual ~StringLiteral(){}

    // Pour savoir ce que l'on traite
    bool isInteger() const {return false;}
    bool isReal() const {return false;}
    bool isRational() const {return false;}
    bool isComplex() const {return false;}
//    bool isExpression() const;
//    bool isProgramm() const;
    bool isAtom() const {return false;}

    // Accesseurs
    /*!
     * \brief Accesseur de l'expression.
     * \return Expression infixe, sans guillemets.
     */
    const QString& getExpression() const {return expression;}

    // Opérateurs numériques
    Literal& operator+(const Literal& l) const;
    Literal& operator-(const Literal& l) const;
    Literal& operator*(const Literal& l) const;
    Literal& operator/(const Literal& l) const;
    Literal& div(const Literal& l) const;
    Literal& mod(const Literal& l) const;
    Literal& pow(const Literal& l) const;
//    Literal& operator-() const;
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
    Literal& $(const Literal &l) const;

    // Opérateurs logiques
    Literal& operator==(const Literal& l) const;
    Literal& operator!=(const Literal& l) const;
    Literal& operator>=(const Literal& l) const;
    Literal& operator>(const Literal& l) const;
    Literal& operator<=(const Literal& l) const;
    Literal& operator<(const Literal& l) const;
    Literal& operator&&(const Literal& l) const;
    Literal& operator||(const Literal& l) const;
    Literal& operator!() const;

//    QString eval() const;
//    QString toString() const;
};

#endif // STRINGLITERAL_H
