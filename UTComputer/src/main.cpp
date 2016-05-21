#include <cmath>

#include "exceptions.h"
#include "literal.h"
#include "digital_literal.h"

using namespace std;

int main(){
    DigitalLiteral l1 = 2.3,
                   l2 = 3,
                   l3 = 0;

    cout << "l1 = " << l1 << endl;
    cout << "l2 = " << l2 << endl;
    cout << "l3 = " << l3 << endl << endl;

    return 0;
}
