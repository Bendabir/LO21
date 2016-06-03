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
    literals.append(new ExpressionLiteral(this, expression)); // On extrait la chaine expression
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

Literal& LiteralFactory::addLiteralFromString(const QString& exp){
    // On cherche à savoir ce que l'on traite
    if(*exp.begin() == '\'' && *exp.end() == '\''){
        QString expression = exp;
        return addLiteral(expression.replace("'", ""));
    }
//    else if(*exp.begin() == '[' && *exp.end() == ']'){

//    }
    else if(exp.indexOf("$") != -1){
        QStringList parts = exp.split("$");

        if(parts.length() > 2)
            throw CalculatorException("Erreur : Impossibler de générer une littérale à partir de la chaine \"" + exp + "\".");

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
    else if(exp.indexOf("$") == -1 && exp.indexOf("/") != -1){
        QStringList parts = exp.split("/");

        if(parts.length() > 2)
            throw CalculatorException("Erreur : Impossibler de générer une littérale à partir de la chaine \"" + exp + "\".");

        return addLiteral(Number(parts[0].toDouble(), parts[1].toDouble()));

    }
    else if(isNumber(exp)){
        return addLiteral(exp.toDouble());
    }
    else
        throw CalculatorException("Erreur : Impossibler de générer une littérale à partir de la chaine \"" + exp + "\".");
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
