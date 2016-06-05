#include "programm_literal.h"
#include "complex_literal.h"

#define MAX_LENGTH 150

QString ProgrammLiteral::concat(const QString& op) const {
    // On ne traite que des fonctions
    QString exp = toString() + " " + op;
    return exp;
}

QString ProgrammLiteral::concat(const QString& op, const Literal& l) const {
    QString exp;

    exp = toString() + " " + l.toString() + " " + op;

    return exp;
}

ProgrammLiteral::ProgrammLiteral(LiteralFactory* m, const QString& exp) : Literal(m), programm(exp){
    // On vire les espaces au début
    programm = programm.trimmed();

    // Si le programme est vide, on ne prend pas
    if(programm.length() == 0)
        throw CalculatorException("Erreur : Le programme entré est vide.");
}

// Pour savoir ce que l'on traite
bool ProgrammLiteral::isInteger() const {return false;}
bool ProgrammLiteral::isReal() const {return false;}
bool ProgrammLiteral::isRational() const {return false;}
bool ProgrammLiteral::isComplex() const {return false;}
bool ProgrammLiteral::isExpression() const {return false;}
bool ProgrammLiteral::isProgramm() const {return true;}
bool ProgrammLiteral::isAtom() const {return false;}

// Opérateurs numériques
Literal& ProgrammLiteral::operator+(const Literal& l) const {
    // Ici, on ne se prend pas la tête : Dans tous les cas, la litérale passée en argument devient une expression
    return this->manager->addLiteral(concat("+", l));
}
Literal& ProgrammLiteral::operator-(const Literal& l) const {
    return this->manager->addLiteral(concat("-", l));
}
Literal& ProgrammLiteral::operator*(const Literal& l) const {
    return this->manager->addLiteral(concat("*", l));
}
Literal& ProgrammLiteral::operator/(const Literal& l) const {
    return this->manager->addLiteral(concat("/", l));
}
// On va peut être ajouter des sécurités sur les conversions
Literal& ProgrammLiteral::div(const Literal& l) const {
    return this->manager->addLiteral(concat("DIV", l));
}
Literal& ProgrammLiteral::mod(const Literal& l) const {
    return this->manager->addLiteral(concat("MOD", l));
}
Literal& ProgrammLiteral::pow(const Literal& l) const {
    return this->manager->addLiteral(concat("POW", l));
}
Literal& ProgrammLiteral::operator-() const {
    QString result = toString() + " NEG";

    return this->manager->addLiteral(result);
}
Literal& ProgrammLiteral::sin() const {
    return this->manager->addLiteral(concat("SIN"));
}
Literal& ProgrammLiteral::arcsin() const {
    return this->manager->addLiteral(concat("ARCSIN"));
}
Literal& ProgrammLiteral::cos() const {
    return this->manager->addLiteral(concat("COS"));
}
Literal& ProgrammLiteral::arccos() const {
    return this->manager->addLiteral(concat("ARCCOS"));
}
Literal& ProgrammLiteral::tan() const {
    return this->manager->addLiteral(concat("TAN"));
}
Literal& ProgrammLiteral::arctan() const {
    return this->manager->addLiteral(concat("ARCTAN"));
}
Literal& ProgrammLiteral::sqrt() const {
    return this->manager->addLiteral(concat("SQRT"));
}
Literal& ProgrammLiteral::ln() const {
    return this->manager->addLiteral(concat("LN"));
}
Literal& ProgrammLiteral::exp() const {
    return this->manager->addLiteral(concat("SIN"));
}
Literal& ProgrammLiteral::num() const {
    return this->manager->addLiteral(concat("NUM"));
}
Literal& ProgrammLiteral::den() const {
    return this->manager->addLiteral(concat("DEN"));
}
Literal& ProgrammLiteral::re() const {
    return this->manager->addLiteral(concat("RE"));
}
Literal& ProgrammLiteral::im() const {
    return this->manager->addLiteral(concat("IM"));
}
Literal& ProgrammLiteral::arg() const {
    return this->manager->addLiteral(concat("ARG"));
}
Literal& ProgrammLiteral::norm() const {
    return this->manager->addLiteral(concat("NORM"));
}
Literal& ProgrammLiteral::$(const Literal &l) const {
    return this->manager->addLiteral(concat("$", l));
}

// Opérateurs logiques
// Pour le moment, on compare juste sur les chaines évaluées.
// A voir si on fait le calcul des chaines et on vérifie que la valeur renvoyée est identique
bool ProgrammLiteral::operator==(const Literal& l) const {
    // On vérifie que l'évaluation des chaînes donne la même chose
    // Cela permet de faire abstraction des parenthèses de priorité (parfois superflues) dans les expressions
    return this->eval() == l.eval();
}
bool ProgrammLiteral::operator!=(const Literal& l) const {
    return this->eval() != l.eval();
}
bool ProgrammLiteral::operator>=(const Literal& l) const {
    return this->eval() >= l.eval();
}
bool ProgrammLiteral::operator>(const Literal& l) const  {
    return this->eval() > l.eval();
}
bool ProgrammLiteral::operator<=(const Literal& l) const  {
    return this->eval() <= l.eval();
}
bool ProgrammLiteral::operator<(const Literal& l) const  {
    return this->eval() < l.eval();
}
bool ProgrammLiteral::operator&&(const Literal& l) const {
    // Si la littérale passée en argument est un entier
    if(l.isInteger() && l.isComplex()){
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        return Number(1) && literal.getReal();
    }
    else
        return true; // Forcément des littérales différentes de 0
}
bool ProgrammLiteral::operator||(const Literal& l) const {
    return true; // Vrai dans tous les cas
}
bool ProgrammLiteral::operator!() const {
    return false; // Toujours faux
}

QString ProgrammLiteral::toString() const {
    QString expression = programm;
    expression.replace("\t", " ");
    expression.replace("\n", " ");

    int nbMaxChar = MAX_LENGTH - 7;

    QString result = "[ " + expression.mid(0, nbMaxChar);

    if(expression.length() > nbMaxChar)
        result += "...";

    result += " ]";
    return result;
}

