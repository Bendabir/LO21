#include "atom_literal.h"
#include "expression_literal.h"

AtomLiteral::AtomLiteral(LiteralFactory* m, const QString& a, Literal* t) : Literal(m), atom(a), target(t){
    if(t == 0)
        throw CalculatorException("Erreur : Une variable doit pointer sur quelque chose.");

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
    if(this->manager->existsAtom(atom))
        throw CalculatorException("Erreur : Le nom de variable " + atom + " est déjà utilisé.");
}

Literal& AtomLiteral::getTarget(bool allSons) const {
    if(allSons){
        if(target->isAtom()){
            AtomLiteral& son = dynamic_cast<AtomLiteral&>(*target);

            return son.getTarget();
        }
        else
            return *target;
    }
    else
        return *target;
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
Literal& AtomLiteral::operator+(const Literal& l) const {
    // Si on a deux atomes
    if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        return *target + *(literal.target);
    }
    // On prend en compte les expressions
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
    else
        return *target + l;
}
Literal& AtomLiteral::operator-(const Literal& l) const {
    // Si on a deux atomes
    if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        return *target - *(literal.target);
    }
    // On prend en compte les expressions
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
    else
        return *target - l;
}
Literal& AtomLiteral::operator*(const Literal& l) const {
    // Si on a deux atomes
    if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        return *target * *(literal.target);
    }
    // On prend en compte les expressions
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
    else
        return *target * l;
}
Literal& AtomLiteral::operator/(const Literal& l) const {
    // Si on a deux atomes
    if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        try {
            return *target / *(literal.target);
        }
        catch(const CalculatorException& e){
            throw e; // On teste et on propage parce qu'on fait du ping-pong entre les fonctions à cause des atomes
        }
    }
    // On prend en compte les expressions
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
    else{
        try{
            return *target / l;
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
}
Literal& AtomLiteral::div(const Literal& l) const {
    // Si on a deux atomes
    if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        try {
            return target->div(*literal.target);
        }
        catch(const CalculatorException& e){
            throw e; // On teste et on propage parce qu'on fait du ping-pong entre les fonctions à cause des atomes
        }
    }
    else{
        try{
            return target->div(l);
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
}
Literal& AtomLiteral::mod(const Literal& l) const {
    // Si on a deux atomes
    if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        try {
            return target->mod(*literal.target);
        }
        catch(const CalculatorException& e){
            throw e; // On teste et on propage parce qu'on fait du ping-pong entre les fonctions à cause des atomes
        }
    }
    else{
        try{
            return target->mod(l);
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
}
Literal& AtomLiteral::pow(const Literal& l) const {
    // Si on a deux atomes
    if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        try {
            return target->pow(*literal.target);
        }
        catch(const CalculatorException& e){
            throw e; // On teste et on propage parce qu'on fait du ping-pong entre les fonctions à cause des atomes
        }
    }
    else{
        try{
            return target->pow(l);
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
}
Literal& AtomLiteral::operator-() const {
    return -(*target);
}
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
Literal& AtomLiteral::arctan() const {
    return target->arctan();
}
Literal& AtomLiteral::sqrt() const {
    try {
        return target->sqrt();
    }
    catch(const CalculatorException& e){
        throw e;
    }
}
Literal& AtomLiteral::ln() const {
    try {
        return target->ln();
    }
    catch(const CalculatorException& e){
        throw e;
    }
}
Literal& AtomLiteral::exp() const {
    return target->exp();
}
Literal& AtomLiteral::num() const {
    try {
        return target->num();
    }
    catch(const CalculatorException& e){
        throw e;
    }
}
Literal& AtomLiteral::den() const {
    try {
        return target->den();
    }
    catch(const CalculatorException& e){
        throw e;
    }
}
Literal& AtomLiteral::re() const {
    return target->re();
}
Literal& AtomLiteral::im() const {
    return target->im();
}
Literal& AtomLiteral::arg() const {
    return target->arg();
}
Literal& AtomLiteral::norm() const {
    return target->norm();
}
Literal& AtomLiteral::$(const Literal& l) const {
    // Si on a deux atomes
    if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        try {
            return target->$(*literal.target);
        }
        catch(const CalculatorException& e){
            throw e; // On teste et on propage parce qu'on fait du ping-pong entre les fonctions à cause des atomes
        }
    }
    else{
        try{
            return target->$(l);
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
}

// Opérateurs logiques
Literal& AtomLiteral::operator==(const Literal& l) const {
    // Si l'argument est un atome, on teste entre les valeurs pointée, sinon on fait un test basique
    if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        try {
            return getTarget() == literal.getTarget();
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
    else{
        try{
            return getTarget() == l;
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
}
Literal& AtomLiteral::operator!=(const Literal& l) const {
    try{
        return !(*this == l);
    }
    catch(const CalculatorException& e){
        throw e;
    }
}
Literal& AtomLiteral::operator>=(const Literal& l) const {
    // Si l'argument est un atome, on teste entre les valeurs pointée, sinon on fait un test basique
    if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        try {
            return getTarget() >= literal.getTarget();
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
    else{
        try{
            return getTarget() >= l;
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
}
Literal& AtomLiteral::operator>(const Literal& l) const {
    // Si l'argument est un atome, on teste entre les valeurs pointée, sinon on fait un test basique
    if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        try {
            return getTarget() > literal.getTarget();
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
    else{
        try{
            return getTarget() > l;
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
}

Literal& AtomLiteral::operator<=(const Literal& l) const {
    // Si l'argument est un atome, on teste entre les valeurs pointée, sinon on fait un test basique
    if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        try {
            return getTarget() <= literal.getTarget();
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
    else{
        try{
            return getTarget() <= l;
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
}

Literal& AtomLiteral::operator<(const Literal& l) const {
    // Si l'argument est un atome, on teste entre les valeurs pointée, sinon on fait un test basique
    if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        try {
            return getTarget() < literal.getTarget();
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
    else{
        try{
            return getTarget() < l;
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
}

Literal& AtomLiteral::operator&&(const Literal& l) const {
    // Si l'argument est un atome, on teste entre les valeurs pointée, sinon on fait un test basique
    if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        try {
            return getTarget() && literal.getTarget();
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
    else{
        try{
            return getTarget() && l;
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
}

Literal& AtomLiteral::operator||(const Literal& l) const {
    // Si l'argument est un atome, on teste entre les valeurs pointée, sinon on fait un test basique
    if(l.isAtom()){
        const AtomLiteral& literal = dynamic_cast<const AtomLiteral&>(l);

        try {
            return getTarget() || literal.getTarget();
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
    else{
        try{
            return getTarget() || l;
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
}

Literal& AtomLiteral::operator!() const {
    try {
        return !getTarget();
    }
    catch(const CalculatorException& e){
        throw e;
    }
}

QString AtomLiteral::eval() const {
    // On retourne la valeur de la variable pointée sous forme de chaine de caractères
    return getTarget().toString();
}
QString AtomLiteral::toString() const {
    // On retourne le nom de la variable
    return atom;
}
