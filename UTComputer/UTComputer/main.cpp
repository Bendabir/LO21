#include <QApplication>
#include <QDebug>
#include <QList>

#include "complex_literal.h"
#include "expression_literal.h"
#include "atom_literal.h"
#include "calculator.h"
#include "mainwindow.h"

int main(int argc, char* argv[]){
    // Démarrage de l'application
    QApplication app(argc, argv);
    MainWindow root;
    root.show();

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

    AtomLiteral& x1 = dynamic_cast<AtomLiteral&>(fact.addLiteral("X1", &u));
    AtomLiteral& x2 = dynamic_cast<AtomLiteral&>(fact.addLiteral("X2", &x1));

    cout << x1.getTarget() << endl;
    cout << x2.getTarget() << endl;
    cout << x2.getTarget(false) << endl;

//    Stack stack;
//    stack.push(i);

//    cout << stack[0] << endl;
//    try{
//        cout << stack[1] << endl;
//    }
//    catch(const CalculatorException& e){
//        cout << e;
//    }

    Calculator& calc = Calculator::start();
    calc.getStack().push(i);

    return app.exec();
}
