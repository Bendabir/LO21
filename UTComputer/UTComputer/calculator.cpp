#include <QStringList>

#include "calculator.h"
#include "literal.h"

//Calculator::Handler Calculator::handler = Calculator::Handler();

Calculator::Calculator(){
    stack = new Stack();
}

Calculator::~Calculator(){
    delete stack;
}

void Calculator::command(const string& c) {
	//cas ou on a juste a ajouter la litterale a la pile: complexe/rationnelle//reelle/entier
	if (isNumber(c) || isComplex(c))
		stack->push(factory.addLiteral(QString::fromStdString(c));
	else {
		//si c'est une expression (c a d avec les " ")
		if (isExpression(c))
		{
			if (QString::fromStdString(c).isValid())
			{
				//on evalue l'expression et on push le resultat dans la pile
				//le type a evaluer me parait pas correct
				stack->push(factory.addLiteral(QString::fromStdString(c.evaluate()));
			}
			else
				throw CalculatorException("ERROR EVAL: L'expression entrée n'est pas valide.")
		}
		//si c'est un programme
		if (isProgramm(c))
		{

		}
		//si c'est un atom
		if (isAtom(c))
		{

		}
	}
}

//Calculator& Calculator::start(){
//    if(!handler.instance)
//        handler.instance = new Calculator();

//    return *handler.instance;
//}

//void Calculator::stop(){
//    delete handler.instance;
//    handler.instance = 0;
//}
