#include <QDebug>

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
    try {
        literals.append(new ExpressionLiteral(this, expression)); // On extrait la chaine expression
        return *literals.last();
    }
    catch(const CalculatorException& e){
        throw e;
    }
}

Literal& LiteralFactory::addLiteral(const QString& atom, Literal* target){
    try {
        literals.append(new AtomLiteral(this, atom, target));
        return *literals.last();
    }
    catch(const CalculatorException& e){
        throw e;
    }
}

void LiteralFactory::removeLiteral(Literal& l){
    if(literals.removeAll(&l) == 0)
        throw CalculatorException("Erreur : L'élément à supprimer n'existe pas.");
}

Literal& LiteralFactory::addLiteralFromString(const QString& exp){
    // Si on a une expression
    if(exp[0] == '\'' && exp[exp.length() - 1] == '\''){
        QString expression = exp;
        return addLiteral(expression.replace("'", ""));
    }
    // Sinon, on regarde si c'est un entier
    else if(isNumber(exp)){
        return addLiteral(exp.toDouble());
    }
    // Sinon, si c'est un rationnel
    else if(isRational(exp)){
        QStringList parts = exp.split("/");
        double num = parts[0].toDouble(),
               den = parts[1].toDouble();

        return addLiteral(Number(num, den));
    }
    else if(isComplex(exp)){
        QStringList parts = exp.split("$");

        try{
            ComplexLiteral& re = dynamic_cast<ComplexLiteral&>(addLiteralFromString(parts[0]));
            ComplexLiteral& im = dynamic_cast<ComplexLiteral&>(addLiteralFromString(parts[1]));

            Literal& result = addLiteral(re.getReal(), im.getReal());

            removeLiteral(re);
            removeLiteral(im);

            return result;
        }
        catch(const CalculatorException& e){
            throw e;
        }
    }
    else
        throw CalculatorException("Erreur : Impossibler de générer une littérale à partir de la chaine \"" + exp + "\".");
}

Literal& LiteralFactory::findLiteral(const QString& literal){
    for(LiteralFactory::iterator l = begin(); l != end(); ++l)
        if((*l).toString() == literal)
            return *l;

    throw CalculatorException("Erreur : Impossible de trouver la littérale " + literal + " .");
}

bool LiteralFactory::existsAtom(const QString& atom) const {
    // On vérifie que l'atome existe
    // On va vérifier que ce nom n'existe pas déjà
    // A voir pour implémenter la vérification en tant que méthode

    for(int i = 0; i < literals.size(); i++){
        // Si on a un atom, on convertit et on check
        const Literal& literal = *literals[i];

        if(literal.isAtom()){
            const AtomLiteral& atomLiteral = dynamic_cast<const AtomLiteral&>(literal);

            // On renvoie vrai si le nom est déjà pris
            if(atom == atomLiteral.atom)
                return true;
        }
    }

    return false;
}
