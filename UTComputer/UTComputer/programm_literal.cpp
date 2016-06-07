#include "programm_literal.h"

QString ProgrammLiteral::concat(const QString& op) const {
    // On ne traite que des fonctions
    return "[ " + eval() + " " + op + " ]";
}

QString ProgrammLiteral::concat(const QString& op, const Literal& l) const {
    return "[ " + eval() + " " + l.eval() + " " + op + " ]";
}

ProgrammLiteral::ProgrammLiteral(LiteralFactory* m, const QString& exp) : StringLiteral(m, exp){
    // On remplace les suites d'espaces/sauts par des espaces uniques
    expression.replace(QRegExp("\\s+"), " ");

    // Si l'expression est vide, on ne prend pas et on vérifie qu'elle est valide
    if(expression.length() == 0)
        throw CalculatorException("Erreur : Le programme entré est vide.");
}

Literal& ProgrammLiteral::operator-() const {
    return this->manager->addLiteral(concat("NEG"));
}

// Permet de récupérer la chaine évaluée même lorsque l'on a une référence sur une litérale (dynamique)
QString ProgrammLiteral::eval() const {
    return expression;
}

QString ProgrammLiteral::toString() const {
    int nbMaxChar = MAX_LENGTH - 7;

    // On remplace les sauts de ligne et tabulations
    QString programm = expression;
    programm.replace("\t", " ");
    programm.replace("\n", " ");

    QString result = "[ " + programm.mid(0, nbMaxChar);

    if(programm.length() > nbMaxChar)
        result += "...";

    result += " ]";
    return result;
}
