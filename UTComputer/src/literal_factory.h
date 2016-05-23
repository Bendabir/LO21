#ifndef LITERALFACTORY_H
#define LITERALFACTORY_H

#include <QList>

#include "literal.h"
#include "digital_literal.h"
#include "rational_literal.h"
#include "number_literal.h"

// Idéalement, il faudrait passer pas mal de membres originel en privé pour éviter de se retrouver avec une foule de méthodes
class LiteralFactory : public QList<Literal*> {
public:
    LiteralFactory() : QList<Literal*>(){}

    Literal& addLiteral(const Literal& l); // Duplication
    Literal& addLiteral(int num, int den = 1); // Entier ou rationnel
    Literal& addLiteral(double n); // Réel
    Literal& addLiteral(const DigitalLiteral& re, const DigitalLiteral& im); // Complexe
    void removeLiteral(Literal& l);
};

std::ostream& operator<<(std::ostream& f, const LiteralFactory& m);

#endif // LITERALFACTORY_H
