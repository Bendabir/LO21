#ifndef MEMENTO_H
#define MEMENTO_H

#include "stack.h"

class Memento {
    friend class Stack;

private:
    QStack<Literal*> state;

public:
    Memento(const QStack <Literal*>& l) : state(l){}
};


#endif // MEMENTO_H
