#include "number_literal.h"

// DIV
IntegerLiteral div(const IntegerLiteral& l1, const IntegerLiteral& l2){
    return l1.getNumber() / l2.getNumber();
}

// MOD
IntegerLiteral operator%(const IntegerLiteral& l1, const IntegerLiteral& l2){
    return l1.getNumber() % l2.getNumber();
}
IntegerLiteral mod(const IntegerLiteral& l1, const IntegerLiteral& l2){
    return l1 % l2;
}
