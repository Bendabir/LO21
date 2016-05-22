
#include <cmath>
#include <typeinfo>

#include "exceptions.h"
#include "literal.h"
#include "digital_literal.h"
#include "rational_literal.h"
#include "factorytest.h"
#include "number_literal.h"

using namespace std;

int main(){
    IntegerLiteral i = 2,
                   k = 3;
    RealLiteral j = 2.5;

    cout << (2 / 2) << " (" << typeid(2 / 2).name() << ")" << endl;
    cout << (2.3 / 2) << " (" << typeid(2.3 / 2).name() << ")" << endl;

    cout << "i : " << i << " (" << typeid(i).name() << ")" << endl;
    cout << "j : " << j << " (" << typeid(j).name() << ")" << endl;
    cout << "--------------------------------" << endl;
    cout << "i + i : " << (i + i) << " (" << typeid(i + i).name() << ")" << endl;
    cout << "j + j : " << (j + j) << " (" << typeid(j + j).name() << ")" << endl;
    cout << "i + j : " << (i + j) << " (" << typeid(i + j).name() << ")" << endl;
    cout << "j + i : " << (j + i) << " (" << typeid(j + i).name() << ")" << endl;
    cout << "--------------------------------" << endl;
    cout << "i - i : " << (i - i) << " (" << typeid(i - i).name() << ")" << endl;
    cout << "j - j : " << (j - j) << " (" << typeid(j - j).name() << ")" << endl;
    cout << "i - j : " << (i - j) << " (" << typeid(i - j).name() << ")" << endl;
    cout << "j - i : " << (j - i) << " (" << typeid(j - i).name() << ")" << endl;
    cout << "--------------------------------" << endl;
    cout << "i * i : " << (i * i) << " (" << typeid(i * i).name() << ")" << endl;
    cout << "j * j : " << (j * j) << " (" << typeid(j * j).name() << ")" << endl;
    cout << "i * j : " << (i * j) << " (" << typeid(i * j).name() << ")" << endl;
    cout << "j * i : " << (j * i) << " (" << typeid(j * i).name() << ")" << endl;
    cout << "--------------------------------" << endl;



    cout << "--------------------------------" << endl;
    cout << "i DIV k : " << div(i, k) << " (" << typeid(div(i, k)).name() << ")" << endl;
    cout << "k DIV i : " << div(k, i) << " (" << typeid(div(i, k)).name() << ")" << endl;
    cout << "--------------------------------" << endl;
    cout << "i MOD k : " << mod(i, k) << " (" << typeid(mod(i, k)).name() << ")" << endl;
    cout << "k MOD i : " << mod(k, i) << " (" << typeid(mod(i, k)).name() << ")" << endl;
    cout << "--------------------------------" << endl;



//    cout << "i * j : " << (i * j) << endl;
//    cout << "j * i : " << (j * i) << endl;
////    cout << "i / j : " << (i / j) << endl;
////    cout << "j / i : " << (j / i) << endl;
//    cout << "i % j : " << (i % j) << endl;
//    cout << "j % i : " << (j % i) << endl;
//    cout << "i DIV j : " << i.div(j) << endl;
//    cout << "j DIV i : " << j.div(i) << endl;

    return 0;
}
