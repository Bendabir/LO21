#ifndef NUMBER_H
#define NUMBER_H

#include <QString>
#include <cmath>

/*!
 * \brief La classe Number permet de gérer les nombres entiers, réels ou rationnels.
 * \brief Tout nombre est implicitement un rationnel.
 */

class Number {
private:
    double numerator;
    double denominator;

    /*!
     * \brief Permet de simplifier l'objet Number.
     * \brief Si c'est un ratio de réel, on le transforme en ratio d'entiers, puis on simplifie la fraction.
     */
    void simplify();
    /*!
     * \brief Permet d'uniformiser le signe d'une fraction (signe - sur le numérateur).
     */
    void sign();

public:
    /*!
     * \brief Permet de créer une nombre selon les valeurs des paramètres. La fraction est automatiquement simplifiée, même si c'est un ratio de réels.
     * \param num : Numérateur
     * \param den : Dénominateur
     */
    Number(double num = 0, double den = 1);

    // Accesseurs
    /*!
     * \brief Accesseur sur le numérateur
     * \return Renvoie un réel (double)
     */
    double getNumerator() const {return numerator;}
    /*!
     * \brief Accesseur sur le dénominateur
     * \return Renvoie un réel (double)
     */
    double getDenominator() const {return denominator;}

    // Pour savoir ce que l'on traite
    /*!
     * \brief Détermine si le Number ciblé est un entier.
     * \return Vrai si le nombre ciblé est un entier, faux sinon.
     */
    bool isInteger() const;
    /*!
     * \brief Détermine si le Number ciblé est un réel.
     * \return Vrai si le nombre ciblé est un réel, faux sinon.
     */
    bool isReal() const;
    /*!
     * \brief Détermine si le Number ciblé est un rationnel.
     * \return Vrai si le nombre ciblé est un rationnel, faux sinon.
     */
    bool isRational() const;

    // Opérateurs numériques
    /*!
     * \brief Permet d'additionner deux nombres.
     * \param Nombre à additionner.
     * \return Addition des deux nombres
     */
    Number operator+(const Number& l) const;
    /*!
     * \brief Permet de soustraire deux nombres.
     * \param Nombre à soustraire.
     * \return Soustraction des deux nombres
     */
    Number operator-(const Number& l) const;
    /*!
     * \brief Permet de multiplier deux nombres.
     * \param Nombre à multiplier.
     * \return Multiplication des deux nombres
     */
    Number operator*(const Number& l) const;
    /*!
     * \brief Permet de diviser deux nombres. Provoque une erreur lors d'une tentative de division par 0.
     * \param Diviseur.
     * \return Division des deux nombres
     */
    Number operator/(const Number& l) const;
    /*!
     * \brief Division entière de deux entiers. Provoque une erreur si l'un des nombres n'est pas entier.
     * \param Diviseur.
     * \return Division entière des deux nombres
     */
    Number div(const Number& l) const;
    /*!
     * \brief Renvoie le reste de la division entière de deux entiers. Provoque une erreur si l'un des nombres n'est pas entier.
     * \param Diviseur.
     * \return Reste de la division entière des deux nombres
     */
    Number mod(const Number& l) const;
    /*!
     * \brief Puissance entre deux nombres
     * \param Puissance
     * \return Nombre à la puissance l.
     */
    Number pow(const Number& l) const;
    /*!
     * \brief Opposé d'un nombre
     * \return Opposé d'un nombre
     */
    Number operator-() const;
    /*!
     * \brief Sinus d'un nombre.
     * \return Sinus d'un nombre.
     */
    Number sin() const;
    /*!
     * \brief Arcinus d'un nombre. Provoque une erreur si le nombre est en dehors de l'interval réel [-1; 1]
     * \return Arcsinus d'un nombre.
     */
    Number arcsin() const;
    /*!
     * \brief Cosinus d'un nombre.
     * \return Cosinus d'un nombre.
     */
    Number cos() const;
    /*!
     * \brief Arccosinus d'un nombre. Provoque une erreur si le nombre est en dehors de l'interval réel [-1; 1]
     * \return Arccosinus d'un nombre.
     */
    Number arccos() const;
    /*!
     * \brief Tangente d'un nombre.
     * \return Tangente d'un nombre.
     */
    Number tan() const;
    /*!
     * \brief Arctangente d'un nombre.
     * \return Arctangente d'un nombre.
     */
    Number arctan() const;
    /*!
     * \brief Racine carrée d'un nombre. Provoque une erreur si le nombre est négatif.
     * \return Racine carrée d'un nombre.
     */
    Number sqrt() const;
    /*!
     * \brief Logarithme naturel d'un nombre. Provoque une erreur si le nombre est négatif.
     * \return Logarithme naturel d'un nombre.
     */
    Number ln() const;
    /*!
     * \brief Exponentielle d'un nombre.
     * \return Exponentielle d'un nombre.
     */
    Number exp() const;
    /*!
     * \brief Numérateur d'un nombre. Renvoie le nombre inchangé si c'est un entier. Provoque une erreur si c'est un réel.
     * \return Numérateur d'un nombre.
     */
    Number num() const;
    /*!
     * \brief Dénominateur d'un nombre. Renvoie le nombre 1 si c'est un entier. Provoque une erreur si c'est un réel.
     * \return Dénominateur d'un nombre.
     */
    Number den() const;
    /*!
     * \brief Surchage de l'opérateur d'incrémentation préfixe.
     * \return Référence sur le nombre incrémenté
     */
    Number& operator++();
    /*!
     * \brief Surchage de l'opérateur d'incrémentation postfixe.
     * \return Nombre incrémenté
     */
    Number operator++(int);
    /*!
     * \brief Surchage de l'opérateur de décrémentation préfixe.
     * \return Référence sur le nombre décrémenté
     */
    Number& operator--();
    /*!
     * \brief Surchage de l'opérateur de décrémentation postfixe.
     * \return Nombre décrémenté
     */
    Number operator--(int);

