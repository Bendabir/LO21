#ifndef EXPRESSIONLITERAL_H
#define EXPRESSIONLITERAL_H

#include <QString>
#include <QStringList>
#include <QStack>
#include <QRegularExpression>

#include "literal.h"

/*!
 * \brief La classe ExpressionLiteral permet de gérer les expression littérales.
 */
class ExpressionLiteral : public Literal {
    friend class LiteralFactory;

private:
    QString expression;

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
    ExpressionLiteral(LiteralFactory* m, const QString& exp);

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
    const QString& getExpression() const {return expression;}

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
    Literal& operator==(const Literal& l) const;
    Literal& operator!=(const Literal& l) const;
    Literal& operator>=(const Literal& l) const;
    Literal& operator>(const Literal& l) const;
    Literal& operator<=(const Literal& l) const;
    Literal& operator<(const Literal& l) const;
    Literal& operator&&(const Literal& l) const;
    Literal& operator||(const Literal& l) const;
    Literal& operator!() const;

    QString eval() const;
    QString toString() const;

    /*!
     * \brief Permet d'évaluer une expression littérale.
     * \brief Renvoie l'expression évaluée sous forme de chaine de caractères si elle est valide ou une erreur si elle ne l'est pas.
     * \return Chaine de caractère évaluée
     */
    QString evaluate() const;
    /*!
     * \brief Vérifie si une expression est valide en tentant son évaluation.
     * \return Vrai si l'évaluation réussie, faux sinon
     */
    bool isValid() const;
    /*!
     * \brief Calcule le nombre de tokens (opérateurs, nombres, variables, etc.) contenus dans l'expression.
     * \return Nombre de tokens
     */
    unsigned int nbTokens() const;
    /*!
     * \brief Renvoie la liste des tokens (opérateurs, nombres, variables, etc.) contenus dans l'expression.
     * \return Liste de chaines de caractères.
     */
    QStringList getTokens() const;
    /*!
     * \brief Renvoie la priorité minimale des opérateurs dans les parties non-parenthésées de l'expression.
     * \brief Utile pour le parenthèsage des expressions lors des opérations entre expressions.
     * \return Priorité minimale de l'expression.
     */
    int priority() const;
};
#endif // EXPRESSIONLITERAL_H
