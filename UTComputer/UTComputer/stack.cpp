#include "stack.h"
#include "memento.h"

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

const Literal& Stack::operator[](int i) const {
    if(!empty() && i < size())
        return *literals[i];
    else
        throw CalculatorException("Erreur : Impossible de retourner l'élément " + QString::number(i) + ".");
}

ostream& operator<<(ostream& f, const Stack& s){
    if(s.empty())
        f << "La pile de calcul est vide." << endl;
    else
        for(int i = 0; i < s.size(); i++)
            f << s.size() - i << " : " << s[i] << endl;

    return f;
}

Memento* Stack::createMemento(){
    return new Memento(literals);
}

void Stack::restoreMemento(Memento* mem, LiteralFactory& f){
    // Lors de la restauration, on redéclare les litérales dans la factory
    // Sinon, elles sont encore affichées mais sans être référencées dans le manager
    literals.clear();
    for(int i = 0; i < mem->state.size(); i++)
        literals.push(&f.addLiteralFromString(mem->state[i]->toString()));
}
