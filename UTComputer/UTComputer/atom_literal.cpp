#include "atom_literal.h"

AtomLiteral::AtomLiteral(LiteralFactory* m, const QString& a, Literal* t) : Literal(m), atom(a), target(t){
    atom.replace(" ", ""); // On vire les espaces

    // On vérifie que le nom de la variable est valide
    QRegExp regex("([A-Z][0-9A-Z]+)");

    // On récupère ce qui match
    regex.indexIn(atom, 0);
    QString match = regex.cap(1);

    // Si ce que l'on récupère est différent du nom, alors le nom de la variable n'est pas correct
    if(match != atom)
        throw CalculatorException("Erreur : Le nom de variable " + atom + " n'est pas valide.");

    // On vérifie que ce n'est pas un nom réservé
    if(isOperator(atom) || isFunction(atom))
        throw CalculatorException("Erreur : " + atom + " est réservé.");

    // On va vérifier que ce nom n'existe pas déjà
    // A voir pour implémenter la vérification en tant que méthode
    LiteralFactory& factory = *this->manager;

    for(int i = 0; i < factory.size(); i++){
        // Si on a un atom, on convertit et on check
        Literal& literal = factory[i];

        if(literal.isAtom()){
            AtomLiteral& atomLiteral = dynamic_cast<AtomLiteral&>(literal);

            // On renvoie un erreur si le nom est déjà pris
            if(atom == atomLiteral.atom)
                throw CalculatorException("Erreur : Le nom de variable " + atom + " est déjà utilisé.");
        }
    }
}

// Pour savoir ce que l'on traite
bool AtomLiteral::isInteger() const {return false;}
bool AtomLiteral::isReal() const {return false;}
bool AtomLiteral::isRational() const {return false;}
bool AtomLiteral::isComplex() const {return false;}
bool AtomLiteral::isExpression() const {return false;}
bool AtomLiteral::isProgramm() const {return false;}
bool AtomLiteral::isAtom() const {return true;}

// Opérateurs numériques
Literal& AtomLiteral::operator+(const Literal& l) const {}
Literal& AtomLiteral::operator-(const Literal& l) const {}
Literal& AtomLiteral::operator*(const Literal& l) const {}
Literal& AtomLiteral::operator/(const Literal& l) const {}
Literal& AtomLiteral::div(const Literal& l) const {}
Literal& AtomLiteral::mod(const Literal& l) const {}
Literal& AtomLiteral::pow(const Literal& l) const {}
Literal& AtomLiteral::operator-() const {}
Literal& AtomLiteral::sin() const {
    // On calcule le sinus de la littérale pointée
    // Si jamais l'atome pointe sur un atome, on a un appel récursif jusqu'à tomber sur la destination "finale".
    // A voir si on conserve ce comportement
    return target->sin();
}
Literal& AtomLiteral::arcsin() const {
    try {
        return target->arcsin();
    }
    catch(const CalculatorException& e){
        throw e; // On propage en cas d'erreurs
    }
}
Literal& AtomLiteral::cos() const {
    return target->cos();
}
Literal& AtomLiteral::arccos() const {
    try {
        return target->arccos();
    }
    catch(const CalculatorException& e){
        throw e; // On propage en cas d'erreurs
    }
}
Literal& AtomLiteral::tan() const {
    return target->tan();
}
Literal& AtomLiteral::arctan() const {}
Literal& AtomLiteral::sqrt() const {}
Literal& AtomLiteral::ln() const {}
Literal& AtomLiteral::exp() const {}
Literal& AtomLiteral::num() const {}
Literal& AtomLiteral::den() const {}
Literal& AtomLiteral::re() const {}
Literal& AtomLiteral::im() const {}
Literal& AtomLiteral::arg() const {}
Literal& AtomLiteral::norm() const {}

// Opérateurs logiques
bool AtomLiteral::operator==(const Literal& l) const {}
bool AtomLiteral::operator!=(const Literal& l) const {}
bool AtomLiteral::operator>=(const Literal& l) const {}
bool AtomLiteral::operator>(const Literal& l) const {}
bool AtomLiteral::operator<=(const Literal& l) const {}
bool AtomLiteral::operator<(const Literal& l) const {}
bool AtomLiteral::operator&&(const Literal& l) const {}
bool AtomLiteral::operator||(const Literal& l) const {}
bool AtomLiteral::operator!() const {}

QString AtomLiteral::operator*() const {
    // On retourne la valeur de la variable pointée sous forme de chaine de caractères
    return target->toString();
}
QString AtomLiteral::toString() const {
    // On retourne le nom de la variable
    return atom;
}
