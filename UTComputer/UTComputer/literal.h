#ifndef LITERAL_H
#define LITERAL_H

#include <cmath>

#include <QString>
#include <QStringList>
#include <QStack>
#include <QMap>

#include "calculator_exception.h"
#include "literal_factory.h"

class LiteralFactory;

/*!
 * \brief La classe Literal est la classe de base de toutes les littérales de l'application (littérales entières, réelles, rationnelles, complexes, programmes, expression).
 */
class Literal {
protected:
    /*!
     * \brief Pointeur sur la factory qui a créé la littérale. Permet de créer des littérales à la volée pendant les opérations et de s'affranchir d'un code trop lourd via des retours par référence.
     */
    LiteralFactory* manager;

public:
    /*!
     * \brief Constructeur de Literal
     * \param Pointeur sur la factory qui a créé la littérale.
     */
    Literal(LiteralFactory* m) : manager(m){}
    virtual ~Literal(){}

    /*!
     * \brief Accesseur pour la factory ayant créé la littérale.
     * \return Référence sur la factory.
     */
    LiteralFactory& getManager(){return *manager;}

    // Pour savoir ce que l'on traite
    /*!
     * \brief Permet de savoir si la Literal traitée est un entier.
     * \return Vrai si c'est un entier, faux sinon
     */
    virtual bool isInteger() const = 0;
    /*!
     * \brief Permet de savoir si la Literal traitée est un réel.
     * \return Vrai si c'est un réel, faux sinon
     */
    virtual bool isReal() const = 0;
    /*!
     * \brief Permet de savoir si la Literal traitée est un rationnel.
     * \return Vrai si c'est un rationnel, faux sinon
     */
    virtual bool isRational() const = 0;
    /*!
     * \brief Permet de savoir si la Literal traitée est un complexe.
     * \return Vrai si c'est un complexe, faux sinon
     */
    virtual bool isComplex() const = 0;
    /*!
     * \brief Permet de savoir si la Literal traitée est une expression littérale.
     * \return Vrai si c'est une expression littérale, faux sinon
     */
    virtual bool isExpression() const = 0;
    /*!
     * \brief Permet de savoir si la Literal traitée est un programme littéral.
     * \return Vrai si c'est un programme littéral, faux sinon
     */
    virtual bool isProgramm() const = 0;
    /*!
     * \brief Permet de savoir si la Literal traitée est une littérale atome.
     * \return Vrai si c'est une littérale atome, faux sinon
     */
    virtual bool isAtom() const = 0;
    /*!
     * \brief Permet de savoir si la Literal traitée est une littérale entière, réelle ou rationnelle.
     * \return Vrai si c'est une littérale entière, réelle ou rationnelle; faux sinon
     */
    bool isNumber() const;

    // Opérateurs numériques
    /*!
     * \brief Gère l'addition de deux littérales.
     * \param l : Littérale à additionner avec la littérale implicite (celle sur laquelle s'applique la méthode)
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas.
     */
    virtual Literal& operator+(const Literal& l) const = 0;
    /*!
     * \brief Gère la soustraction de deux littérales.
     * \param l : Littérale à soustraire avec la littérale implicite (celle sur laquelle s'applique la méthode)
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas.
     */
    virtual Literal& operator-(const Literal& l) const = 0;
    /*!
     * \brief Gère la multiplication de deux littérales.
     * \param l : Littérale à multiplier avec la littérale implicite (celle sur laquelle s'applique la méthode)
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas.
     */
    virtual Literal& operator*(const Literal& l) const = 0;
    /*!
     * \brief Gère la division de deux littérales.
     * \param l : Littérale à diviser avec la littérale implicite (celle sur laquelle s'applique la méthode)
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas.
     */
    virtual Literal& operator/(const Literal& l) const = 0;

