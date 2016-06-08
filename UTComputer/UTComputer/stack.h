#ifndef STACK_H
#define STACK_H

#include <QStack>

#include "literal.h"

class Memento;
class Calculator;

/*!
 * \brief La classe Stack est la pile de calcul de la calculatrice.
 */
class Stack {
    friend class Calculator; // ???

private:
    QStack<Literal*> literals;

public:
    Stack();
    Stack(const Stack& s);
    Stack& operator=(const Stack& s);

    // On réimplémente les fonctions utiles
    /*!
     * \brief Adatapteur de la fonction top() de QStack<Literal*>
     * \return Litérale au sommet de la pile
     */
    Literal& top();
    /*!
     * \brief Adatapteur de la fonction top() de QStack<Literal*> dans sa version const.
     * \return Litérale au sommet de la pile
     */
    const Literal& top() const;
    /*!
     * \brief Adatapteur de la fonction push() de QStack<Literal*>
     * \param l : Litérale à empiler
     */
    void push(Literal& l){literals.push(&l);}
    /*!
     * \brief Adatapteur de la fonction pop() de QStack<Literal*>
     * \return Litérale dépilée
     */
    Literal& pop();
    /*!
     * \brief Adatapteur de la fonction empty() de QStack<Literal*>
     * \return Vrai si la pile est vide, faux sinon
     */
    bool empty() const {return literals.empty();}
    /*!
     * \brief Adatapteur de la fonction size() de QStack<Literal*>
     * \return Taille de la pile de calcul
     */
    int size() const {return literals.size();}
    /*!
     * \brief Adatapteur de la fonction clear() de QStack<Literal*>
     */
    void clear(){literals.clear();}
    /*!
     * \brief Adatapteur de la fonction contains() de QStack<Literal*>
     * \param l : Litérale à retrouver dans la pile
     * \return Vrai si la litérale a été trouvée, faux sinon
     */
    bool contains(Literal& l) const {return literals.contains(&l);}

    /*!
     * \brief Adatapteur de l'opérateur [] de QStack<Literal*>
     * \param i : Index de la litérale à accéder
     * \return Litérale située à l'index i
     */
    Literal& operator[](int i);
    /*!
     * \brief Adatapteur de l'opérateur [] de QStack<Literal*> dans sa version const.
     * \param i : Index de la litérale à accéder
     * \return Litérale située à l'index i
     */
    const Literal& operator[](int i) const;

    //pour le memento
    /*!
     * \brief stackMemento permet de creer un memento de la pile
     * \return renvoi une QStack de literal* avec:  new Memento(literals)
     */
    Memento * stackMemento();
    /*!
     * \brief restoreMemento permet de charger l'attribut literal de la stack avec le memento stocké en mémoire
     * \param mem
     */
    void restoreMemento (Memento* mem);

    // On réimplémente un itérateur
    /*!
     * \brief Adaptateur de la classe iterator de QStack<Literal*> pour plus de facilité d'utilisation.
     */
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
    /*!
     * \brief Renvoie un iterator qui correspond à la première litérale de la pile.
     * \return iterator
     */
    iterator begin() {return iterator(literals.begin());}
    /*!
     * \brief Renvoie un iterator qui correspond à la dernière litérale de la pile.
     * \return iterator
     */
    iterator end() {return iterator(literals.end());}

    /*!
     * \brief Adaptateur de la classe const_iterator de QStack<Literal*> pour plus de facilité d'utilisation.
     */
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
    /*!
     * \brief Renvoie un const_iterator qui correspond à la première litérale de la pile.
     * \return iterator
     */
    const_iterator cbegin() const {return const_iterator(literals.cbegin());}
    /*!
     * \brief Renvoie un const_iterator qui correspond à la première litérale de la pile.
     * \return iterator
     */
    const_iterator cend() const {return const_iterator(literals.cend());}

    /*!
     * \brief Implémentation d'un reverse_iterator pour plus de facilité d'utilisation.
     */
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
    /*!
     * \brief Renvoie un reverse_iterator qui correspond à la dernière litérale de la pile.
     * \return iterator
     */
    reverse_iterator rbegin() {QStack<Literal*>::iterator end = literals.end(); return reverse_iterator(--end);}
    /*!
     * \brief Renvoie un reverse_iterator qui correspond à la première litérale de la pile.
     * \return iterator
     */
    reverse_iterator rend() {QStack<Literal*>::iterator begin = literals.begin(); return reverse_iterator(--begin);}
};

/*!
 * \brief Surchage d'un flux ostream pour afficher tout le contenu de la pile de calcul.
 * \param f : Flux à remplir
 * \param s : Pile de calcul à afficher
 * \return Flux modifié
 */
ostream& operator<<(ostream& f, const Stack& s);



#endif // STACK_H
