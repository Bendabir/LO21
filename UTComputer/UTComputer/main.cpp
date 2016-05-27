#include <QDebug>
#include <QList>

#include "digital_literal.h"

int main(){
    DigitalLiteral x = 2.5,
                   i = 1,
                   q(1.5, -2),
                   p(33, 10);
    QList<DigitalLiteral> tests;
    tests.append(x);
    tests.append(i);
    tests.append(q);
    tests.append(p);

    for(QList<DigitalLiteral>::iterator it = tests.begin(); it != tests.end(); ++it){
        try{
            cout << *it << " : NUM " << *(*it).num() << " DEN " << *(*it).den() << endl;
        }
        catch(const CalculatorException& e){
            cout << e;
        }
    }

    try{
        cout << "x : " << x << endl;
        cout << "i : " << i << endl;
        cout << "q : " << q << endl;
        cout << "x / q : " << (x / q) << endl;
        cout << "i / q : " << (i / q) << endl;
        try {
            cout << "x / 0 : " << (x / DigitalLiteral(0)) << endl;
        }
        catch(const CalculatorException& e){
            cout << e;
        }
        cout << "q / x : " << (q / x) << endl;
        cout << "q / q : " << (q / q) << endl;
        cout << "POW(q, 2) : " << q.pow(DigitalLiteral(2)) << endl;
        cout << "i + i + i : " << (i + x + *q.num()) << endl;
    }
    catch(const CalculatorException& e){
        cout << e;
    }

    return 0;
}
