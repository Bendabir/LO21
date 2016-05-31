#ifndef ATOMLITERAL_H
#define ATOMLITERAL_H

#include "literal.h"

/*!
 * \brief La classe AtomLiteral permet de gérer des "variables" au sein de la calculatrice. Elles pointent (pour le moment) sur d'autres littérales.
 */
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
    /*!
     * \brief Permet de connaitre le nom de la variable.
     * \return Chaine de caractères contenant le nom de la variable.
     */
    const QString& getAtom() const {return atom;}
    /*!
     * \brief Permet de récupérer la littérale pointée par la variable.
     * \brief Si allSons est vrai, alors on récupére la littérale pointée au bout de la chaine de référence (une variable peut pointer sur une variable), sinon on ne récupére que la première littérale fille (nom de la variable pointée).
     * \param allSons : Parcourt complet de la chaine de référence si c'est vrai, ou non si c'est faux. Vrai par défaut.
     * \return Littérale pointée
     */
    Literal& getTarget(bool allSons = true) const;

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

    QString eval() const;
    QString toString() const;
};

#endif // ATOMLITERAL_H
