#include "expression_literal.h"
#include "complex_literal.h"

QString ExpressionLiteral::concat(const QString& op) const {
    // On ne traite que des fonctions
    QString exp = op + "(" + expression + ")";
    return exp;
}

QString ExpressionLiteral::concat(const QString& op, const Literal& l) const {
    QString exp;
    int operatorPriority = getPriority(op);

    // Si on a un opérateur : infixe, sinon préfixe
    if(isOperator(op)){
        // On vire les guillemets si c'était une expression
        if(priority() < operatorPriority)
            exp += "(";

        exp += expression;

        if(priority() < operatorPriority)
            exp += ")";

        exp += op;

        // On crée une expression littérale pour le calcul
        ExpressionLiteral literal(0, l.toString().replace("'", ""));

        if(literal.priority() < operatorPriority)
            exp += "(";

        exp += literal.expression;

        if(literal.priority() < operatorPriority)
            exp += ")";

    }
    else if(isFunction(op))
        // On vire les guillemets si c'était une expression
        exp = op + "(" + expression + "," + l.toString().replace("'", "") + ")";

    return exp;
}

ExpressionLiteral::ExpressionLiteral(LiteralFactory* m, const QString& exp) : Literal(m), expression(exp){
    expression.replace(" ", ""); // On vire les espaces

    // Si l'expression est vide, on ne prend pas et on vérifie qu'elle est valide
    if(expression.length() == 0)
        throw CalculatorException("Erreur : L'expression infixe entrée est vide.");

    try{
        evaluate();
    }
    catch(const CalculatorException& e){
        throw e; // On propage les erreurs
    }
}

// Pour savoir ce que l'on traite
bool ExpressionLiteral::isInteger() const {return false;}
bool ExpressionLiteral::isReal() const {return false;}
bool ExpressionLiteral::isRational() const {return false;}
bool ExpressionLiteral::isComplex() const {return false;}
bool ExpressionLiteral::isExpression() const {return true;}
bool ExpressionLiteral::isProgramm() const {return false;}
bool ExpressionLiteral::isAtom() const {return false;}

// Opérateurs numériques
Literal& ExpressionLiteral::operator+(const Literal& l) const {
    // Ici, on ne se prend pas la tête : Dans tous les cas, la litérale passée en argument devient une expression
    return this->manager->addLiteral(concat("+", l));
}
Literal& ExpressionLiteral::operator-(const Literal& l) const {
    return this->manager->addLiteral(concat("-", l));
}
Literal& ExpressionLiteral::operator*(const Literal& l) const {
    return this->manager->addLiteral(concat("*", l));
}
Literal& ExpressionLiteral::operator/(const Literal& l) const {
    return this->manager->addLiteral(concat("/", l));
}
// On va peut être ajouter des sécurités sur les conversions
Literal& ExpressionLiteral::div(const Literal& l) const {
    return this->manager->addLiteral(concat("DIV", l));
}
Literal& ExpressionLiteral::mod(const Literal& l) const {
    return this->manager->addLiteral(concat("MOD", l));
}
Literal& ExpressionLiteral::pow(const Literal& l) const {
    return this->manager->addLiteral(concat("POW", l));
}
Literal& ExpressionLiteral::operator-() const {
    QString result = "-";
    if(nbTokens() > 1)
        result += "(";

    result += expression;

    if(nbTokens() > 1)
        result += ")";

    return this->manager->addLiteral(result);
}
Literal& ExpressionLiteral::sin() const {
    return this->manager->addLiteral(concat("SIN"));
}
Literal& ExpressionLiteral::arcsin() const {
    return this->manager->addLiteral(concat("ARCSIN"));
}
Literal& ExpressionLiteral::cos() const {
    return this->manager->addLiteral(concat("COS"));
}
Literal& ExpressionLiteral::arccos() const {
    return this->manager->addLiteral(concat("ARCCOS"));
}
Literal& ExpressionLiteral::tan() const {
    return this->manager->addLiteral(concat("TAN"));
}
Literal& ExpressionLiteral::arctan() const {
    return this->manager->addLiteral(concat("ARCTAN"));
}
Literal& ExpressionLiteral::sqrt() const {
    return this->manager->addLiteral(concat("SQRT"));
}
Literal& ExpressionLiteral::ln() const {
    return this->manager->addLiteral(concat("LN"));
}
Literal& ExpressionLiteral::exp() const {
    return this->manager->addLiteral(concat("SIN"));
}
Literal& ExpressionLiteral::num() const {
    return this->manager->addLiteral(concat("NUM"));
}
Literal& ExpressionLiteral::den() const {
    return this->manager->addLiteral(concat("DEN"));
}
Literal& ExpressionLiteral::re() const {
    return this->manager->addLiteral(concat("RE"));
}
Literal& ExpressionLiteral::im() const {
    return this->manager->addLiteral(concat("IM"));
}
Literal& ExpressionLiteral::arg() const {
    return this->manager->addLiteral(concat("ARG"));
}
Literal& ExpressionLiteral::norm() const {
    return this->manager->addLiteral(concat("NORM"));
}
Literal& ExpressionLiteral::$(const Literal &l) const {
    return this->manager->addLiteral(concat("$", l));
}

