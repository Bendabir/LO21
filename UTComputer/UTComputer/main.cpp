#include <QDebug>
#include <QList>

#include "complex_literal.h"
#include "expression_literal.h"
#include "atom_literal.h"

#include "number.h"

int main(){
    LiteralFactory fact;
    Literal& z = fact.addLiteral(1, -1);
    Literal& i = fact.addLiteral(2);
    Literal& u = fact.addLiteral(3);
    Literal& exp1 = fact.addLiteral("1 + 2");
    Literal& exp2 = fact.addLiteral("1 * 2");
    try{
        Literal& exp3 = fact.addLiteral("X1 + 2");
        cout << exp3 << endl;
    }
    catch(const CalculatorException& e){
        cout << e;
    }

    Literal& x1 = fact.addLiteral("X1", &u);

    try {
        Literal& x2 = fact.addLiteral("X2", &x1);
        cout << (x1 + exp2) << endl;
    }
    catch(const CalculatorException& e){
        cout << e;
    }

    return 0;
}
