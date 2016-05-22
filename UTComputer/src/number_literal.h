#ifndef NUMBERLITTERAL_H
#define NUMBERLITTERAL_H

#include "digital_literal.h"

template<class T = int>
class NumberLiteral : public DigitalLiteral {
private:
    T number;

public:
    // Constructeurs/Destructeurs
    NumberLiteral(T n = 0) : number(n){} // On profite de la conversion implicite
    // Recopie par défaut
    // Affectation par défaut
    // Destructeur par défaut

    // Accesseurs
    const T& getNumber() const {return number;}
    void setNumber(const T& n) {number = n;}

    // Opérateurs numériques

    // Opérateurs logiques

    // Autres
    QString toString() const;
};

// On définit des types pour que ce soit plus pratique
typedef NumberLiteral<int> IntegerLiteral;
typedef NumberLiteral<double> RealLiteral;

// Définition des méthodes
template<class T>
QString NumberLiteral<T>::toString() const{
    return QString::number(number);
}

// Prototypes des opérateurs binaires
// +
template<class T>
NumberLiteral<T> operator+(const NumberLiteral<T>& l1, const NumberLiteral<T>& l2){
    return l1.getNumber() + l2.getNumber();
}
template<class T, class U>
RealLiteral operator+(const NumberLiteral<T>& l1, const NumberLiteral<U>& l2){
    return l1.getNumber() + l2.getNumber();
}

// -
template<class T>
NumberLiteral<T> operator-(const NumberLiteral<T>& l1, const NumberLiteral<T>& l2){
    return l1.getNumber() - l2.getNumber();
}
template<class T, class U>
RealLiteral operator-(const NumberLiteral<T>& l1, const NumberLiteral<U>& l2){
    return l1.getNumber() - l2.getNumber();
}

// *
template<class T>
NumberLiteral<T> operator*(const NumberLiteral<T>& l1, const NumberLiteral<T>& l2){
    return l1.getNumber() * l2.getNumber();
}
template<class T, class U>
RealLiteral operator*(const NumberLiteral<T>& l1, const NumberLiteral<U>& l2){
    return l1.getNumber() * l2.getNumber();
}

// /
//template<class T>
//NumberLiteral<T> operator/(const NumberLiteral<T>& l1, const NumberLiteral<T>& l2){
//    return l1.getNumber() / l2.getNumber();
//}
//template<class T, class U>
//RealLiteral operator/(const NumberLiteral<T>& l1, const NumberLiteral<U>& l2){
//    return l1.getNumber() / l2.getNumber();
//}

// DIV
IntegerLiteral div(const IntegerLiteral& l1, const IntegerLiteral& l2);

// MOD
IntegerLiteral operator%(const IntegerLiteral& l1, const IntegerLiteral& l2);
IntegerLiteral mod(const IntegerLiteral& l1, const IntegerLiteral& l2);

#endif // NUMBERLITTERAL_H
