#ifndef PROGRAMMLITERAL_H
#define PROGRAMMLITERAL_H


#include <QString>
#include <QStringList>
#include <QStack>
#include <QRegularExpression>

#include "literal.h"

/*!
 * \brief La classe ProgrammLiteral permet de gérer les expression littérales.
 */
class ProgrammLiteral : public Literal {
    friend class LiteralFactory;

private:
    QString programm;

    /*!
     * \brief Permet d'appliquer un opérateur unaire à l'expression.
     * \param Opérateur à appliquer
     * \return Chaine de caractère sous forme OP(EXP)
     */
    QString concat(const QString& op) const;
    /*!
     * \brief Permet d'appliquer un opérateur binaire à deux expressions.
     * \param Opérateur à appliquer
     * \param Deuxième littérale (expression ou non)
     * \return Chaine de caractère sous forme OP(EXP1, EXP2)
     */
    QString concat(const QString& op, const Literal& l) const;

    // Il y a peut-être d'autres constructeurs à passer en partie privée
    /*!
     * \brief Constructeur de ProgrammLiteral. Vérifie la validité de l'expression à sa création. Renvoie une erreur si jamais elle n'est pas valide.
     * \param Pointeur sur la factory qui a créé l'expression littérale.
     * \param Expression littérale sous forme de chaine de caractères.
     */
    ProgrammLiteral(LiteralFactory* m, const QString& exp);

public:

    // Pour savoir ce que l'on traite
    bool isInteger() const;
    bool isReal() const;
    bool isRational() const;
    bool isComplex() const;
    bool isExpression() const;
    bool isProgramm() const;
    bool isAtom() const;

    // Accesseurs
    /*!
     * \brief Accesseur de l'expression.
     * \return Expression infixe, sans guillemets.
     */
    const QString& getProgramm() const {return programm;}

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
    Literal& $(const Literal &l) const;

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

    QString toString() const;
};

#endif // PROGRAMMLITERAL_H
