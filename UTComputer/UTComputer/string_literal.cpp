#include "string_literal.h"
#include "complex_literal.h"

#define MAX_LENGTH 150

// Opérateurs numériques
Literal& StringLiteral::operator+(const Literal& l) const {
    // Ici, on ne se prend pas la tête : Dans tous les cas, la litérale passée en argument devient une expression
    return this->manager->addLiteral(concat("+", l));
}
Literal& StringLiteral::operator-(const Literal& l) const {
    return this->manager->addLiteral(concat("-", l));
}
Literal& StringLiteral::operator*(const Literal& l) const {
    return this->manager->addLiteral(concat("*", l));
}
Literal& StringLiteral::operator/(const Literal& l) const {
    return this->manager->addLiteral(concat("/", l));
}
// On va peut être ajouter des sécurités sur les conversions
Literal& StringLiteral::div(const Literal& l) const {
    return this->manager->addLiteral(concat("DIV", l));
}
Literal& StringLiteral::mod(const Literal& l) const {
    return this->manager->addLiteral(concat("MOD", l));
}
Literal& StringLiteral::pow(const Literal& l) const {
    return this->manager->addLiteral(concat("POW", l));
}

Literal& StringLiteral::sin() const {
    return this->manager->addLiteral(concat("SIN"));
}
Literal& StringLiteral::arcsin() const {
    return this->manager->addLiteral(concat("ARCSIN"));
}
Literal& StringLiteral::cos() const {
    return this->manager->addLiteral(concat("COS"));
}
Literal& StringLiteral::arccos() const {
    return this->manager->addLiteral(concat("ARCCOS"));
}
Literal& StringLiteral::tan() const {
    return this->manager->addLiteral(concat("TAN"));
}
Literal& StringLiteral::arctan() const {
    return this->manager->addLiteral(concat("ARCTAN"));
}
Literal& StringLiteral::sqrt() const {
    return this->manager->addLiteral(concat("SQRT"));
}
Literal& StringLiteral::ln() const {
    return this->manager->addLiteral(concat("LN"));
}
Literal& StringLiteral::exp() const {
    return this->manager->addLiteral(concat("SIN"));
}
Literal& StringLiteral::num() const {
    return this->manager->addLiteral(concat("NUM"));
}
Literal& StringLiteral::den() const {
    return this->manager->addLiteral(concat("DEN"));
}
Literal& StringLiteral::re() const {
    return this->manager->addLiteral(concat("RE"));
}
Literal& StringLiteral::im() const {
    return this->manager->addLiteral(concat("IM"));
}
Literal& StringLiteral::arg() const {
    return this->manager->addLiteral(concat("ARG"));
}
Literal& StringLiteral::norm() const {
    return this->manager->addLiteral(concat("NORM"));
}
Literal& StringLiteral::$(const Literal &l) const {
    return this->manager->addLiteral(concat("$", l));
}

// Opérateurs logiques
// Pour le moment, on compare juste sur les chaines évaluées.
// A voir si on fait le calcul des chaines et on vérifie que la valeur renvoyée est identique
Literal& StringLiteral::operator==(const Literal& l) const {
    // On vérifie que l'évaluation des chaînes donne la même chose
    // Cela permet de faire abstraction des parenthèses de priorité (parfois superflues) dans les expressions
    return this->manager->addBoolLiteral(eval() == l.eval());
}
Literal& StringLiteral::operator!=(const Literal& l) const {
    return this->manager->addBoolLiteral(eval() != l.eval());
}
Literal& StringLiteral::operator>=(const Literal& l) const {
    return this->manager->addBoolLiteral(eval() >= l.eval());
}
Literal& StringLiteral::operator>(const Literal& l) const  {
    return this->manager->addBoolLiteral(eval() > l.eval());
}
Literal& StringLiteral::operator<=(const Literal& l) const  {
    return this->manager->addBoolLiteral(eval() <= l.eval());
}
Literal& StringLiteral::operator<(const Literal& l) const  {
    return this->manager->addBoolLiteral(eval() < l.eval());
}
Literal& StringLiteral::operator&&(const Literal& l) const {
    // Si la littérale passée en argument est un entier
    if(l.isInteger() && l.isComplex()){
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        return this->manager->addBoolLiteral(Number(1) && literal.getReal());
    }
    else
        return this->manager->addBoolLiteral(true); // Forcément des littérales différentes de 0
}
Literal& StringLiteral::operator||(const Literal& l) const {
    return this->manager->addBoolLiteral(true); // Vrai dans tous les cas
}
Literal& StringLiteral::operator!() const {
    return this->manager->addBoolLiteral(false); // Toujours faux
}
