#ifndef DIGITALLITERAL_H
#define DIGITALLITERAL_H

#include "literal.h"

/*!
 * \brief La classe DigitalLiteral permet de gérer les nombres entiers, réels ou rationnels.
 */

class DigitalLiteral : public Literal {
private:
    double numerator;
    double denominator;

    /*!
     * \brief Permet de simplifier l'objet DigitalLiteral.
     * \brief Si c'est un ratio de réel, on le transforme en ratio d'entiers, puis on simplifie la fraction.
     */
    void simplify();
    /*!
     * \brief Permet d'uniformiser le signe d'une fraction (signe - sur le numérateur).
     */
    void sign();

public:
    /*!
     * \brief Permet de créer une littérale entière selon les valeurs des paramètres. La fraction est automatiquement simplifiée, même si c'est un ratio de réels.
     * \param Numérateur
     * \param Dénominateur
     */
    DigitalLiteral(double num = 0, double den = 1);

    // Pour savoir ce que l'on traite
    bool isInteger() const;
    bool isReal() const;
    bool isRational() const;
    bool isComplex() const;
    bool isExpression() const;
    bool isProgramm() const;

    // Opérateurs numériques
    Literal* operator+(const Literal& l) const;
    Literal* operator-(const Literal& l) const;
    Literal* operator*(const Literal& l) const;
    Literal* operator/(const Literal& l) const;
    Literal* operator+(const Literal* l) const;
    Literal* operator-(const Literal* l) const;
    Literal* operator*(const Literal* l) const;
    Literal* operator/(const Literal* l) const;
    Literal* div(const Literal& l) const;
    Literal* mod(const Literal& l) const;
    Literal* pow(const Literal& l) const;
    Literal* div(const Literal* l) const;
    Literal* mod(const Literal* l) const;
    Literal* pow(const Literal* l) const;
    Literal* operator-() const;
    Literal* sin() const;
    Literal* arcsin() const;
    Literal* cos() const;
    Literal* arccos() const;
    Literal* tan() const;
    Literal* arctan() const;
    Literal* sqrt() const;
    Literal* ln() const;
    Literal* exp() const;
    Literal* num() const;
    Literal* den() const;
    Literal* re() const;
    Literal* im() const;

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

    // Petites surchages des familles pour faciliter les comparaisons
    /*!
     * \brief Permet la comparaison de littérales entières, réelles ou rationnelles avec des réels plus facilement (type de base : int, double).
     * \param d : Valeur à comparer avec la littérale
     * \return Booléen (vrai si égal, faux sinon)
     */
    bool operator==(double d) const;
    /*!
     * \brief Permet la comparaison de littérales entières, réelles ou rationnelles avec des réels plus facilement (type de base : int, double).
     * \param d : Valeur à comparer avec la littérale
     * \return Booléen (vrai si inégal, faux sinon)
     */
    bool operator!=(double d) const;
    /*!
     * \brief Permet la comparaison de littérales entières, réelles ou rationnelles avec des réels plus facilement (type de base : int, double).
     * \param d : Valeur à comparer avec la littérale
     * \return Booléen (vrai si supérieur ou égal, faux sinon)
     */
    bool operator>=(double d) const;
    /*!
     * \brief Permet la comparaison de littérales entières, réelles ou rationnelles avec des réels plus facilement (type de base : int, double).
     * \param d : Valeur à comparer avec la littérale
     * \return Booléen (vrai si supérieur, faux sinon)
     */
    bool operator>(double d) const;
    /*!
     * \brief Permet la comparaison de littérales entières, réelles ou rationnelles avec des réels plus facilement (type de base : int, double).
     * \param d : Valeur à comparer avec la littérale
     * \return Booléen (vrai si inférieur ou égal, faux sinon)
     */
    bool operator<=(double d) const;
    /*!
     * \brief Permet la comparaison de littérales entières, réelles ou rationnelles avec des réels plus facilement (type de base : int, double).
     * \param d : Valeur à comparer avec la littérale
     * \return Booléen (vrai si inférieur, faux sinon)
     */
    bool operator<(double d) const;

    QString toString() const;
    /*!
     * \brief Convertit la littérale (entière, réelle ou rationnelle) en littérale réelle. Permet de faciliter certaines comparaisons avec les rationnels.
     * \return Littérale réelle.
     */
    DigitalLiteral toReal() const;
};

#endif // DIGITALLITERAL_H
