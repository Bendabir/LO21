#include <typeinfo>
#include <iostream>
#include <string>
#include <complex>

#include "exceptions.h"
#include "literal.h"
#include "digital_literal.h"
#include "rational_literal.h"
#include "number_literal.h"
#include "literal_factory.h"

// Déclaration dégueu pour du test
// A terme, le manager est créée dans la classe singleton Application (seule classe qui peut l'instancier)
LiteralFactory manager;

using namespace std;

IntegerLiteral eval(const IntegerLiteral& l) {
   return l;
}

int main(){
//    LiteralFactory manager;

    cout << manager;

    Literal& i = manager.addLiteral(1);
    Literal& q = manager.addLiteral(1, 3);
    Literal& x = manager.addLiteral(0.5);


//    IntegerLiteral& i = manager.addLiteral(1);



//    IntegerLiteral i = 2;
//    RealLiteral x = 2.5;

//    using Test = pair<IntegerLiteral, IntegerLiteral>;
//    using Tests = Test[];
//    const Tests tests {
//        {i, 2},
//        {i / i, 1}
//    };
//    for (auto test: tests) {
//        const auto result = eval(test.first);
//        cout << '\"' << test.first << "\" == " << result <<
//            (test.second == result ? " [pass]" : " [fail]") << endl;
//    }


//    IntegerLiteral i = 2,
//                   k = 3;
//    RealLiteral j = 2.5;
//    RationalLiteral q(2, 3),
//                    p(3, 6);

////    cout << p << endl;
////    cout << p++ << endl;
////    cout << p << endl;
////    cout << ++p << endl;
////    cout << p-- << endl;
////    cout << p << endl;
////    cout << --p << endl;

//    cout << "i : " << i << " (" << typeid(i).name() << ")" << endl;
//    cout << "j : " << j << " (" << typeid(j).name() << ")" << endl;
//    cout << "q : " << q << " (" << typeid(q).name() << ")" << endl;
//    cout << "p : " << p << " (" << typeid(p).name() << ")" << endl;
//    cout << "--------------------------------" << endl;
//    cout << "i + i : " << (i + i) << " (" << typeid(i + i).name() << ")" << endl;
//    cout << "j + j : " << (j + j) << " (" << typeid(j + j).name() << ")" << endl;
//    cout << "i + j : " << (i + j) << " (" << typeid(i + j).name() << ")" << endl;
//    cout << "j + i : " << (j + i) << " (" << typeid(j + i).name() << ")" << endl;
//    cout << "q + p : " << (q + p) << " (" << typeid(q + p).name() << ")" << endl;
//    cout << "p + q : " << (p + q) << " (" << typeid(p + q).name() << ")" << endl;
//    cout << "q + i : " << (q + i) << " (" << typeid(q + i).name() << ")" << endl;
////    cout << "i + q : " << (i + q) << " (" << typeid(i + q).name() << ")" << endl;
//    cout << "--------------------------------" << endl;
//    cout << "i - i : " << (i - i) << " (" << typeid(i - i).name() << ")" << endl;
//    cout << "j - j : " << (j - j) << " (" << typeid(j - j).name() << ")" << endl;
//    cout << "i - j : " << (i - j) << " (" << typeid(i - j).name() << ")" << endl;
//    cout << "j - i : " << (j - i) << " (" << typeid(j - i).name() << ")" << endl;
//    cout << "--------------------------------" << endl;
//    cout << "i * i : " << (i * i) << " (" << typeid(i * i).name() << ")" << endl;
//    cout << "j * j : " << (j * j) << " (" << typeid(j * j).name() << ")" << endl;
//    cout << "i * j : " << (i * j) << " (" << typeid(i * j).name() << ")" << endl;
//    cout << "j * i : " << (j * i) << " (" << typeid(j * i).name() << ")" << endl;
//    cout << "--------------------------------" << endl;

//    cout << "--------------------------------" << endl;
//    try{
//        cout << "i DIV k : " << div(i, k) << " (" << typeid(div(i, k)).name() << ")" << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e.what() << endl;
//    }
//    try{
//    cout << "k DIV i : " << div(k, i) << " (" << typeid(div(k, i)).name() << ")" << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e.what() << endl;
//    }
//    cout << "--------------------------------" << endl;
//    try{
//        cout << "i MOD k : " << (i % k) << " (" << typeid(i % k).name() << ")" << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e.what() << endl;
//    }
//    try{
//        cout << "k MOD i : " << (k % i) << " (" << typeid(k %i).name() << ")" << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e.what() << endl;
//    }
//    cout << "--------------------------------" << endl;
//    cout << "i POW i : " << pow(i, i) << " (" << typeid(pow(i, i)).name() << ")" << endl;
//    cout << "j POW j : " << pow(j, j) << " (" << typeid(pow(j, j)).name() << ")" << endl;
//    cout << "i POW j : " << pow(i, j) << " (" << typeid(pow(i, j)).name() << ")" << endl;
//    cout << "j POW i : " << pow(j, i) << " (" << typeid(pow(j, i)).name() << ")" << endl;
//    cout << "--------------------------------" << endl;
//    cout << "-i : " << -i << " (" << typeid(-i).name() << ")" << endl;
//    cout << "-j : " << -j << " (" << typeid(-j).name() << ")" << endl;
//    cout << "--------------------------------" << endl;
//    cout << "SIN i : " << sin(i) << " (" << typeid(sin(i)).name() << ")" << endl;
//    cout << "SIN j : " << sin(j) << " (" << typeid(sin(j)).name() << ")" << endl;
//    try{
//        cout << "ARCSIN i : " << arcsin(i) << " (" << typeid(arcsin(i)).name() << ")" << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e.what() << endl;
//    }
//    try{
//        cout << "ARCSIN j : " << arcsin(j) << " (" << typeid(arcsin(j)).name() << ")" << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e.what() << endl;
//    }
//    cout << "--------------------------------" << endl;
//    cout << "COS i : " << cos(i) << " (" << typeid(cos(i)).name() << ")" << endl;
//    cout << "COS j : " << cos(j) << " (" << typeid(cos(j)).name() << ")" << endl;
//    try{
//        cout << "ARCCOS i : " << arccos(i) << " (" << typeid(arccos(i)).name() << ")" << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e.what() << endl;
//    }
//    try{
//        cout << "ARCCOS j : " << arccos(j) << " (" << typeid(arccos(j)).name() << ")" << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e.what() << endl;
//    }
//    cout << "--------------------------------" << endl;
//    cout << "TAN i : " << tan(i) << " (" << typeid(tan(i)).name() << ")" << endl;
//    cout << "TAN j : " << tan(j) << " (" << typeid(tan(j)).name() << ")" << endl;
//    try{
//     cout << "ARCTAN i : " << arctan(i) << " (" << typeid(arctan(i)).name() << ")" << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e.what() << endl;
//    }
//    try{
//    cout << "ARCTAN j : " << arctan(j) << " (" << typeid(arctan(j)).name() << ")" << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e.what() << endl;
//    }
//    cout << "--------------------------------" << endl;
//    cout << "SQRT i : " << sqrt(i) << " (" << typeid(sqrt(i)).name() << ")" << endl;
//    cout << "SQRT j : " << sqrt(j) << " (" << typeid(sqrt(j)).name() << ")" << endl;
//    try{
//        cout << "SQRT -i : " << sqrt(-i) << " (" << typeid(sqrt(-i)).name() << ")" << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e.what() << endl;
//    }
//    try{
//        cout << "SQRT -j : " << sqrt(-j) << " (" << typeid(sqrt(-j)).name() << ")" << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e.what() << endl;
//    }
//    cout << "--------------------------------" << endl;
//    cout << "EXP i : " << exp(i) << " (" << typeid(exp(i)).name() << ")" << endl;
//    cout << "EXP j : " << exp(j) << " (" << typeid(exp(j)).name() << ")" << endl;
//    cout << "EXP -i : " << exp(-i) << " (" << typeid(exp(-i)).name() << ")" << endl;
//    cout << "EXP -j : " << exp(-j) << " (" << typeid(exp(-j)).name() << ")" << endl;
//    cout << "--------------------------------" << endl;
//    cout << "LN i : " << ln(i) << " (" << typeid(ln(i)).name() << ")" << endl;
//    cout << "LN j : " << ln(j) << " (" << typeid(ln(j)).name() << ")" << endl;
//    try{
//        cout << "LN -i : " << ln(-i) << " (" << typeid(ln(-i)).name() << ")" << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e.what() << endl;
//    }
//    try{
//        cout << "LN -j : " << ln(-j) << " (" << typeid(ln(-j)).name() << ")" << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e.what() << endl;
//    }
//    cout << "--------------------------------" << endl;
//    cout << "NUM i : " << num(i) << " (" << typeid(num(i)).name() << ")" << endl;
//    try{
//        cout << "NUM j : " << num(j) << " (" << typeid(num(j)).name() << ")" << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e.what() << endl;
//    }
//    cout << "--------------------------------" << endl;
//    cout << "DEN i : " << den(i) << " (" << typeid(den(i)).name() << ")" << endl;
//    try{
//        cout << "DEN j : " << den(j) << " (" << typeid(den(j)).name() << ")" << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e.what() << endl;
//    }
//    cout << "--------------------------------" << endl;
    return 0;
}
