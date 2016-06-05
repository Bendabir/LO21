#include <QStringList>

#include "calculator.h"
#include "literal.h"

Calculator::Calculator() : stack(new Stack()), settings(new Settings()){}

Calculator::~Calculator(){
    delete stack;
}

bool isExpression(const QString& c){
    if (c[0]=='\'' && c[c.size()]=='\'')
        return true;
    else
        return false;
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

void Calculator::command(const QString& c) {
    //cas ou on a juste a ajouter la litterale a la pile: complexe/rationnelle//reelle/entier
    if (isNumber(c) || isComplex(c))
        stack->push(factory.addLiteral(c));

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
        if (isProgramm()) // pourquoi il ne le trouve pas?
        {
            int Arity = getArity(c);
            if (Arity == 2)
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
            if (Arity == 1)
            {
                factory.removeLiteral(stack->top());//on recupere la premire opérande dans l1
                Literal& l1 = stack->pop();

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
                    try {
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
                    try {
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
            int Arity = getArity(c);
            if(Arity==2)
            {
                factory.removeLiteral(stack->top());//on recupere la premire opérande dans l1
                Literal& l1 = stack->pop();

                factory.removeLiteral(stack->top());//on recupere la deuxieme opérande dans l2
                Literal& l2 = stack->pop();

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


            if (Arity==1)
            {
                factory.removeLiteral(stack->top());//on recupere la premire opérande dans l1
                Literal& l1 = stack->pop();
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
