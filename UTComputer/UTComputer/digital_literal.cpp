#include "digital_literal.h"

DigitalLiteral::DigitalLiteral(double num, double den) : Literal(), numerator(num), denominator(den){
    simplify();
}

void DigitalLiteral::simplify(){
    // Si on a des nombres à virgule, on convertit en rapport entier
    double numeratorWholePart,
           numeratorDecimalPart = modf(numerator, &numeratorWholePart),
           denominatorWholePart,
           denominatorDecimalPart = modf(denominator, &denominatorWholePart);

    // On multiplie par 10 (si c'est un rationnel)
    if(isRational()){
        while(numeratorDecimalPart != 0 || denominatorDecimalPart != 0){
            numerator *= 10;
            denominator *= 10;

            numeratorDecimalPart = modf(numerator, 0);
            denominatorDecimalPart = modf(denominator, 0);
        }

        // Si le numérateur vaut 0, on passe le dénominateur à 1 (on traite de l'entier donc)
        if(numerator == 0){
            denominator = 1;
            return;
        }

        if(denominator == 0)
            throw CalculatorException("Erreur : Un dénominateur ne peut pas être nul.");

        int a = numerator,
            b = denominator;

        // Que des entiers
        if(a < 0)
            a = -a;

        if(b < 0)
            b = -b;

        while(a != b){
            if(a > b)
                a = a - b;
            else
                b = b - a;
        }

        numerator /= a;
        denominator /= a;
    }

    // On met à jour les signes
    sign();
}

void DigitalLiteral::sign(){
    // On met le signe négatif sur le numérateur
    // Si les deux sont négatif, pas besoin de signe (on inverse) ou si le numérateur est positif et le dénominateur négatif, on inverse
    if((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0)){
        numerator = -numerator;
        denominator = -denominator;
    }
}

bool DigitalLiteral::isInteger() const {
    double wholePart,
           decimalPart = modf(numerator, &wholePart);

    // Si le dénominateur vaut 1 et que la partie décimale est nulle, alors c'est bon
    return denominator == 1 && decimalPart == 0;
}

bool DigitalLiteral::isReal() const {
    double wholePart,
           decimalPart = modf(numerator, &wholePart);

    // Si le dénominateur vaut 1 et que la partie décimale n'est pas nulle, alors c'est bon
    return denominator == 1 && decimalPart != 0;
}

bool DigitalLiteral::isRational() const {
    // Si le dénominateur n'est pas 1, on a forcément un rationnel
    return denominator != 1;
}

bool DigitalLiteral::isComplex() const {return false;}
bool DigitalLiteral::isExpression() const {return false;}
bool DigitalLiteral::isProgramm() const {return false;}

