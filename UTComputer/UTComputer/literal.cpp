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
    if(str.indexOf("$") == -1)
        return false;

    QStringList parts = str.split("$");

    if(parts.length() > 2)
        return false;

    QString re = parts[0],
            im = parts[1];

    if((isRational(re) || isNumber(re)) && (isRational(im) || isNumber(im)))
        return true;
    return false;
}

bool isRational(const QString& str){
    if(str.indexOf("/") == -1)
        return false;

    QStringList parts = str.split("/");

    if(parts.length() > 2)
        return false;

    QString num = parts[0],
            den = parts[1];

    if(isNumber(num) && isNumber(den))
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

bool isExpression(const QString& str){
    return str[0] == '\'' && str[str.length() - 1] == '\'';
}

bool isProgramm(const QString& str){
    return str[0] == '[' && str[str.length() - 1] == ']';
}

bool isStackOperator(const QString& op){
    if(op == "CLEAR")
        return true;
    if(op == "EDIT")
        return true;
    if(op == "EVAL")
        return true;
    if(op == "DROP")
        return true;
    if(op == "DUP")
        return true;
    if(op == "SWAP")
        return true;
    if(op == "FORGET")
        return true;
    if(op == "STO")
        return true;
    if(op == "LASTOP")
        return true;
    if(op == "LASTARGS")
        return true;
    if(op == "UNDO")
        return true;
    if(op == "REDO")
        return true;
    if(op == "WHILE")
        return true;
    if(op == "IFT")
        return true;
    if(op == "IFTE")
        return true;
    if(op == "WHILE")
        return true;

    return false;
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
