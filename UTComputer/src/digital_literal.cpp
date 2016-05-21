#include <cmath>

#include "digital_literal.h"

// Fonctions outils
bool isWholeNumber(double n){
    return std::floor(std::abs(n)) == n;
}

// Opérateurs numériques
DigitalLiteral* DigitalLiteral::operator+(const DigitalLiteral& l){
    return new DigitalLiteral(value + l.value); // On pourrait retourner uniquement le résultat car une conversion implicite est faite
}

DigitalLiteral* DigitalLiteral::operator-(const DigitalLiteral& l){
    return new DigitalLiteral(value - l.value);
}

DigitalLiteral* DigitalLiteral::operator*(const DigitalLiteral& l){
    return new DigitalLiteral(value * l.value);
}

DigitalLiteral* DigitalLiteral::operator/(const DigitalLiteral& l){
    if(l.value == 0)
        throw CalculatorException("Erreur : Division par 0 impossible.");

    return new DigitalLiteral(value / l.value);
}

DigitalLiteral* DigitalLiteral::div(const DigitalLiteral& l){
    if(!isWholeNumber(value) || !isWholeNumber(l.value))
        throw CalculatorException("Erreur : La division entière ne peut s'appliquer que sur des entiers.");

    return *this / l;
}

// MOD
DigitalLiteral* DigitalLiteral::operator%(const DigitalLiteral& l){
    if(!isWholeNumber(value) || !isWholeNumber(l.value))
        throw CalculatorException("Erreur : Le modulo ne peut s'appliquer que sur des entiers.");

    return new DigitalLiteral(static_cast<int>(value) % static_cast<int>(l.value));
}

DigitalLiteral* DigitalLiteral::pow(const DigitalLiteral& l){
    return new DigitalLiteral(std::pow(value, l.value));
}

// NEG
DigitalLiteral* DigitalLiteral::operator-(){
    return new DigitalLiteral(-value);
}

DigitalLiteral* DigitalLiteral::sin(){
    return new DigitalLiteral(std::sin(value));
}

DigitalLiteral* DigitalLiteral::arcsin(){
    return new DigitalLiteral(std::asin(value));
}

DigitalLiteral* DigitalLiteral::cos(){
    return new DigitalLiteral(std::cos(value));
}

DigitalLiteral* DigitalLiteral::arccos(){
    return new DigitalLiteral(std::acos(value));
}

DigitalLiteral* DigitalLiteral::tan(){
    return new DigitalLiteral(std::tan(value));
}

DigitalLiteral* DigitalLiteral::arctan(){
    return new DigitalLiteral(std::atan(value));
}

DigitalLiteral* DigitalLiteral::sqrt(){
    if(value < 0)
        throw CalculatorException("Erreur : Impossible de calculer une racine négative.");

    return new DigitalLiteral(std::sqrt(value));
}

DigitalLiteral* DigitalLiteral::exp(){
    return new DigitalLiteral(std::exp(value));
}

DigitalLiteral* DigitalLiteral::ln(){
    if(value < 0)
        throw CalculatorException("Erreur : Impossible de calculer un logarithme négatif.");

    return new DigitalLiteral(std::log(value));
}

DigitalLiteral* DigitalLiteral::num(){
    if(!isWholeNumber(value))
        throw CalculatorException("Erreur : Impossible de calculer le numérateur d'un nombre non-rationnel ou non-entier.");

    return *this;
}

DigitalLiteral* DigitalLiteral::den(){
    if(!isWholeNumber(value))
        throw CalculatorException("Erreur : Impossible de calculer le numérateur d'un nombre non-rationnel ou non-entier.");

    return new DigitalLiteral(1);
}

DigitalLiteral* DigitalLiteral::re(){
    return *this;
}

DigitalLiteral* DigitalLiteral::im(){
    return new DigitalLiteral(0);
}

DigitalLiteral* DigitalLiteral::arg(){
    // A reprendre
    return new DigitalLiteral(0);
}

DigitalLiteral* DigitalLiteral::norm(){
    // A reprendre
    return new DigitalLiteral(0);
}

// Opérateurs logiques
DigitalLiteral* DigitalLiteral::operator==(const DigitalLiteral& l){
    if(value == l.value)
        return new DigitalLiteral(1);
    else
        return new DigitalLiteral(0);
}

DigitalLiteral* DigitalLiteral::operator!=(const DigitalLiteral& l){
    if(value != l.value)
        return new DigitalLiteral(1);
    else
        return new DigitalLiteral(0);
}

DigitalLiteral* DigitalLiteral::operator<(const DigitalLiteral& l){
    if(value < l.value)
        return new DigitalLiteral(1);
    else
        return new DigitalLiteral(0);
}

DigitalLiteral* DigitalLiteral::operator<=(const DigitalLiteral& l){
    if(value <= l.value)
        return new DigitalLiteral(1);
    else
        return new DigitalLiteral(0);
}

DigitalLiteral* DigitalLiteral::operator>(const DigitalLiteral& l){
    if(value > l.value)
        return new DigitalLiteral(1);
    else
        return new DigitalLiteral(0);
}

DigitalLiteral* DigitalLiteral::operator>=(const DigitalLiteral& l){
    if(value >= l.value)
        return new DigitalLiteral(1);
    else
        return new DigitalLiteral(0);
}

// AND
DigitalLiteral* DigitalLiteral::operator&&(const DigitalLiteral& l){
    if(value && l.value)
        return new DigitalLiteral(1);
    else
        return new DigitalLiteral(0);
}

// OR
DigitalLiteral* DigitalLiteral::operator||(const DigitalLiteral& l){
    if(value || l.value)
        return new DigitalLiteral(1);
    else
        return new DigitalLiteral(0);
}

// NOT
DigitalLiteral* DigitalLiteral::operator!(){
    if(!value)
        return new DigitalLiteral(1);
    else
        return new DigitalLiteral(0);
}

// Autres
QString DigitalLiteral::toString() const{
    return QString::number(value);
}
