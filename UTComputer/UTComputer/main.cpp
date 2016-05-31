#include <QDebug>
#include <QList>

#include "complex_literal.h"
#include "expression_literal.h"
#include "atom_literal.h"

#include "number.h"

int main(){
    LiteralFactory fact;
    Literal& z = fact.addLiteral(1, -1);
    Literal& i = fact.addLiteral(Number(2.3, -9.6));
    Literal& exp1 = fact.addLiteral("1 + 2");
    Literal& exp2 = fact.addLiteral("1 * 2");
    Literal& exp3 = fact.addLiteral("POW(2 + 5, 2)");

    cout << exp1 << " : " << dynamic_cast<ExpressionLiteral&>(exp1).priority() << endl;
    cout << exp2 << " : " << dynamic_cast<ExpressionLiteral&>(exp2).priority() << endl;
    cout << exp3 << " : " << dynamic_cast<ExpressionLiteral&>(exp3).priority() << endl;
    cout << (exp1 * exp3) << " : " << dynamic_cast<ExpressionLiteral&>(exp1 * exp3).priority() << endl;

    Literal& x1 = fact.addLiteral("X1", &i);
    Literal& x2 = fact.addLiteral("X2", &x1);

    try{
        Literal& sin = fact.addLiteral("SINI", &i.sin());
        cout << sin << " : " << sin.sin() << endl;
    }
    catch(const CalculatorException& e){
        cout << e;
    }

    cout << i << " : " << i.sin() << endl;
    cout << x1 << " : " << x1.sin() << endl;
    cout << x2 << " : " << x2.sin() << endl;


    return 0;
}
