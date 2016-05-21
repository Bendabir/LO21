#include <cmath>

#include "exceptions.h"
#include "literal.h"
#include "digital_literal.h"
#include "rational_literal.h"
#include "integer_literal.h"
#include "factorytest.h"

using namespace std;

int main(){
    FactoryTest factory;


    RationalLiteral q1(2, 4),
                    q2 = 23;

    IntegerLiteral e1(5);

    factory.addLiteral(q1);
    factory.addLiteral(e1);
    factory.addLiteral(q2);
    factory.addLiteral(23, 5);
    factory.addLiteral(1);

    for(int i = 0; i < factory.size(); i++)
        cout << factory[i] << endl;

    return 0;
}
