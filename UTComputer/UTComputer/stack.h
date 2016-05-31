#ifndef STACK_H
#define STACK_H

#include <QStack>

#include "literal.h"

class Calculator;

/*!
 * \brief La classe Stack est la pile de calcul de la calculatrice.
 */
class Stack {
    friend class Calculator;

private:
    QStack<Literal*> literals;


public:
    Stack();
    Stack(const Stack& s);
    Stack& operator=(const Stack& s);

    // On réimplémente les fonctions utiles
    Literal& top();
    const Literal& top() const;
    void push(Literal& l){literals.push(&l);}
    Literal& pop();
    bool empty() const {return literals.empty();}
    int size() const {return literals.size();}

    Literal& operator[](int i);
    const Literal& operator[](int i) const;
};

ostream& operator<<(ostream& f, const Stack& s);

#endif // STACK_H
