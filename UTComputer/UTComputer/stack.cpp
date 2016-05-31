#include "stack.h"

Stack::Stack() : literals(QStack<Literal*>()){}

// On réimplémente les fonctions utiles
Literal& Stack::top(){
    if(!empty())
        return *literals.top();
    else
        throw CalculatorException("Erreur : La pile de calcul est vide.");
}

const Literal& Stack::top() const {
    if(!empty())
        return *literals.top();
    else
        throw CalculatorException("Erreur : La pile de calcul est vide.");
}

Literal& Stack::pop(){
    if(!empty())
        return *literals.pop();
    else
        throw CalculatorException("Erreur : Impossible de dépiler. La pile de calcul est vide.");
}

Literal& Stack::operator[](int i){
    if(!empty() && i < size())
        return *literals[i];
    else
        throw CalculatorException("Erreur : Impossible de retourner l'élément " + QString::number(i) + ".");
}
