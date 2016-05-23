#ifndef NUMBERLITTERAL_H
#define NUMBERLITTERAL_H

#include "digital_literal.h"

// NOTE : Certaines fonctions/opérations sont implémentables en temps que méthodes

template<class T = int>
class NumberLiteral : public DigitalLiteral {
private:
    T number;

public:
    // Constructeurs/Destructeurs
    NumberLiteral(T n = 0) : DigitalLiteral(), number(n){} // On profite de la conversion implicite
    // Recopie par défaut
    // Affectation par défaut
    // Destructeur par défaut

    // Accesseurs
    const T& getNumber() const {return number;}
    void setNumber(const T& n) {number = n;}

    // Opérateurs numériques
    NumberLiteral<T>& operator++();
    NumberLiteral<T> operator++(int);
    NumberLiteral<T>& operator--();
    NumberLiteral<T> operator--(int);

    // Opérateurs logiques
    bool operator==(const NumberLiteral<T>& l) const;
    bool operator!=(const NumberLiteral<T>& l) const;
    bool operator<=(const NumberLiteral<T>& l) const;
    bool operator<(const NumberLiteral<T>& l) const;
    bool operator>=(const NumberLiteral<T>& l) const;
    bool operator>(const NumberLiteral<T>& l) const;

    // Manque AND, OR et NOT

    // Opérateurs
    NumberLiteral<T>& operator=(T n);

    // Autres
    QString toString() const;
};

// On définit des types pour que ce soit plus pratique
typedef NumberLiteral<int> IntegerLiteral;
typedef NumberLiteral<double> RealLiteral;

// Définition des méthodes
template<class T>
QString NumberLiteral<T>::toString() const {
    return QString::number(number);
}

template<class T>
NumberLiteral<T>& NumberLiteral<T>::operator++(){
    ++number;
    return *this;
}
template<class T>
NumberLiteral<T> NumberLiteral<T>::operator++(int){
    NumberLiteral<T> temp = *this;
    ++*this;
    return temp;
}
template<class T>
NumberLiteral<T>& NumberLiteral<T>::operator--(){
    --number;
    return *this;
}
template<class T>
NumberLiteral<T> NumberLiteral<T>::operator--(int){
    NumberLiteral<T> temp = *this;
    --*this;
    return temp;
}

// Opérateurs logiques
template<class T>
bool NumberLiteral<T>::operator==(const NumberLiteral<T>& l) const {
    return number == l.number;
}
template<class T>
bool NumberLiteral<T>::operator!=(const NumberLiteral<T>& l) const {
    return number != l.number;
}
template<class T>
bool NumberLiteral<T>::operator<=(const NumberLiteral<T>& l) const {
    return number <= l.number;
}
template<class T>
bool NumberLiteral<T>::operator<(const NumberLiteral<T>& l) const {
    return number < l.number;
}
template<class T>
bool NumberLiteral<T>::operator>=(const NumberLiteral<T>& l) const {
    return number >= l.number;
}
template<class T>
bool NumberLiteral<T>::operator>(const NumberLiteral<T>& l) const {
    return number > l.number;
}

// Opérateurs
template<class T>
NumberLiteral<T>& NumberLiteral<T>::operator=(T n){
    number = n;
    return *this;
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
//IntegerLiteral mod(const IntegerLiteral& l1, const IntegerLiteral& l2);

// POW
template<class T>
NumberLiteral<T> pow(const NumberLiteral<T>& l1, const NumberLiteral<T>& l2){
    return std::pow(l1.getNumber(), l2.getNumber());
}
template<class T, class U>
RealLiteral pow(const NumberLiteral<T>& l1, const NumberLiteral<U>& l2){
    return std::pow(l1.getNumber(), l2.getNumber());
}

// NEG
template<class T>
NumberLiteral<T> operator-(const NumberLiteral<T>& l){
    return -l.getNumber();
}
//template<class T>
//NumberLiteral<T> neg(const NumberLiteral<T>& l){
//    return -l;
//}

// SIN, ARCSIN, COS, ARCCOS, TAN, ARCTAN
template<class T>
RealLiteral sin(const NumberLiteral<T>& l){
    return std::sin(l.getNumber());
}
template<class T>
RealLiteral arcsin(const NumberLiteral<T>& l){
    if(l < -1 || l > 1)
        throw CalculatorException("Erreur : L'ensemble de définition de ARCSIN est [-1; 1].");

    return std::asin(l.getNumber());
}
template<class T>
RealLiteral cos(const NumberLiteral<T>& l){
    return std::cos(l.getNumber());
}
template<class T>
RealLiteral arccos(const NumberLiteral<T>& l){
    if(l < -1 || l > 1)
        throw CalculatorException("Erreur : L'ensemble de définition de ARCCOS est [-1; 1].");

    return std::acos(l.getNumber());
}
template<class T>
RealLiteral tan(const NumberLiteral<T>& l){
    return std::tan(l.getNumber());
}
template<class T>
RealLiteral arctan(const NumberLiteral<T>& l){
    return std::atan(l.getNumber());
}

// SQRT
template<class T>
RealLiteral sqrt(const NumberLiteral<T>& l){
    if(l < 0)
        throw CalculatorException("Erreur : Impossible de calculer une racine carrée négative.");

    return std::sqrt(l.getNumber());
}

// EXP
template<class T>
RealLiteral exp(const NumberLiteral<T>& l){
    return std::exp(l.getNumber());
}

// LN
template<class T>
RealLiteral ln(const NumberLiteral<T>& l){
    if(l <= 0)
        throw CalculatorException("Erreur : le paramètre d'un logarithme est forcément positif.");

    return std::log(l.getNumber());
}

// NUM
IntegerLiteral num(const IntegerLiteral& l);
RealLiteral num(const RealLiteral& l);

// DEN
IntegerLiteral den(const IntegerLiteral& l);
RealLiteral den(const RealLiteral& l);

// $

// RE
template<class T>
NumberLiteral<T> re(const NumberLiteral<T>& l){
    return l;
}

// IM
template<class T>
NumberLiteral<T> im(const NumberLiteral<T>& l){
    return 0;
}

// ARG
// On fera l'implémentation en déclarant un complexe à partir d'un entier/réel puis en retournant sa norme/argument

// NORM


// Autres opérateurs utiles
template<class T, class U>
NumberLiteral<T>& operator+=(NumberLiteral<T>& l1, const NumberLiteral<U>& l2){
    l1 = l1 + l2;
    return l1;
}
template<class T, class U>
NumberLiteral<T>& operator-=(NumberLiteral<T>& l1, const NumberLiteral<U>& l2){
    l1 = l1 - l2;
    return l1;
}
template<class T, class U>
NumberLiteral<T>& operator*=(NumberLiteral<T>& l1, const NumberLiteral<U>& l2){
    l1 = l1 * l2;
    return l1;
}
template<class T, class U>
NumberLiteral<T>& operator/=(NumberLiteral<T>& l1, const NumberLiteral<U>& l2){
    if(l2 == 0)
        throw CalculatorException("Erreur : Division par 0 impossible.");

    l1 = l1 / l2;
    return l1;
}

#endif // NUMBERLITTERAL_H