// Opérateurs numériques
Literal* DigitalLiteral::operator+(const Literal& l) const {
    // Si on traite au moins un réel
    if(l.isReal() || isReal()){
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);

        // On retourne un réel
        return new DigitalLiteral(numerator + literal.toReal().numerator);
    }
    // Sinon, si on traite du rationnel ou de l'entier
    else if(l.isInteger() || l.isRational()){
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);
        double a = numerator,
               b = denominator,
               c = literal.numerator,
               d = literal.denominator;

        // On retoure un produit de fractions, au pire, cela sera simplifié :)
        return new DigitalLiteral(a*d + b*c, b*d);
    }

     // Autres cas à gérer
     return 0;
}
Literal* DigitalLiteral::operator-(const Literal& l) const {
    // On réutilise l'opérateur + et l'opérateur - unaire, pas besoin de se prendre la tête
    return (*this) + (-l);
}
Literal* DigitalLiteral::operator*(const Literal& l) const{
    // Si on traite au moins un réel
    if(l.isReal() || isReal()){
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);

        // On retourne un réel
        return new DigitalLiteral(numerator * literal.toReal().numerator);
    }
    // Sinon on traite de l'entier ou du rationnel
    else if(l.isInteger() || l.isRational() || l.isReal()){
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);
        double a = numerator,
               b = denominator,
               c = literal.numerator,
               d = literal.denominator;

        // On retoure un produit de fractions, au pire, cela sera simplifié :)
        return new DigitalLiteral(a*c, b*d);
    }

     // Autres cas à gérer
     return 0;
}
Literal* DigitalLiteral::operator/(const Literal& l) const {
    // Si on traite au moins un réel
    if(l.isReal() || isReal()){
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);

        if(literal == 0)
            throw CalculatorException("Erreur : la division par 0 est impossible.");

        // On retourne un réel
        return new DigitalLiteral(numerator / literal.toReal().numerator);
    }
    // Sinon on traite de l'entier ou du rationnel
    else if(l.isRational() || l.isInteger()){
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);

        if(literal == 0)
            throw CalculatorException("Erreur : la division par 0 est impossible.");

        double a = numerator,
               b = denominator,
               c = literal.numerator,
               d = literal.denominator;

        return new DigitalLiteral(a*d, b*c);
    }

    // Autres cas à gérer
    return 0;

}
Literal* DigitalLiteral::operator+(const Literal* l) const {
    // Permet de faciliter la manipulation avec des indirections
    return (*this) + *l;
}
Literal* DigitalLiteral::operator-(const Literal* l) const {
    return (*this) - *l;
}
Literal* DigitalLiteral::operator*(const Literal* l) const {
    return (*this) * *l;
}
Literal* DigitalLiteral::operator/(const Literal* l) const {
    return (*this) / *l;
}

Literal* DigitalLiteral::div(const Literal& l) const {
    // Ne peut s'appliquer que sur les litérales entières
    if(!isInteger() || !l.isInteger())
        throw CalculatorException("Erreur : DIV ne peut s'appliquer que sur des entiers.");

    // On convertit l'opérande 2
    try{
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);

        return new DigitalLiteral(numerator / literal.numerator); // On retourne la division d'entiers, qui sera soit un entier soit un rationnel
    }
    catch(const std::bad_cast& e){
        cout << e.what() << endl;
    }

    // Autres cas de littérales
    return 0;
}

Literal* DigitalLiteral::mod(const Literal& l) const {
    // Ne peut s'appliquer que sur les litérales entières
    if(!isInteger() || !l.isInteger())
        throw CalculatorException("Erreur : MOD ne peut s'appliquer que sur des entiers.");

    // On convertit l'opérande 2
    try{
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);

        int a = numerator,
            b = literal.numerator;

        return new DigitalLiteral(a % b); // On retourne la division d'entiers, qui sera soit un entier soit un rationnel
    }
    catch(const std::bad_cast& e){
        cout << e.what() << endl;
    }

    // Si le deuxième opérateur est une expression, on convertit
    return 0;
}

/// Il y a peut-être un bug avec des litérales réelles
Literal* DigitalLiteral::pow(const Literal& l) const {
    // Si on gère des réels ou des entiers
    if(l.isInteger() || l.isReal() || l.isRational()){
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);

        return new DigitalLiteral(std::pow(numerator, literal.toReal().numerator), std::pow(denominator, literal.toReal().numerator));
    }

    // Autres cas de littérales
    return 0;
}
Literal* DigitalLiteral::div(const Literal* l) const {
    // Permet juste de gérer les opérations depuis des pointeurs sans avoir à gérer des indirections à chaque fois
    return (*this).div(*l);
}
Literal* DigitalLiteral::mod(const Literal* l) const {
    return (*this).mod(*l);
}
Literal* DigitalLiteral::pow(const Literal* l) const {
    return (*this).pow(*l);
}

Literal* DigitalLiteral::operator-() const {
    return new DigitalLiteral(-numerator, denominator);
}

