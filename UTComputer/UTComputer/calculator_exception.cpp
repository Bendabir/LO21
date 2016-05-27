#include "calculator_exception.h"

ostream& operator<<(ostream& f, const CalculatorException& e){
    f << e.what() << endl;
    return f;
}
