#include "number.h"
#include "calculator_exception.h"

Number::Number(double num, double den) : numerator(num), denominator(den){
    simplify();
}

void Number::simplify(){
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

        if(denominator == 0){
            denominator = 1;
            return;
        }

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

void Number::sign(){
    // On met le signe négatif sur le numérateur
    // Si les deux sont négatif, pas besoin de signe (on inverse) ou si le numérateur est positif et le dénominateur négatif, on inverse
    if((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0)){
        numerator = -numerator;
        denominator = -denominator;
    }
}

bool Number::isInteger() const {
    double wholePart,
           decimalPart = modf(numerator, &wholePart);

    // Si le dénominateur vaut 1 et que la partie décimale est nulle, alors c'est bon
    return denominator == 1 && decimalPart == 0;
}

bool Number::isReal() const {
    double wholePart,
           decimalPart = modf(numerator, &wholePart);

    // Si le dénominateur vaut 1 et que la partie décimale n'est pas nulle, alors c'est bon
    return denominator == 1 && decimalPart != 0;
}

bool Number::isRational() const {
    // Si le dénominateur n'est pas 1, on a forcément un rationnel
    return denominator != 1;
}

// Opérateurs numériques
Number Number::operator+(const Number& n) const {
    // Si on traite au moins un réel
    if(n.isReal() || isReal()){
        // On retourne un réel
        return numerator + n.toReal();
    }
    // Sinon, si on traite du rationnel ou de l'entier
    else {
        double a = numerator,
               b = denominator,
               c = n.numerator,
               d = n.denominator;

        // On retoure un produit de fractions, au pire, cela sera simplifié :)
        return Number(a*d + b*c, b*d);
    }
}
Number Number::operator-(const Number& n) const {
    // On réutilise l'opérateur + et l'opérateur - unaire, pas besoin de se prendre la tête
    return (*this) + (-n);
}
Number Number::operator*(const Number& n) const{
    // Si on traite au moins un réel
    if(n.isReal() || isReal()){
        // On retourne un réel
        return numerator * n.toReal();
    }
    // Sinon on traite de l'entier ou du rationnel
    else {
        double a = numerator,
               b = denominator,
               c = n.numerator,
               d = n.denominator;

        // On retoure un produit de fractions, au pire, cela sera simplifié :)
        return Number(a*c, b*d);
    }
}
Number Number::operator/(const Number& n) const {
    // Division par 0 impossible
    if(n == 0)
        throw CalculatorException("Erreur : la division par 0 est impossible.");

    // Si on traite au moins un réel
    if(n.isReal() || isReal()){
        // On retourne un réel
        return numerator / n.toReal();
    }
    // Sinon on traite de l'entier ou du rationnel
    else {
        double a = numerator,
               b = denominator,
               c = n.numerator,
               d = n.denominator;

        return Number(a*d, b*c);
    }
}

Number Number::div(const Number& n) const {
    // Ne peut s'appliquer que sur entiers
    if(isInteger() && n.isInteger()){
        // Division par 0 : VERBOTEN !
        if(n == 0)
            throw CalculatorException("Erreur : La division par 0 est impossible.");

        // Conversion au calme
        int a = numerator,
            b = n.numerator;

        // On convertit l'opérande 2
        return a / b; // On retourne la division d'entiers, qui sera soit un entier soit un rationnel
    }
    // Autres cas de littérales (programme, expression)
    else
        throw CalculatorException("Erreur : DIV ne peut s'appliquer que sur des entiers.");
}

Number Number::mod(const Number& n) const {
    // Ne peut s'appliquer que sur entiers
    if(isInteger() && n.isInteger()){
        // Division par 0 : VERBOTEN !
        if(n == 0)
            throw CalculatorException("Erreur : La division par 0 est impossible.");

        int a = numerator,
            b = n.numerator;

        // On convertit l'opérande 2
        return a % b; // On retourne la division d'entiers, qui sera soit un entier soit un rationnel
    }
    // Autres cas de littérales (programme, expression)
    else
        throw CalculatorException("Erreur : MOD ne peut s'appliquer que sur des entiers.");
}

// Il y a peut-être un bug avec des litérales réelles
Number Number::pow(const Number& n) const {
    return Number(std::pow(numerator, n.toReal()), std::pow(denominator, n.toReal()));
}

Number Number::operator-() const {
    return Number(-numerator, denominator);
}

Number Number::sin() const {
    // On crée un sinus à partir de la valeur en réel (osef des rationnels)
    return std::sin(toReal());
}
Number Number::arcsin() const {
    // Si on est pas dans le bon interval
    if(*this < -1 || *this > 1)
        throw CalculatorException("Erreur : ARCSIN ne s'applique que dans l'interval réel [-1; 1]");

    // Même bails pour les autres fonctions trigo
    return std::asin(toReal());
}
Number Number::cos() const {
    return std::cos(toReal());
}
Number Number::arccos() const {
    // Si on est dans le bon interval
    if(*this < -1 || *this > 1)
        throw CalculatorException("Erreur : ARCSIN ne s'applique que dans l'interval réel [-1; 1]");

    return std::acos(toReal());
}
Number Number::tan() const {
    return std::tan(toReal());
}
Number Number::arctan() const {
    return std::atan(toReal());
}

Number Number::sqrt() const {
    if(*this < 0)
        throw CalculatorException("Erreur : SQRT ne peut s'appliquer que sur des nombres réels positifs.");

    return std::sqrt(toReal());
}
Number Number::ln() const {
    if(*this < 0)
        throw CalculatorException("Erreur : LN ne peut s'appliquer que sur des nombres réels positifs.");

    return std::log(toReal());
}
Number Number::exp() const {
    return std::exp(toReal());
}

// Reste à déterminer si on renvoie le signe de la fraction avec le numérateur car il est stocké dans le numérateur
// Pour le moment c'est le cas, question épineuse
Number Number::num() const {
    // Ne peut pas s'appliquer sur des réels ou des complexes
    if(isReal())
        throw CalculatorException("Erreur : NUM ne peut pas s'appliquer sur des réels.");

    return std::abs(numerator); // On retourne le numérateur (ou l'entier inchangé)
}

Number Number::den() const {
    // Ne peut pas s'appliquer sur des réels ou des complexes
    if(isReal())
        throw CalculatorException("Erreur : NUM ne peut pas s'appliquer sur des réels.");

    return std::abs(denominator); // On retourne le dénominateur qui vaut soit 1, soit autre chose
}

Number& Number::operator++(){
    *this = *this + 1;
    return *this;
}
Number Number::operator++(int){
    Number temp = *this;
    ++(*this);
    return temp;
}

Number& Number::operator--(){
    *this = *this - 1;
    return *this;
}

Number Number::operator--(int){
    Number temp = *this;
    --(*this);
    return temp;
}

// Opérateurs logiques
bool Number::operator==(const Number& n) const {
    return toReal() == n.toReal();
}
bool Number::operator!=(const Number& n) const {
    return toReal() != n.toReal();
}
bool Number::operator>=(const Number& n) const {
    return toReal() >= n.toReal();
}
bool Number::operator>(const Number& n) const {
    return toReal() > n.toReal();
}
bool Number::operator<=(const Number& n) const {
    return toReal() <= n.toReal();
}
bool Number::operator<(const Number& n) const {
    return toReal() < n.toReal();
}
bool Number::operator&&(const Number& n) const {
    return toReal() && n.toReal();
}
bool Number::operator||(const Number& n) const {
    return toReal() || n.toReal();
}
bool Number::operator!() const {
    return !toReal();
}

QString Number::toString() const {
    QString result = QString::number(numerator);

    // On n'affiche le dénominateur seulement si on a un rationnel
    if(isRational())
        result += "/" + QString::number(denominator);

    return result;
}

double Number::toReal() const {
    return numerator / denominator;
}

QString Number::eval() const {
    QString result;

    // On convertit en postfixe
    if(numerator < 0)
        result = QString::number(numerator).replace("-", "") + " NEG";
    else
        result = QString::number(numerator);

    if(denominator != 0){
        result += " ";

        if(denominator < 0)
            result += QString::number(numerator).replace("-", "") + " NEG";
        else
            result += QString::number(numerator);

        result += " /"
    }
}


std::ostream& operator<<(std::ostream& f, const Number& n){
    f << n.toString().toStdString();
    return f;
}
