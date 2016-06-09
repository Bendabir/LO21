#ifndef MEMENTO_H
#define MEMENTO_H

#include "stack.h"

/*!
 * \brief Permet de sauvegarder l'état de la pile
 */
class Memento {
    friend class Stack;

private:
    QStack<Literal*> state;

public:
    /*!
     * \brief Constructeur
     * \param l : Pile à sauvegarder
     */
    Memento(const QStack <Literal*>& l) : state(l){}
};


#endif // MEMENTO_H
