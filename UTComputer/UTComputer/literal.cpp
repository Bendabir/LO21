#include "literal.h"

ostream& operator<<(ostream& f, const QString& str){
    f << str.toStdString();
    return f;
}

ostream& operator<<(ostream& f, const Literal& l){
    f << l.toString();
    return f;
}

bool Literal::isNumber() const {
    return isInteger() || isReal() || isRational();
}

// Permet d'implémenter l'évaluation d'une expression litérale. Par défaut, ça affiche la littérale
QString Literal::eval() const {
    return toString();
}

// Fonctions outils
bool isNumber(const QString& str){
    bool check;
    str.toDouble(&check);

    return check;
}

bool isComplex(const QString& str){
    if(str.indexOf("$") != -1)
        return true;
    return false;
}

bool isRational(const QString& str){
    if(str.indexOf("/") != -1)
        return true;
    return false;
}

bool isFunction(const QString& str){
    QString function = str.toUpper();

    if(function == "MOD")
        return true;
    if(function == "DIV")
        return true;
    if(function == "POW")
        return true;
    if(function == "NEG")
        return true;
    if(function == "SIN" || function == "COS" || function == "TAN" || function == "ARCSIN" || function == "ARCCOS" || function == "ARCTAN")
        return true;
    if(function == "SQRT")
        return true;
    if(function == "EXP")
        return true;
    if(function == "LN")
        return true;
    if(function == "NUM")
        return true;
    if(function == "DEN")
        return true;
    if(function == "RE")
        return true;
    if(function == "IM")
        return true;
    if(function == "ARG")
        return true;
    if(function == "NORM")
        return true;

    return false;
}

bool isOperator(const QString& str){
    QString op = str.toUpper();

    if(op == "+")
        return true;
    if(op == "-")
        return true;
    if(op == "*")
        return true;
    if(op == "/")
        return true;
    if(op == "<")
        return true;
    if(op == "<=")
        return true;
    if(op == ">")
        return true;
    if(op == ">=")
        return true;
    if(op == "=")
        return true;
    if(op == "!=")
        return true;
    if(op == "AND")
        return true;
    if(op == "OR")
        return true;
    if(op == "NOT")
        return true;
    if(op == "$")
        return true;

    return false;
}

bool isVariable(const QString& str){
    QString var = str.toUpper();

    // Si c'est un opérateur ou une fonction, ça ne peut pas être une variable
    if(isFunction(var) || isOperator(var))
        return false;

    QRegExp regex("^([A-Z][0-9A-Z]*)");

    return regex.indexIn(var) != -1; // On vérifie que l'on a trouvé un identifieur de variable
}

int getPriority(const QString& o){
    QMap<QString, int> priorities;
    priorities["+"] = 5;
    priorities["-"] = 5;
    priorities["*"] = 6;
    priorities["/"] = 6;
    priorities[">"] = 4;
    priorities[">="] = 4;
    priorities["<"] = 4;
    priorities["<="] = 4;
    priorities["="] = 3;
    priorities["!="] = 3;
    priorities["AND"] = 2;
    priorities["OR"] = 1;
    priorities["NOT"] = 7;
    priorities["$"] = 8;

    return priorities[o.toUpper()];
}
