#ifndef EXPRESSIONLITERAL_H
#define EXPRESSIONLITERAL_H

#include <QString>
#include <QStringList>
#include <QStack>
#include <QRegularExpression>

#include "string_literal.h"

/*!
 * \brief La classe ExpressionLiteral permet de gérer les expression littérales. Elle hérite d'une classe intermédiaire, spécialisée dans les Literal à base de chaine de caractères.
 */
class ExpressionLiteral : public StringLiteral {
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
    ExpressionLiteral(LiteralFactory* m, const QString& exp);

public:
    // Pour savoir ce que l'on traite
    bool isExpression() const {return true;}
    bool isProgramm() const {return false;}

    Literal& operator-() const;

    /*!
     * \brief Réimplémentation de la fonction eval() qui retourne maintenant une chaine de caractères interprétable par la commande, correspondant à l'expression infixe évaluée.
     * \return Commande postfixe
     */
    QString eval() const;
    /*!
     * \brief Permet d'afficher l'expression (possiblement tronquée)
     * \return Expression postfixe, entre single quotes.
     */
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
