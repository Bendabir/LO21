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
    Literal& exp1 = fact.addLiteral("1$1");
    Literal& exp2 = fact.addLiteral("1 * 2");
    Literal& exp3 = fact.addLiteral("POW(2 + 5, 2)");

    Literal& x1 = fact.addLiteral("X1", &u);
    Literal& x2 = fact.addLiteral("X2", &x1);

    try {
        cout << u.div(i) << endl;
    }
    catch(const CalculatorException& e){
        cout << e;
    }

    return 0;
}
