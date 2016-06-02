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

    return app.exec();
}
