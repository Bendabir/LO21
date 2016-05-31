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
    Literal& addLiteral(const QString& atom, Literal* target);
    /*!
     * \brief Permet de supprimer une littérale passée en argument. Provoque une erreur si la littérale à supprimer n'existait pas.
     * \param Référence sur la littérale à supprimer.
     */
    void removeLiteral(Literal& l);

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
};

#endif // LITERALFACTORY_H
