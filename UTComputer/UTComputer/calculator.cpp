#include <QStringList>

#include "calculator.h"
#include "literal.h"
#include "atom_literal.h"

Calculator::Calculator() : stack(new Stack()), settings(new Settings()){}

Calculator::~Calculator(){
    delete stack;
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
    if (c == "POW")
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
    if (c == "MOD");

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
    if (c== "$")
        return 2;

//operateurs unaires logiques
    if (c== "NOT")
        return 1;
}

void Calculator::commandTest(const QString& c){
    QString commandText = c.toUpper();

    // On vérifie que l'on ne traite pas un unique programme ou expression
    // Si on traite un programme
    // Si on a un nombre, on le créait. A noter qu'on ne peut pas créer de complexes ou de rationnels directements ! (Même si on le fait pour charger les paramètres)
    if(isNumber(commandText) || isProgramm(commandText) || isExpression(commandText)){
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
                Literal& res = *literals[1] + *literals[0];
                stack->push(res);
            }

            if(op == "-"){
                Literal& res = *literals[1] - *literals[0];
                stack->push(res);
            }

            if(op == "*"){
                Literal& res = *literals[1] * *literals[0];
                stack->push(res);
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

            // On supprime les litérales si pas d'erreurs
            if(!error){
                for(int i = 0; i < operatorArity; i++)
                    factory.removeLiteral(*literals[i]);
            }
        }
        else
            throw CalculatorException("Erreur : Il n'y a pas assez d'arguments dans la pile pour appliquer " + commandText + ".");
    }
    // Si on traite des opérateurs de pile
    else if(isStackOperator(commandText)){
        QString op = commandText;

        if(op == "CLEAR"){
            while(!stack->empty())
                factory.removeLiteral(stack->pop());
        }

        if(op == "DUP"){
            try {
                Literal& dup = factory.addLiteralFromString(stack->top().toString());
                stack->push(dup);
            }
            catch(const CalculatorException& e){
                throw e;
            }
        }

        if(op == "DROP"){
            try{
                factory.removeLiteral(stack->pop());
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
                commandTest(l.eval());

                // Si ce n'est pas un atome ou un fils d'atome, il faudrait supprimer
//                if(!l.isAtom()){
//                    factory.removeLiteral(l);
//                }
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

            try {
                Literal& variable = factory.addLiteral(atom.toString().replace("'", ""), &target);

                stack->push(variable);
                factory.removeLiteral(atom);
                factory.removeLiteral(target);
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
                throw CalculatorException("Erreur : La pile est vide.");

            try {
                Literal& l = stack->pop();

                if(!l.isAtom())
                    throw CalculatorException("Erreur : Impossible de supprimer la variable car ce n'en est pas une.");

                // On supprime la variable et sa cible
                factory.removeLiteral(l);
            }
            catch(const CalculatorException& e){
                throw e;
            }
        }

        // Manque UNDO, REDO, LASTOP, LASTARGS

    }
    // Sinon, si on trouve un atome
    else if(factory.existsAtom(commandText)) {
        // On le récupère et on push sa cible
        try {
            Literal& atom = factory.findLiteral(commandText);
            stack->push(atom);
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
    else {
        // Sinon, si on trouve un atom

        // On récupère les commandes, splitée selon les espaces et on va les traiter une par une.
        QStringList commands = commandText.split(" ");

        // On applique de manière récursive
        for(QStringList::iterator token = commands.begin(); token != commands.end(); ++token){
            // On vérifie ce que c'est avant de lancer
            if(isOperator(*token) || isFunction(*token) || isNumber(*token) || isExpression(*token) || isProgramm(*token)){
                try {
                    this->commandTest(*token);
                }
                catch(const CalculatorException& e){
                    throw e; // On propage en cas d'erreur
                }
            }
            else
                throw CalculatorException("Erreur : Commande non reconnue.");
        }
    }
}

void Calculator::command(const QString& c) {
    //cas ou on a juste a ajouter la litterale a la pile: complexe/rationnelle//reelle/entier
    if (isNumber(c) || isComplex(c) || isRational(c))
        stack->push(factory.addLiteralFromString(c)); //on ajoute a la pile en creer une nouvelle literale à partir de la chaine de caractère passé en paramètre

    else {
        if (isExpression(c))//si c'est une expression (c a d avec les ' ')
        {
        try{
           stack->push(factory.addLiteral(c));
            }
        catch (const CalculatorException& e){
                cout << e.what()<<"\n";
            };
        }
        //si c'est un programme
        if (isProgramm(c)) // pourquoi il ne trouve pas la fonction?
        {
            int Arity = getArity(c);
            if (Arity == 2) //quand l'arité du programme est de deux
            {
                factory.removeLiteral(stack->top());//on recupere la premire opérande dans l1
                Literal& l1 = stack->pop();

                factory.removeLiteral(stack->top());//on recupere la deuxieme opérande dans l2
                Literal& l2 = stack->pop();

                if (c == "MOD"){
                    Literal& res = l1.mod(l2);
                    stack->push(res);
                }
                if (c == "DIV"){
                    Literal& res = l1.div(l2);
                    stack->push(res);
                }
                if (c == "POW"){
                    Literal& res = l1.pow(l2);
                    stack->push(res);
                }
            }
            if (Arity == 1)//quand le programme a une arité de 1
            {
                factory.removeLiteral(stack->top());//on supprime de la factory la reference du top de la pile
                Literal& l1 = stack->pop(); //on recupere la premire opérande dans l1

                if (c == "SIN")
                {
                    Literal& res = l1.sin();
                    stack->push(res);
                }
                if (c == "COS")
                {
                    Literal& res = l1.cos();
                    stack->push(res);
                }
                if (c == "TAN")
                {
                    Literal& res = l1.tan();
                    stack->push(res);
                }
                if (c == "ARCSIN")
                {
                    Literal& res = l1.arcsin();
                    stack->push(res);
                }
                if (c == "ARCCOS")
                {
                    Literal& res = l1.arccos();
                    stack->push(res);
                }
                if (c == "ARCTAN")
                {
                    Literal& res = l1.arctan();
                    stack->push(res);
                }
                if (c == "SQRT")
                {
                    Literal& res = l1.sqrt();
                    stack->push(res);
                }
                if (c == "EXP")
                {
                    Literal& res = l1.exp();
                    stack->push(res);
                }
                if (c == "LN")
                {
                    Literal& res = l1.ln();
                    stack->push(res);
                }
                if (c == "NUM")
                {
                    Literal& res = l1.num();
                    stack->push(res);
                }
                if (c == "DEN")
                {
                    try { // on test qu'il n'y a pas de probleme avec le dénominateur
                        Literal& res = l1.den();
                        stack->push(res);
                    }
                    catch (CalculatorException& e){
                        cout<<e.what()<<"\n";
                    }
                }
                if (c == "RE")
                {
                    Literal& res = l1.re();
                    stack->push(res);
                }
                if (c == "IM")
                {
                    try { //on test qu'il n'y a pas de probleme avec la partie imaginaire
                        Literal& res = l1.im();
                        stack->push(res);
                    }
                    catch (CalculatorException& e){
                        cout<<e.what()<<"\n";
                    }
                }
                if (c == "ARG")
                {
                    try {
                        Literal& res = l1.arg();
                        stack->push(res);
                    }
                    catch (CalculatorException& e){
                        cout<<e.what()<<"\n";
                    }
                }
                if (c == "NORM")
                {
                    Literal& res = l1.norm();
                    stack->push(res);
                }
            }
        }
        if (isOperator(c))
        {
            int Arity = getArity(c); //on récupère l'arité de l'opérande

            if(Arity==2) //si l'arité vaut 2
            {
                factory.removeLiteral(stack->top()); //on retire de la factory la reférence sur le top de la pile
                Literal& l1 = stack->pop();//on recupere la premire opérande dans l1

                factory.removeLiteral(stack->top()); //on retire de la factory la reférence sur le top de la pile
                Literal& l2 = stack->pop();//on recupere la deuxieme opérande dans l2

             //les operateurs arithmétiques basiques
                if (c == "+")
                {
                    try {
                    Literal& res = l1+l2;
                    stack->push(res); // on empile la Literal&
                    }
                    catch (CalculatorException& e){
                        cout << e.what()<<"\n";
                    }
                }

                if (c == "-")
                {
                    try {
                    Literal& res = l1-l2;
                    stack->push(res); // on empile la Literal&
                    }
                    catch (CalculatorException& e){
                        cout << e.what()<<"\n";
                    }
                }

                if (c == "*")
                {
                    try {
                    Literal& res = l1*l2;
                    stack->push(res); // on empile la Literal&
                    }
                    catch (CalculatorException& e){
                        cout << e.what()<<"\n";
                    }
                }

                if (c == "/")
                {
                    try {
                    Literal& res = l1/l2;
                    stack->push(res); // on empile la Literal&
                    }
                    catch (CalculatorException& e){
                        cout << e.what()<<"\n";
                    }
                }


             //les operateurs binaires logiques
             /*   if (c == "<")
                {
                    try {
                    if (l1 < l2)
                        Literal& res (1);
                    else
                        Literal& res (0);
                    }
                    catch (CalculatorException & e){
                        cout << e.what()<<"\n";
                    }
                }
                if (c == ">")
                {
                    try {
                    if (l1 > l2)
                        return Literal& res (1);
                    else
                        return Literal& res (0);
                    }
                    catch (CalculatorException & e){
                        cout << e.what()<<"\n";
                    }
                }
                if (c == "<=")
                {
                    try {
                    if (l1 <= l2)
                        return Literal& res (1);
                    else
                        return Literal& res (0);
                    }
                    catch (CalculatorException & e){
                        cout << e.what()<<"\n";
                    }
                }
                if (c == ">=")
                {
                    try {
                    if (l1 >= l2)
                        return Literal& res (1);
                    else
                        return Literal& res (0);
                    }
                    catch (CalculatorException & e){
                        cout << e.what()<<"\n";
                    }
                }
                if (c == "=")
                {
                    try {
                    if (l1 == l2)
                        return Literal& res (1);
                    else
                        return Literal& res (0);
                    }
                    catch (CalculatorException & e){
                        cout << e.what()<<"\n";
                    }
                }
                if (c == "!=")
                {
                    try {
                    if (l1 < l2)
                        return Literal& res (1);
                    else
                        return Literal& res (0);
                    }
                    catch (CalculatorException & e){
                        cout << e.what()<<"\n";
                    }
                }
                if (c == "AND")
                {
                    try {
                    if (l1 && l2)
                        return Literal& res (1);
                    else
                        return Literal& res (0);
                    }
                    catch (CalculatorException & e){
                        cout << e.what()<<"\n";
                    }
                }
                if (c == "OR")
                {
                    try {
                    if (l1 || l2)
                        return Literal& res (1);
                    else
                        return Literal& res (0);
                    }
                    catch (CalculatorException & e){
                        cout << e.what()<<"\n";
                    }
                }
                   */


                if (c == "$") {
                    try{
                        Literal& res = l1.$(l2);
                        stack->push(res); // on empile la Literal&
                    }
                    catch (CalculatorException& e){
                        cout<<e.what()<<"\n";
                    }
                }
            }


            if (Arity==1) //si l'arité vaut 1
            {
                factory.removeLiteral(stack->top()); //on retire de la factory la reférence sur le top de la pile
                Literal& l1 = stack->pop();//on recupere la premire opérande dans l1
                if (c == "NOT")
                {
                    try {
                        !l1;
                    }
                    catch (CalculatorException& e)
                    {
                        cout<<e.what()<<"\n";
                    }
                }
            }

        }

    }
}
