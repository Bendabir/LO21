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
    void clear(){literals.clear();}

    Literal& operator[](int i);
    const Literal& operator[](int i) const;

    // On réimplémente un itérateur
    class iterator {
        typename QStack<Literal*>::iterator current;

    public:
        iterator(typename QStack<Literal*>::iterator c) : current(c) {}
        iterator() : current() {}
        Literal& operator*() const {return **current;}
        iterator& operator++() {current++; return *this;}
        iterator operator++(int) {iterator tmp = *this; current++; return tmp;}
        iterator& operator--() {current--; return *this;}
        iterator operator--(int) {iterator tmp = *this; current--; return tmp;}
        bool operator==(const iterator& it) const {return current == it.current;}
        bool operator!=(const iterator& it) const {return current != it.current;}
    };
    iterator begin() {return iterator(literals.begin());}
    iterator end() {return iterator(literals.end());}

    class const_iterator {
        typename QStack<Literal*>::const_iterator current;

    public:
        const_iterator(typename QStack<Literal*>::const_iterator c) : current(c) {}
        const_iterator() : current() {}
        Literal& operator*() const {return **current;}
        const_iterator& operator++() {current++; return *this;}
        const_iterator operator++(int) {const_iterator tmp = *this; current++; return tmp;}
        const_iterator& operator--() {current--; return *this;}
        const_iterator operator--(int) {const_iterator tmp = *this; current--; return tmp;}
        bool operator==(const const_iterator& it) const {return current == it.current;}
        bool operator!=(const const_iterator& it) const {return current != it.current;}
    };
    const_iterator cbegin() const {return const_iterator(literals.cbegin());}
    const_iterator cend() const {return const_iterator(literals.cend());}

    class reverse_iterator {
        typename QStack<Literal*>::iterator current;

    public:
        reverse_iterator(typename QStack<Literal*>::iterator c) : current(c) {}
        reverse_iterator() : current() {}
        Literal& operator*() const {return **current;}
        reverse_iterator& operator++() {current--; return *this;}
        reverse_iterator operator++(int) {reverse_iterator tmp = *this; current--; return tmp;}
        bool operator==(const reverse_iterator& it) const {return current == it.current;}
        bool operator!=(const reverse_iterator& it) const {return current != it.current;}
    };
    reverse_iterator rbegin() {QStack<Literal*>::iterator end = literals.end(); return reverse_iterator(--end);}
    reverse_iterator rend() {QStack<Literal*>::iterator begin = literals.begin(); return reverse_iterator(--begin);}
};

ostream& operator<<(ostream& f, const Stack& s);

#endif // STACK_H
