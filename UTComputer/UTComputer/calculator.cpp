#include <QStringList>
#include <QRegExp>
#include <QDebug>

#include "calculator.h"
#include "literal.h"
#include "atom_literal.h"

Calculator::Calculator() : stack(new Stack()), settings(new Settings()), mementoIndex(0), topIndex(0){}

Calculator::~Calculator(){
    delete stack;
    delete settings;
}

unsigned int getArity(const QString &c){
//operateurs binaires numériques
    if (c == "+")
        return 2;
    if (c == "-")
        return 2;
    if (c == "*")
        return 2;
    if (c == "/")
        return 2;
    if (c == "DIV")
        return 2;
    if (c == "MOD")
        return 2;
    if (c == "POW")
        return 2;
    if (c== "$")
        return 2;

 //operateurs unaires numériques
    if (c== "NEG")
        return 1;
    if (c == "SIN")
        return 1;
    if (c == "COS")
        return 1;
    if (c == "TAN")
        return 1;
    if (c == "ARCSIN")
        return 1;
    if (c == "ARCCOS")
        return 1;
    if (c == "ARCTAN")
        return 1;
    if (c == "SQRT")
        return 1;
    if (c == "EXP")
        return 1;
    if (c == "LN")
        return 1;
    if (c == "NUM")
        return 1;
    if (c == "DEN")
        return 1;
    if (c == "RE")
        return 1;
    if (c == "IM")
        return 1;
    if (c == "ARG")
        return 1;
    if (c == "NORM")
        return 1;

//operateurs binaires logiques
    if (c == ">")
        return 2;
    if (c == "<")
        return 2;
    if (c == ">=")
        return 2;
    if (c == "<=")
        return 2;
    if (c == "=")
        return 2;
    if (c == "!=")
        return 2;
    if (c== "AND")
        return 2;
    if (c== "OR")
        return 2;

//operateurs unaires logiques
    if (c== "NOT")
        return 1;

    return 0;
}