Literal* DigitalLiteral::sin() const {
    // On crée un sinus à partir de la valeur en réel (osef des rationnels)
    return new DigitalLiteral(std::sin(toReal().numerator));
}
Literal* DigitalLiteral::arcsin() const {
    // Si on est pas dans le bon interval
    if(*this < -1 || *this > 1)
        throw CalculatorException("Erreur : ARCSIN ne s'applique que dans l'interval réel [-1; 1]");

    // Même bails pour les autres fonctions trigo
    return new DigitalLiteral(std::asin(toReal().numerator));
}
Literal* DigitalLiteral::cos() const {
    return new DigitalLiteral(std::cos(toReal().numerator));
}
Literal* DigitalLiteral::arccos() const {
    // Si on est dans le bon interval
    if(*this < -1 || *this > 1)
        throw CalculatorException("Erreur : ARCSIN ne s'applique que dans l'interval réel [-1; 1]");

    return new DigitalLiteral(std::acos(toReal().numerator));
}
Literal* DigitalLiteral::tan() const {
    return new DigitalLiteral(std::tan(toReal().numerator));
}
Literal* DigitalLiteral::arctan() const {
    return new DigitalLiteral(std::atan(toReal().numerator));
}

Literal* DigitalLiteral::sqrt() const {
    if(*this < 0)
        throw CalculatorException("Erreur : SQRT ne peut s'appliquer que sur des nombres réels positifs.");

    return new DigitalLiteral(std::sqrt(toReal().numerator));
}
Literal* DigitalLiteral::ln() const {
    if(*this < 0)
        throw CalculatorException("Erreur : LN ne peut s'appliquer que sur des nombres réels positifs.");

    return new DigitalLiteral(std::log(toReal().numerator));
}
Literal* DigitalLiteral::exp() const {
    return new DigitalLiteral(std::exp(toReal().numerator));
}

// Reste à déterminer si on renvoie le signe de la fraction avec le numérateur car il est stocké dans le numérateur
// Pour le moment c'est le cas, question épineuse
Literal* DigitalLiteral::num() const {
    // Ne peut pas s'appliquer sur des réels ou des complexes
    if(isReal())
        throw CalculatorException("Erreur : NUM ne peut pas s'appliquer sur des réels.");

    if(isComplex())
        throw CalculatorException("Erreur : NUM ne peut pas s'appliquer sur des réels.");

    return new DigitalLiteral(std::abs(numerator)); // On retourne le numérateur (ou l'entier inchangé)
}

Literal* DigitalLiteral::den() const {
    // Ne peut pas s'appliquer sur des réels ou des complexes
    if(isReal())
        throw CalculatorException("Erreur : NUM ne peut pas s'appliquer sur des réels.");

    if(isComplex())
        throw CalculatorException("Erreur : NUM ne peut pas s'appliquer sur des réels.");

    return new DigitalLiteral(denominator); // On retourne le dénominateur qui vaut soit 1, soit autre chose
}

Literal* DigitalLiteral::re() const {
    return new DigitalLiteral(*this);
}
Literal* DigitalLiteral::im() const {
    return new DigitalLiteral(0);
}

