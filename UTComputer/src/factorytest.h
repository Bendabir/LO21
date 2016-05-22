#ifndef FACTORYTEST_H
#define FACTORYTEST_H

#include <QVector>
#include <QDebug>

#include "literal.h"
#include "digital_literal.h"
#include "rational_literal.h"
#include "number_literal.h"

class FactoryTest {
private:
    QVector<Literal*> literals;

public:
    explicit FactoryTest();

//    DigitalLiteral* addLiteral(int num = 0, int den = 1);
//    DigitalLiteral* addLiteral(const IntegerLiteral& l);
//    DigitalLiteral* addLiteral(const RationalLiteral& l);

    int size() const {return literals.size();}

    const Literal& operator[](unsigned int i) const;
};

#endif // FACTORYTEST_H
