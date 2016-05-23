#include "rational_literal.h"

QString RationalLiteral::toString() const {
    QString str = QString::number(numerator.getNumber());

    // On affiche le dénominateur seulement s'il est différent de 1
    if(denominator != 1)
        str += "/" + QString::number(denominator.getNumber());

    return str;
}

RealLiteral RationalLiteral::toReal() const {
    return (static_cast<double>(numerator.getNumber()) / denominator.getNumber());
}

void RationalLiteral::simplify() {
    if(numerator == 0){
        denominator = 1;
        return;
    }

    /* un denominateur ne devrait pas être 0;
    si c’est le cas, on sort de la méthode */
    if(denominator == 0)
        return;

    /* utilisation de l’algorithme d’Euclide pour trouver le Plus Grand Commun
    Denominateur (PGCD) entre le numerateur et le denominateur */
    IntegerLiteral a = numerator,
        b = denominator;

    // on ne travaille qu’avec des valeurs positives...
    if(a < 0)
        a = -a;
    if(b < 0)
        b = -b;

    while(a!=b){
        if(a > b)
            a = a - b;
        else
            b = b - a;
    }

    // on divise le numerateur et le denominateur par le PGCD=a
    numerator = div(numerator, a);
    denominator = div(denominator, a);

    // si le denominateur est négatif, on fait passer le signe - au denominateur
    if(denominator < 0){
        denominator = -denominator;
        numerator = -numerator;
    }
}

// +
RationalLiteral RationalLiteral::operator+(const RationalLiteral& q) const {
    IntegerLiteral a = numerator,
                   b = denominator,
                   c = q.numerator,
                   d = q.denominator;
    return RationalLiteral(a * d + b * c, b * d);
}

// -
RationalLiteral RationalLiteral::operator-(const RationalLiteral& q) const {
    IntegerLiteral a = numerator,
                   b = denominator,
                   c = q.numerator,
                   d = q.denominator;
    return RationalLiteral(a * d - b * c, b * d);
}

// *
RationalLiteral RationalLiteral::operator*(const RationalLiteral& q) const {
    IntegerLiteral a = numerator,
                   b = denominator,
                   c = q.numerator,
                   d = q.denominator;
    return RationalLiteral(a * c, b * d);
}

// /
RationalLiteral RationalLiteral::operator/(const RationalLiteral& q) const {
    IntegerLiteral a = numerator,
                   b = denominator,
                   c = q.numerator,
                   d = q.denominator;
    return RationalLiteral(a * d, b * c);
}


// Autres opérateurs utiles
RationalLiteral& RationalLiteral::operator++(){
    *this = *this + IntegerLiteral(1);
    return *this;
}
RationalLiteral RationalLiteral::operator++(int){
    RationalLiteral temp = *this;
    ++*this;
    return temp;
}

RationalLiteral& RationalLiteral::operator--(){
    *this = *this - IntegerLiteral(1);
    return *this;
}

RationalLiteral RationalLiteral::operator--(int){
    RationalLiteral temp = *this;
    --*this;
    return *this;
}

