#include "factorytest.h"

FactoryTest::FactoryTest() : literals(0){}

DigitalLiteral* FactoryTest::addLiteral(int num, int den){
    // Si le denominateur vaut 1, on traite un entier
    if(den == 1)
        literals.append(new IntegerLiteral(num));
    else
        literals.append(new RationalLiteral(num, den));

    return dynamic_cast<DigitalLiteral*>(literals.last());
}

DigitalLiteral* FactoryTest::addLiteral(const IntegerLiteral& l){
    literals.append(new IntegerLiteral(l));

    return dynamic_cast<DigitalLiteral*>(literals.last());
}

DigitalLiteral* FactoryTest::addLiteral(const RationalLiteral& l){
    literals.append(new RationalLiteral(l));

    return dynamic_cast<DigitalLiteral*>(literals.last());
}

const Literal& FactoryTest::operator[](unsigned int i) const{
    return *literals[i];
}
