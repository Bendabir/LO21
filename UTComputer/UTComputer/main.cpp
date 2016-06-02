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

//    LiteralFactory fact;
//    Literal& z = fact.addLiteral(1, -1);
//    Literal& i = fact.addLiteral(2);
//    Literal& u = fact.addLiteral(3);
//    Literal& exp1 = fact.addLiteral("1 + 2");
//    Literal& exp2 = fact.addLiteral("1 * 2");

//    Stack stack;

//    cout << stack;

//    stack.push(z);
//    stack.push(i);
//    stack.push(u);

//    cout << stack;

//    root.getStack().push(z);
//    root.getStack().push(i);
//    root.getStack().push(u);
//    root.getStack().push(exp1);
//    root.getStack().push(exp2);

    return app.exec();
//    return 0;
}
