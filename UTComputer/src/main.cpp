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

//    cout << i << endl;
//    cout << i-- << endl;
//    cout << i << endl;
//    cout << --i << endl;

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
    try{
        cout << "i DIV k : " << div(i, k) << " (" << typeid(div(i, k)).name() << ")" << endl;
    }
    catch(const CalculatorException& e){
        cout << e.what() << endl;
    }
    try{
    cout << "k DIV i : " << div(k, i) << " (" << typeid(div(k, i)).name() << ")" << endl;
    }
    catch(const CalculatorException& e){
        cout << e.what() << endl;
    }
    cout << "--------------------------------" << endl;
    try{
        cout << "i MOD k : " << (i % k) << " (" << typeid(i % k).name() << ")" << endl;
    }
    catch(const CalculatorException& e){
        cout << e.what() << endl;
    }
    try{
        cout << "k MOD i : " << (k % i) << " (" << typeid(k %i).name() << ")" << endl;
    }
    catch(const CalculatorException& e){
        cout << e.what() << endl;
    }
    cout << "--------------------------------" << endl;
    cout << "i POW i : " << pow(i, i) << " (" << typeid(pow(i, i)).name() << ")" << endl;
    cout << "j POW j : " << pow(j, j) << " (" << typeid(pow(j, j)).name() << ")" << endl;
    cout << "i POW j : " << pow(i, j) << " (" << typeid(pow(i, j)).name() << ")" << endl;
    cout << "j POW i : " << pow(j, i) << " (" << typeid(pow(j, i)).name() << ")" << endl;
    cout << "--------------------------------" << endl;
    cout << "-i : " << -i << " (" << typeid(-i).name() << ")" << endl;
    cout << "-j : " << -j << " (" << typeid(-j).name() << ")" << endl;
    cout << "--------------------------------" << endl;
    cout << "SIN i : " << sin(i) << " (" << typeid(sin(i)).name() << ")" << endl;
    cout << "SIN j : " << sin(j) << " (" << typeid(sin(j)).name() << ")" << endl;
    try{
        cout << "ARCSIN i : " << arcsin(i) << " (" << typeid(arcsin(i)).name() << ")" << endl;
    }
    catch(const CalculatorException& e){
        cout << e.what() << endl;
    }
    try{
        cout << "ARCSIN j : " << arcsin(j) << " (" << typeid(arcsin(j)).name() << ")" << endl;
    }
    catch(const CalculatorException& e){
        cout << e.what() << endl;
    }
    cout << "--------------------------------" << endl;
    cout << "COS i : " << cos(i) << " (" << typeid(cos(i)).name() << ")" << endl;
    cout << "COS j : " << cos(j) << " (" << typeid(cos(j)).name() << ")" << endl;
    try{
        cout << "ARCCOS i : " << arccos(i) << " (" << typeid(arccos(i)).name() << ")" << endl;
    }
    catch(const CalculatorException& e){
        cout << e.what() << endl;
    }
    try{
        cout << "ARCCOS j : " << arccos(j) << " (" << typeid(arccos(j)).name() << ")" << endl;
    }
    catch(const CalculatorException& e){
        cout << e.what() << endl;
    }
    cout << "--------------------------------" << endl;
    cout << "TAN i : " << tan(i) << " (" << typeid(tan(i)).name() << ")" << endl;
    cout << "TAN j : " << tan(j) << " (" << typeid(tan(j)).name() << ")" << endl;
    try{
     cout << "ARCTAN i : " << arctan(i) << " (" << typeid(arctan(i)).name() << ")" << endl;
    }
    catch(const CalculatorException& e){
        cout << e.what() << endl;
    }
    try{
    cout << "ARCTAN j : " << arctan(j) << " (" << typeid(arctan(j)).name() << ")" << endl;
    }
    catch(const CalculatorException& e){
        cout << e.what() << endl;
    }
    cout << "--------------------------------" << endl;
    cout << "SQRT i : " << sqrt(i) << " (" << typeid(sqrt(i)).name() << ")" << endl;
    cout << "SQRT j : " << sqrt(j) << " (" << typeid(sqrt(j)).name() << ")" << endl;
    try{
        cout << "SQRT -i : " << sqrt(-i) << " (" << typeid(sqrt(-i)).name() << ")" << endl;
    }
    catch(const CalculatorException& e){
        cout << e.what() << endl;
    }
    try{
        cout << "SQRT -j : " << sqrt(-j) << " (" << typeid(sqrt(-j)).name() << ")" << endl;
    }
    catch(const CalculatorException& e){
        cout << e.what() << endl;
    }
    cout << "--------------------------------" << endl;
    cout << "EXP i : " << exp(i) << " (" << typeid(exp(i)).name() << ")" << endl;
    cout << "EXP j : " << exp(j) << " (" << typeid(exp(j)).name() << ")" << endl;
    cout << "EXP -i : " << exp(-i) << " (" << typeid(exp(-i)).name() << ")" << endl;
    cout << "EXP -j : " << exp(-j) << " (" << typeid(exp(-j)).name() << ")" << endl;
    cout << "--------------------------------" << endl;
    cout << "LN i : " << ln(i) << " (" << typeid(ln(i)).name() << ")" << endl;
    cout << "LN j : " << ln(j) << " (" << typeid(ln(j)).name() << ")" << endl;
    try{
        cout << "LN -i : " << ln(-i) << " (" << typeid(ln(-i)).name() << ")" << endl;
    }
    catch(const CalculatorException& e){
        cout << e.what() << endl;
    }
    try{
        cout << "LN -j : " << ln(-j) << " (" << typeid(ln(-j)).name() << ")" << endl;
    }
    catch(const CalculatorException& e){
        cout << e.what() << endl;
    }
    cout << "--------------------------------" << endl;
    cout << "NUM i : " << num(i) << " (" << typeid(num(i)).name() << ")" << endl;
    try{
        cout << "NUM j : " << num(j) << " (" << typeid(num(j)).name() << ")" << endl;
    }
    catch(const CalculatorException& e){
        cout << e.what() << endl;
    }
    cout << "--------------------------------" << endl;
    cout << "DEN i : " << den(i) << " (" << typeid(den(i)).name() << ")" << endl;
    try{
        cout << "DEN j : " << den(j) << " (" << typeid(den(j)).name() << ")" << endl;
    }
    catch(const CalculatorException& e){
        cout << e.what() << endl;
    }
    cout << "--------------------------------" << endl;

    return 0;
}