    /*!
     * \brief Renvoie la division euclidienne de deux entiers. Provoque une erreur sur les réels, les complexes et les rationnels. Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \param Référence sur la littérale.
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas.
     */
    virtual Literal& div(const Literal& l) const = 0;
    /*!
     * \brief Renvoie le reste de la division euclidienne de deux entiers. Provoque une erreur sur les réels, les complexes et les rationnels. Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \param Référence sur la littérale.
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas.
     */
    virtual Literal& mod(const Literal& l) const = 0;
    /*!
     * \brief Renvoie la littérale à la puissance passée en argument. Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \param Référence sur la littérale.
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas.
     */
    virtual Literal& pow(const Literal& l) const = 0;
    /*!
     * \brief Renvoie l'opposée de la littérale sur laquelle s'applique l'opérateur. Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas.
     */
    virtual Literal& operator-() const = 0;
    /*!
     * \brief Renvoie le numérateur de la littérale sur laquelle s'applique l'opérateur. Provoque une erreur sur les réels et les complexes. Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas.
     */
    virtual Literal& num() const = 0;
    /*!
     * \brief Renvoie le dénominateur de la littérale sur laquelle s'applique l'opérateur. Provoque une erreur sur les réels et les complexes. Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas.
     */
    virtual Literal& den() const = 0;
    /*!
     * \brief Renvoie le sinus de la littérale sur laquelle s'applique l'opérateur (littérale réelle). Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas (réel, expression ou programme).
     */
    virtual Literal& sin() const = 0;
    /*!
     * \brief Renvoie l'arcsinus de la littérale sur laquelle s'applique l'opérateur (littérale réelle). Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \brief Provoque une erreur si la littérale est en dehors de l'intervale réel [-1; 1]
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas (réel, expression ou programme).
     */
    virtual Literal& arcsin() const = 0;
    /*!
     * \brief Renvoie le cosinus de la littérale sur laquelle s'applique l'opérateur (littérale réelle). Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas (réel, expression ou programme).
     */
    virtual Literal& cos() const = 0;
    /*!
     * \brief Renvoie l'arccos de la littérale sur laquelle s'applique l'opérateur (littérale réelle). Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \brief Provoque une erreur si la littérale est en dehors de l'intervale réel [-1; 1]
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas (réel, expression ou programme).
     */
    virtual Literal& arccos() const = 0;
    /*!
     * \brief Renvoie la tangente de la littérale sur laquelle s'applique l'opérateur (littérale réelle). Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas (réel, expression ou programme).
     */
    virtual Literal& tan() const = 0;
    /*!
     * \brief Renvoie l'arctan de la littérale sur laquelle s'applique l'opérateur (littérale réelle). Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas (réel, expression ou programme).
     */
    virtual Literal& arctan() const = 0;
    /*!
     * \brief Renvoie la racine carrée de la littérale sur laquelle s'applique l'opérateur (littérale réelle). Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \brief Provoque une erreur si la littérale n'est pas réelle et inférieure à 0;
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas (réel, expression ou programme).
     */
    virtual Literal& sqrt() const = 0;
    /*!
     * \brief Renvoie le logarithme népérien de la littérale sur laquelle s'applique l'opérateur (littérale réelle). Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \brief Provoque une erreur si la littérale n'est pas réelle et inférieure à 0;
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas (réel, expression ou programme).
     */
    virtual Literal& ln() const = 0;
    /*!
     * \brief Renvoie l'exponentielle de la littérale sur laquelle s'applique l'opérateur (littérale réelle). Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas (réel, expression ou programme).
     */
    virtual Literal& exp() const = 0;
    /*!
     * \brief Renvoie la partie réelle de la littérale sur laquelle s'applique l'opérateur (littérale complexe). Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \brief Renvoie la littérale inchangée s'il s'agit d'une littérale réelle, entière ou rationnelle.
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas (réel, expression ou programme).
     */
    virtual Literal& re() const = 0;
    /*!
     * \brief Renvoie la partie imaginaire de la littérale sur laquelle s'applique l'opérateur (littérale complexe). Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \brief Renvoie la littérale entière 0 s'il s'agit d'une littérale réelle, entière ou rationnelle.
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas (réel, expression ou programme).
     */
    virtual Literal& im() const = 0;
    /*!
     * \brief Renvoie l'argument de la littérale sur laquelle s'applique l'opérateur (littérale complexe). Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \brief Peut s'appliquer sur les réels, entiers et rationnels également.
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas (réel, expression ou programme).
     */
    virtual Literal& arg() const = 0;
    /*!
     * \brief Renvoie le module de la littérale sur laquelle s'applique l'opérateur (littérale complexe). Renvoie un nouveau programme ou expression sur lequel s'applique cet opérateur.
     * \brief Peut s'appliquer sur les réels, entiers et rationnels également.
     * \return Pointeur sur une littérale (étant une sous-classe de Literal), selon les cas (réel, expression ou programme).
     */
    virtual Literal& norm() const = 0;