// Opérateurs logiques
// Pour le moment, on compare juste sur les chaines évaluées.
// A voir si on fait le calcul des chaines et on vérifie que la valeur renvoyée est identique
bool ExpressionLiteral::operator==(const Literal& l) const {
    // On vérifie que l'évaluation des chaînes donne la même chose
    // Cela permet de faire abstraction des parenthèses de priorité (parfois superflues) dans les expressions
    return this->eval() == l.eval();
}
bool ExpressionLiteral::operator!=(const Literal& l) const {
    return this->eval() != l.eval();
}
bool ExpressionLiteral::operator>=(const Literal& l) const {
    return this->eval() >= l.eval();
}
bool ExpressionLiteral::operator>(const Literal& l) const  {
    return this->eval() > l.eval();
}
bool ExpressionLiteral::operator<=(const Literal& l) const  {
    return this->eval() <= l.eval();
}
bool ExpressionLiteral::operator<(const Literal& l) const  {
    return this->eval() < l.eval();
}
bool ExpressionLiteral::operator&&(const Literal& l) const {
    // Si la littérale passée en argument est un entier
    if(l.isInteger() && l.isComplex()){
        const ComplexLiteral& literal = dynamic_cast<const ComplexLiteral&>(l);

        return Number(1) && literal.getReal();
    }
    else
        return true; // Forcément des littérales différentes de 0
}
bool ExpressionLiteral::operator||(const Literal& l) const {
    return true; // Vrai dans tous les cas
}
bool ExpressionLiteral::operator!() const {
    return false; // Toujours faux
}

// Permet de récupérer la chaine évaluée même lorsque l'on a une référence sur une litérale (dynamique)
QString ExpressionLiteral::eval() const {
    return evaluate();
}

QString ExpressionLiteral::toString() const {
    int nbMaxChar = 20 - 5;

    QString result = "'" + expression.mid(0, nbMaxChar);

    if(expression.length() > nbMaxChar)
        result += "...";

    result += "'";
    return result;
}