void Calculator::command(const QString& c){
    if(c.isEmpty())
        return;


    QString commandText = c.toUpper().trimmed();

    // On sauvegarde l'état de la pile
    if(commandText != "UNDO" && commandText != "REDO"){
        // Si on a atteint la fin du tableau, on décale tout pour continuer à stocker
        if(mementoIndex >= HISTORY_SIZE - 1){
            for(int i = 0; i < HISTORY_SIZE - 1; i++)
                mementoList[i] = mementoList[i + 1];

            mementoIndex = HISTORY_SIZE - 1;
        }

        mementoList[mementoIndex] = stack->createMemento();

        if (mementoIndex > topIndex)
                  topIndex = mementoIndex;

        mementoIndex++;

        qDebug() << "INDEX : " << mementoIndex;
    }

    // On vérifie que l'on ne traite pas un unique programme ou expression
    // Si on traite un programme
    // Si on a un nombre, on le créait. A noter qu'on ne peut pas créer de complexes ou de rationnels directements ! (Même si on le fait pour charger les paramètres)
    if(isNumber(commandText) || isProgramm(commandText) || isExpression(commandText) || isComplex(commandText) || isRational(commandText)){
        try {

            stack->push(factory.addLiteralFromString(commandText));
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
    else if(isOperator(commandText) || isFunction(commandText)){
        QString op = commandText;
        int operatorArity = getArity(op);
        bool error = false;

        // Si on a suffisamment d'arguments dans la pile pour appliquer l'opérateur
        if(stack->size() >= operatorArity){
            // On récupère les litérales
            QVector<Literal*> literals;

            for(int i = 0; i < operatorArity; i++)
                literals.append(&stack->pop()); // On pop la littérale, on les supprimera après

            // On traite
            if(op == "+"){
                try {
                    Literal& res = *literals[1] + *literals[0];

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }

            }

            if(op == "-"){
                try {
                    Literal& res = *literals[1] - *literals[0];

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            if(op == "*"){
                try {
                    Literal& res = *literals[1] * *literals[0];

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            if(op == "/"){
                try {
                    Literal& res = *literals[1] / *literals[0];

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);


                    error = true;
                    throw e;
                }
            }

            if(op == "DIV"){
                try {
                    Literal& res = literals[1]->div(*literals[0]);

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);


                    error = true;
                    throw e;
                }
            }

            if(op == "MOD"){
                try {
                    Literal& res = literals[1]->mod(*literals[0]);

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);


                    error = true;
                    throw e;
                }
            }

            if(op == "POW"){
                try {
                    Literal& res = literals[1]->pow(*literals[0]);

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);


                    error = true;
                    throw e;
                }
            }

            if(op == "NEG"){
                Literal& res = -*literals[0];

                stack->push(res);
            }

            if(op == "SIN"){
                Literal& res = literals[0]->sin();

                stack->push(res);
            }

            if(op == "COS"){
                Literal& res = literals[0]->cos();

                stack->push(res);
            }

            if(op == "TAN"){
                Literal& res = literals[0]->tan();

                stack->push(res);
            }

            if(op == "ARCSIN"){
                try {
                    Literal& res = literals[0]->arcsin();

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);


                    error = true;
                    throw e;
                }
            }

            if(op == "ARCCOS"){
                try {
                    Literal& res = literals[0]->arccos();

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            if(op == "ARCTAN"){
                Literal& res = literals[0]->arctan();

                stack->push(res);
            }

            if(op == "SQRT"){
                try {
                    Literal& res = literals[0]->sqrt();

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            if(op == "EXP"){
                Literal& res = literals[0]->exp();

                stack->push(res);
            }

            if(op == "LN"){
                try {
                    Literal& res = literals[0]->ln();

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            if(op == "DEN"){
                try {
                    Literal& res = literals[0]->den();

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            if(op == "NUM"){
                try {
                    Literal& res = literals[0]->num();

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            if(op == "$"){
                try {
                    Literal& res = literals[1]->$(*literals[0]);

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            if(op == "RE"){
                Literal& res = literals[0]->re();

                stack->push(res);
            }

            if(op == "IM"){
                Literal& res = literals[0]->im();

                stack->push(res);
            }

            if(op == "ARG"){
                try {
                    Literal& res = literals[0]->arg();

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            if(op == "NORM"){
                try {
                    Literal& res = literals[0]->norm();

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            // Opérateurs logiques des familles
            if(op == "="){
                try {
                    Literal& res = *literals[1] == *literals[0];

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            if(op == "!="){
                try {
                    Literal& res = *literals[1] != *literals[0];

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            if(op == ">="){
                try {
                    Literal& res = *literals[1] >= *literals[0];

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            if(op == ">"){
                try {
                    Literal& res = *literals[1] > *literals[0];

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            if(op == "<="){
                try {
                    Literal& res = *literals[1] <= *literals[0];

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            if(op == "<"){
                try {
                    Literal& res = *literals[1] < *literals[0];

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            if(op == "NOT"){
                try {
                    Literal& res = !*literals[0];

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit
                    stack->push(*literals[0]);

                    error = true;
                    throw e;
                }
            }

            if(op == "AND"){
                try {
                    Literal& res = *literals[1] && *literals[0];

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            if(op == "OR"){
                try {
                    Literal& res = *literals[1] || *literals[0];

                    stack->push(res);
                }
                catch(const CalculatorException& e){
                    // On rétablit les littérales
                    for(int i = literals.length() - 1; i >= 0; i--)
                        stack->push(*literals[i]);

                    error = true;
                    throw e;
                }
            }

            // On supprime les litérales si pas d'erreurs
            if(!error){
                cleanLastArgs();

                // On sauvegarde les littérales dans lastargs
                for(int i = 0; i < operatorArity; i++)
                    lastargs.push_back(literals[i]);

                lastop = op; // On sauvegarde le dernier opérateur
            }
        }
        else
            throw CalculatorException("Erreur : Il n'y a pas assez d'arguments dans la pile pour appliquer " + commandText + ".");
    }
    // Si on traite des opérateurs de pile
    else if(isStackOperator(commandText)){
        QString op = commandText;

        if(op == "CLEAR"){

            while(!stack->empty()){
                cleanLastArgs();

                Literal& pop = stack->pop();

                if(!pop.isAtom())
                    factory.removeLiteral(pop);
            }
        }

        if(op == "DUP"){
            try {
                Literal& dup = stack->top();

                stack->push(dup);

                // On retient l'argument dans lastargs
                cleanLastArgs();
                lastargs.push_back(&dup);
            }
            catch(const CalculatorException& e){
                throw e;
            }
        }

        if(op == "DROP"){
            try{
                // On nettoie lastargs (nettoie la factory au passage) puis on retient le dernier élément dépilé
                cleanLastArgs();

                lastargs.push_back(&stack->pop());
            }
            catch(const CalculatorException& e){
                throw e;
            }
        }

        if(op == "SWAP"){
            if(stack->size() < 2)
                throw CalculatorException("Erreur : Impossible d'échanger les deux premiers éléments de la pile (pas assez d'éléments).");

            try {
                Literal& l1 = stack->pop();
                Literal& l2 = stack->pop();



                stack->push(l1);
                stack->push(l2);

                cleanLastArgs();
                lastargs.push_back(&l1);
                lastargs.push_back(&l2);
            }
            catch(const CalculatorException& e){
                throw e;
            }
        }

        if(op == "EVAL"){
            if(stack->size() < 1)
                throw CalculatorException("Erreur : Impossible d'évaluer le premier élément de la pile car elle est vide.");

            Literal& l = stack->pop();

            try {

                command(l.eval()); // Pose un problème (sauf si l'on autorise l'ajout de rationnels ou de complexes depuis leur forme string

                // On sauvegarde la litérale utilisée
                cleanLastArgs();
                lastargs.push_back(&l);
            }
            catch(const CalculatorException& e){
                // On rétablit
                stack->push(l);

                throw e;
            }
        }

        if(op == "STO"){
            if(stack->size() < 2)
                throw CalculatorException("Erreur : Pas assez d'éléments dans la pile pour créer une variable.");

            Literal& atom = stack->pop(); // L'identificateur
            Literal& target = stack->pop(); // La variable pointée

            QString atomName = atom.toString().replace("'", "");



            try {
                // On regarde si la variable existe, sinon on écrase
                if(factory.existsAtom(atomName)){
                    AtomLiteral& variable = dynamic_cast<AtomLiteral&>(factory.findLiteral(atomName));
                    factory.removeLiteral(variable.getTarget());
                    variable.setTarget(target);
                    stack->push(variable);
                }
                else{
                    Literal& variable = factory.addLiteral(atomName, &target);
                    stack->push(variable);
                }

                cleanLastArgs();
                lastargs.push_back(&atom);
                lastargs.push_back(&target);
            }
            catch(const CalculatorException& e){
                // On rétablit
                stack->push(target);
                stack->push(atom);

                throw e;
            }
        }

        if(op == "FORGET"){
            if(stack->size() < 1)
                throw CalculatorException("Erreur : Il faut d'abord empiler la variable à supprimer.");

            Literal& l = stack->pop();

            try {
                if(!l.isAtom())
                    throw CalculatorException("Erreur : Impossible de supprimer la variable car ce n'en est pas une.");

                // On supprime la variable et sa cible
                factory.removeLiteral(l);
            }
            catch(const CalculatorException& e){
                stack->push(l); // On rétablit

                throw e;
            }
        }

        if(op == "LASTOP")
            command(lastop);

        if(op == "LASTARGS"){
            if(lastargs.isEmpty())
                throw CalculatorException("Erreur : Impossible d'utiliser les dernières opérandes car il n'y en avait pas.");

            for(int i = lastargs.length() - 1; i >= 0; i--)
                stack->push(*lastargs[i]);
        }

        if(op == "IFT"){
            // On dépile deux arguments
            QVector<Literal*> literals;

            if(stack->size() < 2)
                throw CalculatorException("Erreur : Pas assez d'arguments dans pile pour effectuer le test.");

            for(int i = 0; i < 2; i++){
                Literal& res = stack->pop();

                cleanLastArgs();
                lastargs.push_back(&res);
                literals.append(&res); // On pop la littérale, on les supprimera après
            }

            // Si le dernier argument dépilé est vrai
            if(literals[1]->toString() != "0")
                command(literals[0]->eval());
        }

        if(op == "IFTE"){
            // On dépile deux arguments
            QVector<Literal*> literals;

            if(stack->size() < 3)
                throw CalculatorException("Erreur : Pas assez d'arguments dans pile pour effectuer le test.");

            for(int i = 0; i < 3; i++){
                Literal& res = stack->pop();

                cleanLastArgs();
                lastargs.append(&res);
                literals.append(&res); // On pop la littérale, on les supprimera après
            }

            // Si le dernier argument dépilé est vrai
            if(literals[2]->toString() != "0")
                command(literals[1]->eval());
            else
                command(literals[0]->eval());
        }

        if(op == "UNDO"){
            try{
                undo();
            }
            catch(const CalculatorException& e){
                throw e;
            }
        }

        if(op == "REDO"){
            try{
                redo();
            }
            catch(const CalculatorException& e){
                throw e;
            }

        }

        // On sauvegarde le dernier opérateur
        if(op != "LASTOP")
            lastop = op; // On sauvegarde l'opérateur

    }
    // Sinon, si on trouve un atome
    else if(factory.existsAtom(commandText)) {
        // On le récupère et on push l'atome (sinon, on ne peut pas le supprimer)
        try {
            AtomLiteral& atom = dynamic_cast<AtomLiteral&>(factory.findLiteral(commandText));
            stack->push(atom);
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
    else {
        // On récupère les commandes, splitée selon une regex et on va les traiter une par une.
        QRegExp regex("(\\[.+\\]|'.+'|[A-Z]+|[A-Z][0-9A-Z]*|[0-9.]+|[+\\-*/(),<>=$]|<=|>=|!=)");

        QStringList commands;

        // On découpe la chaine de caractères et on récupère une liste de tokens
        int pos = 0;
        while ((pos = regex.indexIn(commandText, pos)) != -1) {
            commands << regex.cap(1);
            pos += regex.matchedLength();
        }

        // Sinon, si on trouve un atome inexistant, on crée une chaine qui prend la valeur de l'atome
        if(commands.length() == 1){
            try{
                stack->push(factory.addLiteralFromString("'" + commands[0] + "'"));
            }
            catch(const CalculatorException& e){
                throw e;
            }
        }
        else
            // On applique de manière récursive
            for(int i = 0; i < commands.length(); i++){
                // On vérifie ce que c'est avant de lancer
                if(isOperator(commands[i]) || isStackOperator(commands[i]) || isFunction(commands[i]) || isNumber(commands[i]) || isExpression(commands[i]) || isProgramm(commands[i]) || isVariable(commands[i])){
                    try {
                        this->command(commands[i]);
                    }
                    catch(const CalculatorException& e){
                        throw e; // On propage en cas d'erreur
                    }
                }
                else
                    throw CalculatorException("Erreur : Commande non reconnue ou opération impossible.");
            }
    }
}

void Calculator::cleanLastArgs(){
    // On supprime les littérales dans lastargs si ce n'est pas un atome et si ce n'est pas dans la pile. Il ne faut pas supprimer les cibles de variables non plus
    for(int i = 0; i < lastargs.length(); i++){
        QString exp = lastargs[i]->toString();

        if(!lastargs[i]->isAtom() && !stack->contains(*lastargs[i])){
            exp += " (Removed)";
            factory.removeLiteral(*lastargs[i]);
        }

//        qDebug() << exp;
    }

    lastargs.clear();
}

void Calculator::undo(){
    if(mementoIndex == 0)
        throw CalculatorException("Erreur : Impossible d'annuler car aucune action n'a été effectuée !");

    stack->restoreMemento(mementoList[--mementoIndex], factory);

    qDebug() << "UNDOING : " + mementoIndex;
}

void Calculator::redo(){
    if(mementoIndex > topIndex)
        throw CalculatorException("Erreur : Impossible de rétablir car il n'y a plus rien à rétablir.");

    qDebug() << "REDOING : " + mementoIndex;

    stack->restoreMemento(mementoList[mementoIndex++], factory);

}
