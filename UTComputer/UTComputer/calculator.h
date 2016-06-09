#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "stack.h"
#include "settings.h"

#define HISTORY_SIZE 20

/*!
 * \brief La classe Calculator est la classe principale de l'application. C'est elle qui gère les calculs.
 * \brief Elle compose la pile, le manager des littérales ainsi que les options de l'application.
 */
class Calculator {
protected:
    Stack* stack;
    Settings* settings;
    LiteralFactory factory;

    // Permet de stocker la pile à chaque changement
    Memento* mementoList[HISTORY_SIZE];

    //les indices de ce tableaux
    int mementoIndex;
    int topIndex;

    QString lastop;
    QVector<Literal*> lastargs;

private:
    // On empêche la recopie et l'affectation
    Calculator(const Calculator& c);
    Calculator& operator=(const Calculator& c);

    /*!
     * \brief Permet de nettoyer le tableau des derniers arguments utiliser (et de supprimer convenablement de la mémoire les littérales inutiles)
     */
    void cleanLastArgs(bool nokeep);


public:
    /*!
     * \brief Constructeur sans argument
     */
    Calculator(); // En privé si Singleton
    virtual ~Calculator(); // En privé si Singleton

    /*!
     * \brief Permet d'exécuter une commande ou une suite de commande à partir d'une chaine de caractères.
     * \param commantText : Commande à exécuter.
     */
    void command(const QString& commantText, bool keep = true);

    // Accesseurs
    /*!
     * \brief Accesseur sur la pile de calcul.
     * \return Référence sur la pile.
     */
    Stack& getStack() {return *stack;}

    //fonction undo() et redo()
    void undo();
    void redo();
};

/*!
 * \brief Permet de connaitre l'arité d'un opérateur et de dépiler le bon nombre de littérales
 * \param c : Opérateur dont l'ont souhaite connaitre l'arité.
 * \return Arité de l'opérateur (0 si opérateur inconnu).
 */
unsigned int getArity(const QString &c);

#endif // CALCULATOR_H
