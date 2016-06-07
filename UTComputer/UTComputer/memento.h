#ifndef MEMENTO_H
#define MEMENTO_H

#include "stack.h"

class Memento {
private:
    friend class Stack;
    QStack<Literal*> state;
public:
    Memento(QStack <Literal*> l){
        state = l;
    }
};


#endif // MEMENTO_H
