#include "literal_factory.h"
#include "complex_literal.h"
#include "expression_literal.h"
#include "atom_literal.h"

LiteralFactory::LiteralFactory() : literals(QVector<Literal*>()){}

Literal& LiteralFactory::addLiteral(const Number& re, const Number& im){
    literals.append(new ComplexLiteral(this, re, im));
    return *literals.last();
}

Literal& LiteralFactory::addLiteral(const QString& expression){
    literals.append(new ExpressionLiteral(this, expression));
    return *literals.last();
}

Literal& LiteralFactory::addLiteral(const QString& atom, Literal* target){
    literals.append(new AtomLiteral(this, atom, target));
    return *literals.last();
}

void LiteralFactory::removeLiteral(Literal& l){
    if(literals.removeAll(&l) == 0)
        throw CalculatorException("Erreur : L'élément à supprimer n'existe pas.");
}