    // Opérateurs logiques
    /*!
     * \brief Compare la valeur de deux nombres.
     * \param Nombre à comparer
     * \return Vrai si les nombres sont égaux, faux sinon.
     */
    bool operator==(const Number& l) const;
    /*!
     * \brief Compare la valeur de deux nombres.
     * \param Nombre à comparer
     * \return Vrai si les nombres sont inégaux, faux sinon.
     */
    bool operator!=(const Number& l) const;
    /*!
     * \brief Compare la valeur de deux nombres.
     * \param Nombre à comparer
     * \return Vrai si le nombre implicite est supérieur ou égal au nombre paramètre, faux sinon.
     */
    bool operator>=(const Number& l) const;
    /*!
     * \brief Compare la valeur de deux nombres.
     * \param Nombre à comparer
     * \return Vrai si le nombre implicite est supérieur au nombre paramètre, faux sinon.
     */
    bool operator>(const Number& l) const;
    /*!
     * \brief Compare la valeur de deux nombres.
     * \param Nombre à comparer
     * \return Vrai si le nombre implicite est inférieur ou égal au nombre paramètre, faux sinon.
     */
    bool operator<=(const Number& l) const;
    /*!
     * \brief Compare la valeur de deux nombres.
     * \param Nombre à comparer
     * \return Vrai si le nombre implicite est inférieur au nombre paramètre, faux sinon.
     */
    bool operator<(const Number& l) const;
    /*!
     * \brief Procède au ET logique entre deux nombres.
     * \param Nombre à utiliser
     * \return Vrai si les deux nombres sont considérés comme vrais (différent de 0), faux sinon.
     */
    bool operator&&(const Number& l) const;
    /*!
     * \brief Procède au OU logique entre deux nombres.
     * \param Nombre à utiliser
     * \return Vrai si l'un des deux nombres sont considérés comme vrais (différent de 0), faux sinon.
     */
    bool operator||(const Number& l) const;
    /*!
     * \brief Procède au NON logique d'un nombre.
     * \return Vrai si le nombre était 0, faux sinon.
     */
    bool operator!() const;

    // Petites surchages des familles pour faciliter les comparaisons
    /*!
     * \brief Renvoie le nombre ciblé sous forme de chaine de caractères.
     * \return Chaine de caractères.
     */
    QString toString() const;
    /*!
     * \brief Convertit un nombre quelconque en réel. Permet de faciliter certaines comparaisons avec les rationnels.
     * \return Réel.
     */
    double toReal() const;

    QString eval() const;
};

/*!
 * \brief Surcharge de l'opérateur << pour les flux ostream pour Number
 * \param Flux où l'on veut afficher le nombre
 * \param Nombre à afficher
 * \return Flux modifié
 */
std::ostream& operator<<(std::ostream& f, const Number& n);

#endif // NUMBER_H
