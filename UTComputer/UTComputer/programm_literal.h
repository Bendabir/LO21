#ifndef PROGRAMMLITERAL_H
#define PROGRAMMLITERAL_H

#include "string_literal.h"

class ProgrammLiteral : public StringLiteral {
    friend class LiteralFactory;
private:
    /*!
     * \brief Permet d'appliquer un opérateur unaire au programme
     * \brief Exemple : [ 1 2 + ] SIN --> [ 1 2 + SIN ]
     * \param Opérateur à appliquer
     * \return Nouveau programme composé du programme et de l'opérateur
     */
    QString concat(const QString& op) const;
    /*!
     * \brief Permet d'appliquer un opérateur binaire au programme et une litérale
     * \brief Exemple : [ 1 2 + ] [ 5 SIN ] * --> [ 1 2 + 5 SIN * ]
     * \param Opérateur à appliquer
     * \param Deuxième littérale (programme ou non)
     * \return Nouveau programme composé du programme, de la litérale et de l'opérateur
     */
    QString concat(const QString& op, const Literal& l) const;

    // Il y a peut-être d'autres constructeurs à passer en partie privée
    /*!
     * \brief Constructeur de ProgrammLiteral. Renvoie une erreur si jamais le programme est vide.
     * \param Pointeur sur la factory qui a créé le programme.
     * \param Programme sous forme de chaine de caractères.
     */
    ProgrammLiteral(LiteralFactory* m, const QString& exp);

public:
    bool isExpression() const {return false;}
    bool isProgramm() const {return true;}

    Literal& operator-() const;

    /*!
     * \brief Redéfinition de la fonction eval().
     * \return Le Programme en chaine de caractères, interprétable par la commande (sans les crochets donc).
     */
    QString eval() const;
    /*!
     * \brief Renvoie le programme sous forme de chaine de caractères avec les crochets.
     * \return Programme.
     */
    QString toString() const;
};

#endif // PROGRAMMLITERAL_H