QString ExpressionLiteral::evaluate() const {
    QStringList tokens = getTokens();
    QStack<QString> tokensStack;
    QStringList output;

    // On traite les tokens
    for(int i = 0; i < tokens.length(); i++){
        QString token = tokens[i];

        // Si le token est un nombre, on le stocke en sortie
        if(::isNumber(token) || ::isComplex(token))
            output.append(token);

        // Si c'est une variable, on va faire quelques tests pour être sûrs
        if(isVariable(token)){
            if(!this->manager->existsAtom(token))
                throw CalculatorException("Erreur : Le nom d'atome " + token + " n'existe pas.");
            else
                output.append(token); // A voir si on évalue la variable dans l'évaluation (ou si on la laisse telle qu'elle) et si oui, si on l'évalue sur une itération ou sur toute sa chaine de référence
        }

        // Si c'est une fonction, on empile
        if(isFunction(token))
            tokensStack.push(token);

        // Si c'est un séparateur d'argument
        if(token == ","){
            // Tant qu'on ne retrouve pas une parenthèse gauche, on dépile et on stocke
            // On est obligé de faire des breaks dégueux car on a des problèmes sur les fonctions de la stack lorsqu'elle est vide
            while(!tokensStack.empty()){
                if(tokensStack.top() != "(")
                    output.append(tokensStack.pop());
                else
                    break;
            }

            // Si la pile est vide sans trouver de parenthèses gauche
            if(tokensStack.empty())
                throw CalculatorException("Erreur : L'expression à convertir n'est pas valide (mauvais parenthèsage).");
        }

        // Si c'est un opérateur o1
        if(isOperator(token)){
            // Tant qu'on a un operateur o2 sur le sommet de la pile et d'une priorité inférieure, on le sort
            while(!tokensStack.empty()){
                QString top = tokensStack.top();

                if(isOperator(top) && getPriority(token) <= getPriority(top))
                    output.append(tokensStack.pop());
                else
                    break;
            }

            // On empile o1
            tokensStack.push(token);
        }

        // Si c'est une parenthèse gauche, on empile
        if(token == "(")
            tokensStack.push(token);

        // Si c'est une parenthèse droite, on dépile les opérateurs
        if(token == ")"){
            bool parenthesisFound = false;

            while(!tokensStack.empty()){
                QString top = tokensStack.pop();

                if(top == "("){
                    parenthesisFound = true;
                    break;
                }
                else
                    // Si c'est un opérateur
                    if(isOperator(top))
                        output.append(top);
            }

            // Si on a dépilé toute la pile sans trouver de parenthèse gauche
            if(!tokensStack.empty()){
                // Si le token au sommet est une fonction, on le dépile
                if(isFunction(tokensStack.top()))
                    output.append(tokensStack.pop());
            }
            else if(!parenthesisFound)
                throw CalculatorException("Erreur : L'expression à convertir n'est pas valide (mauvais parenthèsage).");
        }
    }

    // Quand on a traité le dernier token, si la pile n'est pas vide
    while(!tokensStack.empty()){
        QString remainingToken = tokensStack.pop(); // Les tokens restants

        if(remainingToken == "(")
            throw CalculatorException("Erreur : L'expression à convertir n'est pas valide (mauvais parenthèsage).");
        else if(!isOperator(remainingToken))
            throw CalculatorException("Erreur : L'expression à convertir n'est pas valide (problème d'opérateurs).");
        else
            output.append(remainingToken);
    }

    // On remplace les - qui sont d'arité 1
    int nbLiterals = 0;
    for(int i = 0; i < output.length(); i++){
        // Si on tombe sur un - et qu'il n'y a qu'une seule littérale avant
        if(output[i] == "-" && nbLiterals == 1)
            output[i] = "NEG";

        // On compte les littérales
        if(isVariable(output[i]) || ::isNumber(output[i]))
            nbLiterals++;
        else
            nbLiterals = 0;
    }

    QString formedOutput = output.join(" ");

    return formedOutput;
}
// Permet de vérifier si l'expression est valide
bool ExpressionLiteral::isValid() const {
    try {
        evaluate();
    }
    catch(const CalculatorException& e){
        return false;
    }

    return true;
}

unsigned int ExpressionLiteral::nbTokens() const {
    return getTokens().length();
}

QStringList ExpressionLiteral::getTokens() const {
    QString toParse(expression);

    // Notre regex pour spliter la chaine
    // Ancienne regex :
    // Ancienne regex : ((-?[0-9\\/]+\\$-?[0-9\\/]+)|[A-Z]+|[A-Z][0-9A-Z]*|[0-9.]+|[+\\-*\\/(),<>=]|<=|>=|!=)
    // Traite : fonction | variable | nombre | opérateurs
    QRegExp regex("([A-Z]+|[A-Z][0-9A-Z]*|[0-9.]+|[+\\-*/(),<>=$]|<=|>=|!=)");
    QStringList tokens;

    // On découpe la chaine de caractères et on récupère une liste de tokens
    int pos = 0;
    while ((pos = regex.indexIn(toParse, pos)) != -1) {
        tokens << regex.cap(1);
        pos += regex.matchedLength();
    }

    return tokens;
}

// Retourne la priorité minimale des parties non parenthésées de l'expression
int ExpressionLiteral::priority() const {
    // On récupère les tokens
    QStringList tokens = getTokens();
    int enteredInParenthesis = 0;
    int priority = 100;

    for(QStringList::iterator token = tokens.begin(); token != tokens.end(); ++token){
        // Si on est en dehors des parenthèses et que l'on a un opérateur
        if(enteredInParenthesis == 0 && isOperator(*token))
            priority = std::min(priority, getPriority(*token));

        // On compte les groupes de parenthèses
        if(*token == "(")
            enteredInParenthesis++;

        if(*token == ")")
            enteredInParenthesis--;
    }

    if(enteredInParenthesis)
        return 0;
    else
        return priority;
}
