#include <QtMath>

#include "complex_literal.h"
#include "expression_literal.h"
#include "atom_literal.h"

// Pour savoir ce que l'on traite
bool ComplexLiteral::isInteger() const {
    // Si la partie imaginaire est nulle, on regarde la partie réelle
    if(imaginary == 0)
        return real.isInteger();
    else
        return false;
}
bool ComplexLiteral::isReal() const {
    // Si la partie imaginaire est nulle, on regarde la partie réelle
    if(imaginary == Number(0))
        return real.isReal();
    else
        return false;
}
bool ComplexLiteral::isRational() const {
    // Si la partie imaginaire est nulle, on regarde la partie réelle
    if(imaginary == Number(0))
        return real.isRational();
    else
        return false;
}
bool ComplexLiteral::isComplex() const {
    // Même si la partie imaginaire est nulle, on a quand même un complexe (qui peut être entier, réel ou rationnel si cette partie est nulle)
    return true;
}
bool ComplexLiteral::isExpression() const {return false;}
bool ComplexLiteral::isProgramm() const {return false;}
bool ComplexLiteral::isAtom() const {return false;}

// Opérateurs numériques
Literal& ComplexLiteral::operator+(const Literal& l) const {
    if(l.isComplex()){
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        return this->manager->addLiteral(real + literal.real, imaginary + literal.imaginary);
    }
    // Si on a une expression littérale
    else if(l.isExpression()){
        const ExpressionLiteral& expressionArgument = dynamic_cast<const ExpressionLiteral&>(l);
        int operatorPriority = getPriority("+");

        QString result = this->toString() + " + ";

        if(operatorPriority > expressionArgument.priority())
            result += "(" ;

        result += expressionArgument.getExpression();

        if(operatorPriority > expressionArgument.priority())
            result += ")" ;

        return this->manager->addLiteral(result);
    }
    else if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        return *this + literal.getTarget();
    }
    else if(l.isProgramm()){
        QString programm = "[ " + eval() + " " + l.eval() + " + ]";
        return this->manager->addLiteral(programm);
    }
    else
        throw CalculatorException("Erreur : Impossible d'appliquer l'opérateur + sur ces opérandes.");

    // Autres cas
}
Literal& ComplexLiteral::operator-(const Literal& l) const {
    // Pas vraiment possible de réutiliser l'addition dans ce cas
    if(l.isComplex()){
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        return this->manager->addLiteral(real - literal.real, imaginary - literal.imaginary);
    }
    else if(l.isExpression()){
        const ExpressionLiteral& expressionArgument = dynamic_cast<const ExpressionLiteral&>(l);
        int operatorPriority = getPriority("-");

        QString result = this->toString() + " - ";

        if(operatorPriority > expressionArgument.priority())
            result += "(" ;

        result += expressionArgument.getExpression();

        if(operatorPriority > expressionArgument.priority())
            result += ")" ;

        return this->manager->addLiteral(result);
    }
    else if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        return *this - literal.getTarget();
    }
    else if(l.isProgramm()){
        QString programm = "[ " + eval() + " " + l.eval() + " - ]";
        return this->manager->addLiteral(programm);
    }
    else
        throw CalculatorException("Erreur : Impossible d'appliquer l'opérateur + sur ces opérandes.");
}
Literal& ComplexLiteral::operator*(const Literal& l) const {
    if(l.isComplex()){
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        // (a + ib) * (c + id) = (ac - bd) + i(ad + bc)
        Number a = real,
               b = imaginary,
               c = literal.real,
               d = literal.imaginary;

        return this->manager->addLiteral(a*c - b*d, a*d + b*c);
    }
    else if(l.isExpression()){
        const ExpressionLiteral& expressionArgument = dynamic_cast<const ExpressionLiteral&>(l);
        int operatorPriority = getPriority("*");

        QString result = this->toString() + " * ";

        if(operatorPriority > expressionArgument.priority())
            result += "(" ;

        result += expressionArgument.getExpression();

        if(operatorPriority > expressionArgument.priority())
            result += ")" ;

        return this->manager->addLiteral(result);
    }
    else if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        return *this * literal.getTarget();
    }
    else if(l.isProgramm()){
        QString programm = "[ " + eval() + " " + l.eval() + " * ]";
        return this->manager->addLiteral(programm);
    }
    else
        throw CalculatorException("Erreur : Impossible d'appliquer l'opérateur + sur ces opérandes.");
}
Literal& ComplexLiteral::operator/(const Literal& l) const {
    if(l.isComplex()){
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        // Si le complexe argument vaut 0
        if(literal.isInteger() && literal.real == 0)
            throw CalculatorException("Erreur : La division par 0 est impossible.");

        Number a = real,
               b = imaginary,
               c = literal.real,
               d = literal.imaginary;

        // On tente la division
        try {
            // (a + ib)/(c + id) = [(ac + bd) + i(bc - ad)]/[c^2 + d^2]
            Number re = (a*c + b*d),
                   im = (b*c - a*d);

            return this->manager->addLiteral(re, im);
        }
        catch(const CalculatorException& e){
            throw e; // On propage le problème
        }
    }
    else if(l.isExpression()){
        const ExpressionLiteral& expressionArgument = dynamic_cast<const ExpressionLiteral&>(l);
        int operatorPriority = getPriority("/");

        QString result = this->toString() + " / ";

        if(operatorPriority > expressionArgument.priority())
            result += "(" ;

        result += expressionArgument.getExpression();

        if(operatorPriority > expressionArgument.priority())
            result += ")" ;

        return this->manager->addLiteral(result);
    }
    else if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        try{
            return *this / literal.getTarget();
        }
        catch(const CalculatorException& e){
            throw e; // On propage à cause du ping-pong
        }
    }
    else if(l.isProgramm()){
        QString programm = "[ " + eval() + " " + l.eval() + " / ]";
        return this->manager->addLiteral(programm);
    }
    else
        throw CalculatorException("Erreur : Impossible d'appliquer l'opérateur + sur ces opérandes.");
}
Literal& ComplexLiteral::div(const Literal& l) const {
    // Ne s'applique que sur des entiers
    if(isInteger() && l.isInteger() && l.isComplex()){
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        // On effectue la divion
        return this->manager->addLiteral(real.div(literal.real));
    }
    else if(l.isExpression()){
        const ExpressionLiteral& literal = dynamic_cast<const ExpressionLiteral&>(l);

        QString result = "DIV(" + this->toString() + ", " + literal.getExpression() + ")";

        return this->manager->addLiteral(result);
    }
    else if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        try {
            return this->div(literal.getTarget());
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
    else if(l.isProgramm()){
        QString programm = "[ " + eval() + " " + l.eval() + " DIV ]";
        return this->manager->addLiteral(programm);
    }
    // Autres cas à gérer
    else
        throw CalculatorException("Erreur : DIV ne peut s'appliquer que sur des entiers.");
}
Literal& ComplexLiteral::mod(const Literal& l) const {
    // Ne s'applique que sur des entiers
    if(isInteger() && l.isInteger() && l.isComplex()){
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        // On effectue la divion
        return this->manager->addLiteral(real.mod(literal.real));
    }
    else if(l.isExpression()){
        const ExpressionLiteral& literal = dynamic_cast<const ExpressionLiteral&>(l);

        QString result = "MOD(" + this->toString() + ", " + literal.getExpression() + ")";

        return this->manager->addLiteral(result);
    }
    else if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        try {
            return this->mod(literal.getTarget());
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
    else if(l.isProgramm()){
        QString programm = "[ " + eval() + " " + l.eval() + " MOD ]";
        return this->manager->addLiteral(programm);
    }
    // Autres cas à gérer
    else
        throw CalculatorException("Erreur : DIV ne peut s'appliquer que sur des entiers.");
}
Literal& ComplexLiteral::pow(const Literal& l) const {
    // Première implémentation sommaire, on verra plus tard pour les puissances complexes
    // isComplex permet de connaitre le type de l et isNumber permet de savoir si la partie imaginaire est nulle
    if(isNumber() && l.isNumber() && l.isComplex()){
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        return this->manager->addLiteral(real.pow(literal.real));
    }
    else if(l.isExpression()){
        const ExpressionLiteral& literal = dynamic_cast<const ExpressionLiteral&>(l);

        QString result = "POW(" + this->toString() + ", " + literal.getExpression() + ")";

        return this->manager->addLiteral(result);
    }
    else if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        try {
            return this->pow(literal.getTarget());
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
    else if(l.isProgramm()){
        QString programm = "[ " + eval() + " " + l.eval() + " POW ]";
        return this->manager->addLiteral(programm);
    }
    else
        throw CalculatorException("Erreur : POW ne peut pas s'appliquer sur ces opérandes.");
}
Literal& ComplexLiteral::operator-() const {
    return this->manager->addLiteral(-real, -imaginary);
}
Literal& ComplexLiteral::sin() const {
    if(isNumber())
        return this->manager->addLiteral(real.sin());
    else
        throw CalculatorException("Erreur : SIN ne peut pas s'appliquer sur un complexe.");
}
Literal& ComplexLiteral::arcsin() const {
    if(isNumber()){
        try {
            return this->manager->addLiteral(real.arcsin());
        }
        catch(const CalculatorException& e){
            throw e; // On propage
        }
    }
    else
        throw CalculatorException("Erreur : ARCSIN ne peut pas s'appliquer sur un complexe.");
}
Literal& ComplexLiteral::cos() const {
    if(isNumber())
        return this->manager->addLiteral(real.cos());
    else
        throw CalculatorException("Erreur : COS ne peut pas s'appliquer sur un complexe.");
}
Literal& ComplexLiteral::arccos() const {
    if(isNumber()){
        try {
            return this->manager->addLiteral(real.arccos());
        }
        catch(const CalculatorException& e){
            throw e; // On propage
        }
    }
    else
        throw CalculatorException("Erreur : ARCCOS ne peut pas s'appliquer sur un complexe.");
}
Literal& ComplexLiteral::tan() const {
    if(isNumber())
        return this->manager->addLiteral(real.tan());
    else
        throw CalculatorException("Erreur : TAN ne peut pas s'appliquer sur un complexe.");
}
Literal& ComplexLiteral::arctan() const {
    if(isNumber())
        return this->manager->addLiteral(real.arctan());
    else
        throw CalculatorException("Erreur : ARCTAN ne peut pas s'appliquer sur un complexe.");
}
Literal& ComplexLiteral::sqrt() const {
    // Première implémentation dégueux
    if(isNumber()){
        try {
            return this->manager->addLiteral(real.sqrt());
        }
        catch(const CalculatorException& e){
            throw e; // On propage le problème
        }
    }
    else
        throw CalculatorException("Erreur : SQRT ne peut pas s'appliquer sur un complexe.");
}
Literal& ComplexLiteral::ln() const {
    // Première implémentation dégueux
    if(isNumber()){
        try {
            return this->manager->addLiteral(real.ln());
        }
        catch(const CalculatorException& e){
            throw e; // On propage le problème
        }
    }
    else
        throw CalculatorException("Erreur : LN ne peut pas s'appliquer sur un complexe.");
}
Literal& ComplexLiteral::exp() const {
    // exp(a + ib) = exp(a)[cos(b) + i.sin(b)]
    return this->manager->addLiteral(real.exp() * imaginary.cos(), real.exp() * imaginary.sin());
}
Literal& ComplexLiteral::num() const {
    // On tente sur tous les nombres, histoire de récupérer les erreurs spécifiques et ne pas tout réimplémenter
    if(isNumber()){
        try{
            return this->manager->addLiteral(real.num());
        }
        catch(const CalculatorException& e){
            throw e; // On propage
        }
    }
    else
        throw CalculatorException("Erreur : NUM ne peut pas s'appliquer sur un complexe.");
}
Literal& ComplexLiteral::den() const {
    if(isNumber()){
        try{
            return this->manager->addLiteral(real.den());
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
    else
        throw CalculatorException("Erreur : NUM ne peut pas s'appliquer sur un complexe.");
}
Literal& ComplexLiteral::re() const {
    return this->manager->addLiteral(real);
}
Literal& ComplexLiteral::im() const {
    return this->manager->addLiteral(imaginary);
}
Literal& ComplexLiteral::arg() const {
    return this->manager->addLiteral(complexArg());
}
Literal& ComplexLiteral::norm() const {
    return this->manager->addLiteral(complexNorm());
}
Literal& ComplexLiteral::$(const Literal& l) const {
    // Si on a des réels, on crée un entier
    if(l.isNumber() && isNumber()){
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        return this->manager->addLiteral(real, literal.real);
    }
    else if(l.isExpression() && isNumber()){
        const ExpressionLiteral& expressionArgument = dynamic_cast<const ExpressionLiteral&>(l);
        int operatorPriority = getPriority("$");

        QString result = this->toString() + " $ ";

        if(operatorPriority > expressionArgument.priority())
            result += "(" ;

        result += expressionArgument.getExpression();

        if(operatorPriority > expressionArgument.priority())
            result += ")" ;

        return this->manager->addLiteral(result);
    }
    else if(l.isAtom() && isNumber()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        return this->$(literal.getTarget());
    }
    else if(l.isProgramm()){
        QString programm = "[ " + eval() + " " + l.eval() + " $ ]";
        return this->manager->addLiteral(programm);
    }
    else
        throw CalculatorException("Erreur : Impossible de créer un complexe à partir de ces opérandes.");
}

// On utilise ces fonctions pour alléger l'écriture des autres, notamment dans les comparaisons
Number ComplexLiteral::complexArg() const {
    // Pas trop sûr du calcul, à revoir
    Number norm = complexNorm();
    if(isNumber())
        return (real / norm).arccos();
    else
        return (imaginary / norm).arcsin();
}
Number ComplexLiteral::complexNorm() const {
    // |a + ib| = sqrt(a^2 + b^2)
    return (real.pow(2) + imaginary.pow(2)).sqrt();
}

// Opérateurs logiques
Literal& ComplexLiteral::operator==(const Literal& l) const {
    // Si on a deux complexes
    if(l.isComplex()){
        // z = z' <=> {|z| = |z'| ET arg(z) = arg(z')[2PI]}
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        return this->manager->addBoolLiteral((complexNorm() == literal.complexNorm()) && (complexArg() == (literal.complexArg()))); // Retourne un Number
    }
    // Si on a une expression litérale, on fait une conversion et on compare
    else if(l.isExpression()){
        const ExpressionLiteral& literal = dynamic_cast<const ExpressionLiteral&>(l);

        return literal == *this;
    }
    else
        return this->manager->addBoolLiteral(false); // Si ce n'est pas une égalité de complexe, c'est différent
}
Literal& ComplexLiteral::operator!=(const Literal& l) const {
    // Si on a deux complexes
    if(l.isComplex()){
        // z = z' <=> {|z| = |z'| ET arg(z) = arg(z')[2PI]}
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        return this->manager->addBoolLiteral((complexNorm() != literal.complexNorm()) || (complexArg() != (literal.complexArg()))); // Retourne un Number
    }
    // Si on a une expression litérale, on fait une conversion et on compare
    else if(l.isExpression()){
        const ExpressionLiteral& literal = dynamic_cast<const ExpressionLiteral&>(l);

        return literal != *this;
    }
    else
        return this->manager->addBoolLiteral(true); // Si c'est différent
}
Literal& ComplexLiteral::operator>=(const Literal& l) const {
    // On peut facilement déterminer que deux complexes sont égaux ou différents, mais on ne peut pas les comparer
    // Si on a deux réels
    if(isNumber() && l.isNumber() && l.isComplex()){
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        return this->manager->addBoolLiteral(real >= literal.real);
    }
    // Si on a une expression litérale, on fait une conversion et on compare
    else if(l.isExpression()){
        const ExpressionLiteral& literal = dynamic_cast<const ExpressionLiteral&>(l);

        return literal >= *this;
    }
    else
        return this->manager->addBoolLiteral(false); // Si pas de comparaison possible. Retourner une erreur ?
}
Literal& ComplexLiteral::operator>(const Literal& l) const {
    // On peut facilement déterminer que deux complexes sont égaux ou différents, mais on ne peut pas les comparer
    // Si on a deux réels
    if(isNumber() && l.isNumber() && l.isComplex()){
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        return this->manager->addBoolLiteral(real > literal.real);
    }
    // Si on a une expression litérale, on fait une conversion et on compare
    else if(l.isExpression()){
        const ExpressionLiteral& literal = dynamic_cast<const ExpressionLiteral&>(l);

        return literal > *this;
    }
    else
        return this->manager->addBoolLiteral(false); // Si pas de comparaison possible. Retourner une erreur ?
}
Literal& ComplexLiteral::operator<=(const Literal& l) const {
    // On peut facilement déterminer que deux complexes sont égaux ou différents, mais on ne peut pas les comparer
    // Si on a deux réels
    if(isNumber() && l.isNumber() && l.isComplex()){
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        return this->manager->addBoolLiteral(real <= literal.real);
    }
    // Si on a une expression litérale, on fait une conversion et on compare
    else if(l.isExpression()){
        const ExpressionLiteral& literal = dynamic_cast<const ExpressionLiteral&>(l);

        return literal <= *this;
    }
    else
        return this->manager->addBoolLiteral(false); // Si pas de comparaison possible. Retourner une erreur ?
}
Literal& ComplexLiteral::operator<(const Literal& l) const {
    // On peut facilement déterminer que deux complexes sont égaux ou différents, mais on ne peut pas les comparer
    // Si on a deux réels
    if(isNumber() && l.isNumber() && l.isComplex()){
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        return this->manager->addBoolLiteral(real < literal.real);
    }
    // Si on a une expression litérale, on fait une conversion et on compare
    else if(l.isExpression()){
        const ExpressionLiteral& literal = dynamic_cast<const ExpressionLiteral&>(l);

        return literal < *this;
    }
    else
        return this->manager->addBoolLiteral(false); // Si pas de comparaison possible. Retourner une erreur ?
}
Literal& ComplexLiteral::operator&&(const Literal& l) const {
    if(isInteger()){
        if(l.isInteger() && l.isComplex()){
            const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

            return  this->manager->addBoolLiteral(real && literal.real);
        }
        else
            return this->manager->addBoolLiteral(real && Number(1));
    }
    else {
        if(l.isInteger() && l.isComplex()){
            const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

            return  this->manager->addBoolLiteral(Number(1) && literal.real);
        }
        else
            return this->manager->addBoolLiteral(true);
    }
}
Literal& ComplexLiteral::operator||(const Literal& l) const {
    // Si on a deux entiers
    if(isInteger() && (l.isInteger() && l.isComplex())){
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        return  this->manager->addBoolLiteral(real || literal.real);
    }
    else
        return this->manager->addBoolLiteral(true); // Sinon, on a forcément au moins un argument vrai
}
Literal& ComplexLiteral::operator!() const {
    // On vérifie que ce n'est pas la littérale entière 0
    if(isInteger())
        return this->manager->addBoolLiteral(!real);
    else
        return this->manager->addBoolLiteral(false); // Forcément quelque chose différent de 0
}

QString ComplexLiteral::eval() const {
    return real.toString() + " " + imaginary.toString() + " $";
}

QString ComplexLiteral::toString() const {
    QString result;
    result += real.toString();

    // On n'affiche la partie imaginaire que si elle existe
    if(imaginary != 0)
        result += "$" + imaginary.toString();

    return result;
}

// Pas forcément utile mais peu servir.
Literal& ComplexLiteral::conj() const {
    // On risque de la duplication si c'est un réel mais tant pis
    return this->manager->addLiteral(real, -imaginary);
}

