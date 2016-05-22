#include "number_literal.h"

// DIV
IntegerLiteral div(const IntegerLiteral& l1, const IntegerLiteral& l2){
    if(l2 == 0)
        throw CalculatorException("Erreur : Division par 0 impossible.");

    return l1.getNumber() / l2.getNumber();
}

// MOD
IntegerLiteral operator%(const IntegerLiteral& l1, const IntegerLiteral& l2){
    if(l2 == 0)
        throw CalculatorException("Erreur : Impossible de calculer le reste d'une division par 0.");

    return l1.getNumber() % l2.getNumber();
}
//IntegerLiteral mod(const IntegerLiteral& l1, const IntegerLiteral& l2){
//    return l1 % l2;
//}

// NUM
IntegerLiteral num(const IntegerLiteral& l){
    return l;
}
RealLiteral num(const RealLiteral& l){
    throw CalculatorException("Erreur : La fonction NUM ne peut s'appliquer qu'à des entiers ou des rationnels.");
}

// DEN
IntegerLiteral den(const IntegerLiteral& l){
    return 1;
}
RealLiteral den(const RealLiteral& l){
    throw CalculatorException("Erreur : La fonction DEN ne peut s'appliquer qu'à des entiers ou des rationnels.");
}
