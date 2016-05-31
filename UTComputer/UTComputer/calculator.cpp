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

//void Calculator::command(const QString& token){
//    if(isNumber(token))
//        stack->push(factory.addLiteral(token.toDouble()));

//    if(isRational(token)){
//        QStringList rationalParts = token.split("/");

//        stack->push(factory.addLiteral(rationalParts.at(0).toDouble(), rationalParts.at(0).toDouble());
//    }

//    if(isComplex(token)){
//        QStringList complexPart = token.split("$");
//    }

//}

//Calculator& Calculator::start(){
//    if(!handler.instance)
//        handler.instance = new Calculator();

//    return *handler.instance;
//}

//void Calculator::stop(){
//    delete handler.instance;
//    handler.instance = 0;
//}
