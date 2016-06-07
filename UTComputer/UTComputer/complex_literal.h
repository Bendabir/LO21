#ifndef COMPLEXLITERAL_H
#define COMPLEXLITERAL_H

#include "literal.h"
#include "number.h"

/*!
 * \brief Classe permettant de gérer les nombres complexes. Composée de deux Number.
 * \brief Un complexe ayant une partie imaginaire nulle se comporte comme un "réel".
 */
class ComplexLiteral : public Literal {
    friend class LiteralFactory;

private:
    Number real;
    Number imaginary;

    // Il y a peut-être d'autres constructeurs à passer en partie privée
    /*!
     * \brief Construit une littérale complexe à partir de deux littérale "réelles" (entières, rationnelles ou réelles). Si la partie imaginaire n'est pas précisée, elle vaut 0.
     * \param m : Pointeur sur la Factory qui a créé le complexe
     * \param re : La partie réelle
     * \param im : La partie imaginaire
     */
    ComplexLiteral(LiteralFactory* m, const Number& re = 0, const Number& im = 0) : Literal(m), real(re), imaginary(im){}

public:

    // Accesseurs
    /*!
     * \brief Accesseur de la partie réelle
     * \return Renvoie une référence constante sur la partie réelle (Number)
     */
    const Number& getReal() const {return real;}
    /*!
     * \brief Accesseur de la partie imaginaire
     * \return Renvoie une référence constante sur la partie imaginaire (Number)
     */
    const Number& getImaginary() const {return imaginary;}

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
    Literal& $(const Literal& l) const;


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

    QString toString() const;
    /*!
     * \brief Renvoie l'argument du complexe sous forme de Number (et non de littérale complexe)
     * \return Argument du complexe
     */
    Number complexArg() const;
    /*!
     * \brief Renvoie le module du complexe sous forme de Number (et non de littérale complexe)
     * \return Module du complexe
     */
    Number complexNorm() const;
    /*!
     * \brief Redéfinition de l'évaluation d'un complexe. Renvoie le complexe sous forme de commande.
     * \brief Exemple : 1$2 --> 1 2 $
     * \return Commande associée au complexe
     */
    QString eval() const;
};

#endif // COMPLEXLITERAL_H
