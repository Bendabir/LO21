#include <QStringList>

#include "calculator.h"
#include "literal.h"

//Calculator::Handler Calculator::handler = Calculator::Handler();

Calculator::Calculator() : stack(new Stack()), settings(new Settings()){}

Calculator::~Calculator(){
    delete stack;
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