// Opérateurs logiques
bool DigitalLiteral::operator==(const Literal& l) const {
    // Si on traite deux litérales numériques entre-elles
    if(l.isInteger() || l.isRational() || l.isReal()){
        // Il faudrait gérer les erreurs au niveau des cast dynamiques, c'est un peu dégueux même s'il n'y a pas de problèmes normalement
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);

        return toReal().numerator == literal.toReal().numerator;
    }

    // Autres cas de gestion d'égalité
    return false;
}
bool DigitalLiteral::operator!=(const Literal& l) const {
    // Si on traite deux litérales numériques entre-elles
    if(l.isInteger() || l.isRational() || l.isReal()){
        // Il faudrait gérer les erreurs au niveau des cast dynamiques, c'est un peu dégueux même s'il n'y a pas de problèmes normalement
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);

        return !(toReal().numerator == literal.toReal().numerator);
    }

    // Autres cas de gestion d'égalité
    return false;
}
bool DigitalLiteral::operator>=(const Literal& l) const {
    // Si on traite deux litérales numériques entre-elles
    if(l.isInteger() || l.isRational() || l.isReal()){
        // Il faudrait gérer les erreurs au niveau des cast dynamiques, c'est un peu dégueux même s'il n'y a pas de problèmes normalement
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);

        return toReal().numerator >= literal.toReal().numerator;
    }

    // Autres cas de gestion d'égalité
    return false;
}
bool DigitalLiteral::operator>(const Literal& l) const {
    // Si on traite deux litérales numériques entre-elles
    if(l.isInteger() || l.isRational() || l.isReal()){
        // Il faudrait gérer les erreurs au niveau des cast dynamiques, c'est un peu dégueux même s'il n'y a pas de problèmes normalement
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);

        return toReal().numerator > literal.toReal().numerator;
    }

    // Autres cas de gestion d'égalité
    return false;
}
bool DigitalLiteral::operator<=(const Literal& l) const {
    // Si on traite deux litérales numériques entre-elles
    if(l.isInteger() || l.isRational() || l.isReal()){
        // Il faudrait gérer les erreurs au niveau des cast dynamiques, c'est un peu dégueux même s'il n'y a pas de problèmes normalement
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);

        return toReal().numerator <= literal.toReal().numerator;
    }

    // Autres cas de gestion d'égalité
    return false;
}
bool DigitalLiteral::operator<(const Literal& l) const {
    // Si on traite deux litérales numériques entre-elles
    if(l.isInteger() || l.isRational() || l.isReal()){
        // Il faudrait gérer les erreurs au niveau des cast dynamiques, c'est un peu dégueux même s'il n'y a pas de problèmes normalement
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);

        return toReal().numerator < literal.toReal().numerator;
    }

    // Autres cas de gestion d'égalité
    return false;
}
bool DigitalLiteral::operator&&(const Literal& l) const {
    // Si on traite deux litérales numériques entre-elles
    if(l.isInteger() || l.isRational() || l.isReal()){
        // Il faudrait gérer les erreurs au niveau des cast dynamiques, c'est un peu dégueux même s'il n'y a pas de problèmes normalement
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);

        return toReal().numerator && literal.toReal().numerator;
    }

    // Autres cas de gestion d'égalité
    return false;
}
bool DigitalLiteral::operator||(const Literal& l) const {
    // Si on traite deux litérales numériques entre-elles
    if(l.isInteger() || l.isRational() || l.isReal()){
        // Il faudrait gérer les erreurs au niveau des cast dynamiques, c'est un peu dégueux même s'il n'y a pas de problèmes normalement
        const DigitalLiteral& literal = dynamic_cast<const DigitalLiteral&>(l);

        return toReal().numerator || literal.toReal().numerator;
    }

    // Autres cas de gestion d'égalité
    return false;
}
bool DigitalLiteral::operator!() const {
    return !toReal().numerator;
}

bool DigitalLiteral::operator==(double d) const {
    return *this == DigitalLiteral(d);
}
bool DigitalLiteral::operator!=(double d) const {
    return *this != DigitalLiteral(d);
}
bool DigitalLiteral::operator>=(double d) const {
    return *this >= DigitalLiteral(d);
}
bool DigitalLiteral::operator>(double d) const {
    return *this > DigitalLiteral(d);
}
bool DigitalLiteral::operator<=(double d) const {
    return *this <= DigitalLiteral(d);
}
bool DigitalLiteral::operator<(double d) const {
    return *this < DigitalLiteral(d);
}

QString DigitalLiteral::toString() const {
    QString result = QString::number(numerator);

    // On n'affiche le dénominateur seulement si on a un rationnel
    if(isRational())
        result += "/" + QString::number(denominator);

    return result;
}

DigitalLiteral DigitalLiteral::toReal() const {
    return DigitalLiteral(numerator/denominator);
}
