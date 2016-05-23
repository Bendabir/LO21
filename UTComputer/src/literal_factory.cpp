#include "literal_factory.h"

Literal& LiteralFactory::addLiteral(const Literal& l){

}

// Entier ou rationnel
Literal& LiteralFactory::addLiteral(int num, int den){
    // Si l'on traite un entier
    if(den == 1 || den == 0)
        this->append(new IntegerLiteral(num));
    else
        this->append(new RationalLiteral(num, den));

    return *(this->last());
}

// Réel
Literal& LiteralFactory::addLiteral(double n){
    this->append(new RealLiteral(n));
    return *(this->last());
}

// Complexe
Literal& LiteralFactory::addLiteral(const DigitalLiteral& re, const DigitalLiteral& im){
    // Pas d'implémentation pour le moment
}

void LiteralFactory::removeLiteral(Literal& l){
    for(iterator it = begin(); it != end(); it++)
        if(*it == &l){
            this->removeOne(&l);
            return;
        }
    throw CalculatorException("Erreur : La littérale à supprimer n'existe pas.");
}

// On affiche le contenu du manager.
std::ostream& operator<<(std::ostream& f, const LiteralFactory& m){
    if(m.length() == 0)
        f << "Le manager est vide." << std::endl;

    for(LiteralFactory::const_iterator it = m.begin(); it != m.end(); it++)
        f << **it << " (" << typeid(**it).name() << ")" << std::endl;
    return f;
}

