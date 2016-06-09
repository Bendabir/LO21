#ifndef LITERALFACTORY_H
#define LITERALFACTORY_H

#include <QVector>

#include "number.h"

class Literal;

/*!
 * \brief Permet de créer des littérales (quelconques) et les stocker.
 */
class LiteralFactory {
private:
    /*!
     * \brief Permet de stocker les littérales créées. On conserve toujours une référence sur ces variables en mémoire. Evite les fuites mémoires donc, même si ça grossit ;)
     */
    QVector<Literal*> literals;

public:
    LiteralFactory();

    /*!
     * \brief Ajoute une littérale complexe et la lie à la factory.
     * \param Partie réelle (Number)
     * \param Partie imaginaire (Number). Peut-être nulle, le complexe se comportera donc comme un nombre "réel".
     * \return Une référence sur la littérale créée.
     */
    Literal& addLiteral(const Number& re, const Number& im = 0);
    /*!
     * \brief Ajoute une littérale expression et la lie à la factory.
     * \param Chaine de caractère correspondant à l'expression à ajouter.
     * \return Une référence sur la littérale créée.
     */
    Literal& addLiteral(const QString& expression);
    /*!
     * \brief Permet d'ajouter une variable pointant sur une autre littérale.
     * \brief Provoque une erreur si le nom de variable correspond à un nom de fonction ou d'opérateur.
     * \brief Provoque une erreur si le nom de variable correspond à un nom de variable déjà utilisé.
     * \brief Provoque une erreur si le nom de variable n'est pas valide (suite de chiffre ou de lettres majuscules, commençant par une lettre majuscule).
     * \param atom : Nom de la variable
     * \param target : Pointeur sur la littérale à pointer
     * \return
     */
    Literal& addLiteral(const QString& atom, Literal* target);
    /*!
     * \brief Permet d'ajouter une litérale valant 0 ou 1 en fonction du booléen passé en paramètre
     * \param test : Booléen que l'on souhaite "convertir"
     * \return Litéral valant 1 si le booléen était vrai, 0 sinon
     */
    Literal& addBoolLiteral(bool test);
    /*!
     * \brief Permet de supprimer une littérale passée en argument. Provoque une erreur si la littérale à supprimer n'existait pas.
     * \param Référence sur la littérale à supprimer.
     */
    void removeLiteral(Literal& l);
    /*!
     * \brief Permet d'ajouter une litérale à partir de la forme qu'elle devrait avoir une fois la fonction toString() appliquée.
     * \brief Exemple : "1$2" permet de créer la litérale complexe 1$2
     * \brief Déclenche une erreur s'il est impossible de créer une littérale à partir de la chaine de caractères.
     * \param exp : Chaine de caractères à convertir en litérale
     * \return La litérale créée
     */
    Literal& addLiteralFromString(const QString& exp);
    /*!
     * \brief Permet de retrouver une litérale à partir de la valeur qu'elle devrait avoir une fois la fonction toString() appliquée.
     * \brief Déclenche une erreur si la littérale correspondante n'existe pas.
     * \param literal : Littérale sous forme de chaine de caractères.
     * \return Référence sur la littérale trouvée.
     */
    Literal& findLiteral(const QString& literal);

    /*!
     * \brief Renvoie le nombre de littérales créées (et toujours existantes) de la factory
     * \return Nombre de littérales
     */
    int size() const {return literals.size();}
    /*!
     * \brief Surchage de l'opérateur [] pour accéder directement à une littérale
     * \param Indice de la littérale
     * \return Référence sur la littérale ciblée
     */
    Literal& operator[](unsigned int i){return *literals[i];}
    /*!
     * \brief Détermine sur la factory est vide.
     * \return Vrai si la factory est vide, faux sinon
     */
    bool empty() const {return literals.empty();}

    /*!
     * \brief Permet de vérifier si un nom de variable (atome) est déjà utilisé.
     * \param Le nom de la variable à vérifier
     * \return Vrai si le nom est déjà pris, faux sinon
     */
    bool existsAtom(const QString& atom) const;
    /*!
     * \brief Permet de vérifier si une littérale existe.
     * \param Le nom de la littérale à vérifier
     * \return Vrai si la littérale existe, faux sinon
     */
    bool existsLiteral(const QString& l) const;
    void clear() {literals.clear();}
    bool isPointed(const Literal& l);

    /*!
     * \brief Adaptateur de la classe iterator de QVector<Literal*> pour plus de facilité d'utilisation.
     */
    class iterator {
        typename QVector<Literal*>::iterator current;

    public:
        iterator(typename QVector<Literal*>::iterator c) : current(c) {}
        iterator() : current() {}
        Literal& operator*() {return **current;}
        iterator& operator++() {current++; return *this;}
        iterator operator++(int) {iterator tmp = *this; current++; return tmp;}
        iterator& operator--() {current--; return *this;}
        iterator operator--(int) {iterator tmp = *this; current--; return tmp;}
        bool operator==(const iterator& it) const {return current == it.current;}
        bool operator!=(const iterator& it) const {return current != it.current;}
    };
    /*!
     * \brief Renvoie un iterator qui correspond à la première litérale du manager.
     * \return iterator
     */
    iterator begin() {return iterator(literals.begin());}
    /*!
     * \brief Renvoie un iterator qui correspond à la dernière litérale du manager.
     * \return iterator
     */
    iterator end() {return iterator(literals.end());}

    /*!
     * \brief Adaptateur de la classe const_iterator de QVector<Literal*> pour plus de facilité d'utilisation.
     */
    class const_iterator {
        typename QVector<Literal*>::const_iterator current;

    public:
        const_iterator(typename QVector<Literal*>::const_iterator c) : current(c) {}
        const_iterator() : current() {}
        const Literal& operator*() const {return **current;}
        const_iterator& operator++() {current++; return *this;}
        const_iterator operator++(int) {const_iterator tmp = *this; current++; return tmp;}
        const_iterator& operator--() {current--; return *this;}
        const_iterator operator--(int) {const_iterator tmp = *this; current--; return tmp;}
        bool operator==(const const_iterator& it) const {return current == it.current;}
        bool operator!=(const const_iterator& it) const {return current != it.current;}
    };
    /*!
     * \brief Renvoie un const_iterator qui correspond à la première litérale du manager.
     * \return iterator
     */
    const_iterator cbegin() const {return const_iterator(literals.cbegin());}
    /*!
     * \brief Renvoie un const_iterator qui correspond à la dernière litérale du manager.
     * \return iterator
     */
    const_iterator cend() const {return const_iterator(literals.cend());}
};

#endif // LITERALFACTORY_H
