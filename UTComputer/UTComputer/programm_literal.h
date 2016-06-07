#ifndef PROGRAMMLITERAL_H
#define PROGRAMMLITERAL_H

#include "string_literal.h"

class ProgrammLiteral : public StringLiteral {
    friend class LiteralFactory;
private:
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
     * \brief Constructeur de ExpressionLiteral. Vérifie la validité de l'expression à sa création. Renvoie une erreur si jamais elle n'est pas valide.
     * \param Pointeur sur la factory qui a créé l'expression littérale.
     * \param Expression littérale sous forme de chaine de caractères.
     */
    ProgrammLiteral(LiteralFactory* m, const QString& exp);

public:
    bool isExpression() const {return false;}
    bool isProgramm() const {return true;}

    Literal& operator-() const;

    QString eval() const;
    QString toString() const;
};

#endif // PROGRAMMLITERAL_H