    // Opérateurs logiques
    /*!
     * \brief Compare deux littérales entre elles. Egalité selon les cas.
     * \param Une autre littérale.
     * \return Booléen (vrai si les littérales sont jugées égales, faux sinon)
     */
    virtual bool operator==(const Literal& l) const = 0;
    /*!
     * \brief Compare deux littérales entre elles. Inégalité selon les cas.
     * \param l : Une autre littérale.
     * \return Booléen (vrai si les littérales sont jugées inégales, faux sinon)
     */
    virtual bool operator!=(const Literal& l) const = 0;
    /*!
     * \brief Compare deux littérales entre elles. Supériorité ou égalité selon les cas.
     * \param l : Une autre littérale.
     * \return Booléen (vrai si la littérale passée en argument est jugée inférieure ou égale à l'autre, faux sinon)
     */
    virtual bool operator>=(const Literal& l) const = 0;
    /*!
     * \brief Compare deux littérales entre elles. Supériorité selon les cas.
     * \param l : Une autre littérale.
     * \return Booléen (vrai si la littérale passée en argument est jugée inférieure à l'autre, faux sinon)
     */
    virtual bool operator>(const Literal& l) const = 0;
    /*!
     * \brief Compare deux littérales entre elles. Infériorité ou égalité selon les cas.
     * \param l : Une autre littérale.
     * \return Booléen (vrai si la littérale passée en argument est jugée supérieure ou égale à l'autre, faux sinon)
     */
    virtual bool operator<=(const Literal& l) const = 0;
    /*!
     * \brief Compare deux littérales entre elles. Infériorité selon les cas.
     * \param l : Une autre littérale.
     * \return Booléen (vrai si la littérale passée en argument est jugée inférieure à l'autre, faux sinon)
     */
    virtual bool operator<(const Literal& l) const = 0;
    /*!
     * \brief Compare la valeur de deux littérales (0 vaut faux, tout autre valeur vaut vrai).
     * \param l : Une autre littérale.
     * \return Booléen (vrai si les deux littérales sont jugées vraies, faux sinon)
     */
    virtual bool operator&&(const Literal& l) const = 0;
    /*!
     * \brief Compare la valeur de deux littérales (0 vaut faux, tout autre valeur vaut vrai).
     * \param l : Une autre littérale.
     * \return Booléen (vrai si au moins une des deux littérales est jugée vraie, faux sinon)
     */
    virtual bool operator||(const Literal& l) const = 0;
    /*!
     * \brief Renvoie le booléen opposé correspondant à la littérale sur laquelle s'applique l'opérateur
     * \return Booléen (vrai si la littérale était jugée "fausse", faux sinon)
     */
    virtual bool operator!() const = 0;

    /*!
     * \brief Convertit la littérale en chaine de caractères (QString).
     * \return Chaine de caractères convertit.
     */
    virtual QString toString() const = 0;
    /*!
     * \brief Opérateur d'indirection surchargé pour renvoyer la littérale sous forme de chaine de caractères.
     * \brief Si cette littérale est une expression, cela renvoie une chaine de caractères correspondant à l'expression évaluée.
     * \brief Si cette littérale est un atome, cela renvoie une chaine de caractères correspondant à l'expression pointée.
     * \return Chaine de caractère
     */
    virtual QString operator*() const;
};

/*!
 * \brief Surchage de flux ostream pour utiliser les QString facilement. Utile pour le debug, en plus de QDebug.
 * \param Flux
 * \param Chaine de caractère Qt
 * \return Le flux modifié
 */
ostream& operator<<(ostream& f, const QString& str);

/*!
 * \brief Permet d'afficher une littérale dans un flux ostream. Réalise un hook depuis Literal::toString().
 * \param f : Le flux ciblé
 * \param l : La littérale à afficher
 * \return Le flux ciblé
 */
ostream& operator<<(ostream& f, const Literal& l);

/*!
 * \brief Permet de vérifier si une chaine de caractères est un nombre (réel, entier ou complexe). Un rationnel est considéré comme une disivion d'entiers.
 * \param Nombre à vérifier
 * \return Vrai si c'est un nombre, faux sinon
 */
bool isNumber(const QString& str);
/*!
 * \brief Permet de vérifier si une chaine de caractères est une fonction.
 * \param Fonction à vérifier
 * \return Vrai si c'est une fonction, faux sinon
 */
bool isFunction(const QString& str);
/*!
 * \brief Permet de vérifier si une chaine de caractères est un opérateur.
 * \param Opérateur à vérifier
 * \return Vrai si c'est un opérateur, faux sinon
 */
bool isOperator(const QString& str);
/*!
 * \brief Permet de vérifier si une chaine de caractères est une variable.
 * \param Variable à vérifier
 * \return Vrai si c'est une variable, faux sinon
 */
bool isVariable(const QString& str);
/*!
 * \brief Permet de connaitre la priorité d'un opérateur. Ne fait pas de vérification sur la validité de l'opérateur.
 * \param Opérateur dont l'on souhaite connaitre la priorité
 * \return Priorité de l'opérateur
 */
int getPriority(const QString& o);

#endif // LITERAL_H
