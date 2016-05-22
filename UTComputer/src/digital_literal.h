#ifndef DIGITAL_LITERAL_H
#define DIGITAL_LITERAL_H

#include "literal.h"

/*!
 * \brief The DigitalLiteral class
 */

class DigitalLiteral : public Literal {
public:
    // Constructeurs/Destructeur
    // On conserve la conversion implicite de double vers DigitalLiteral
    DigitalLiteral(){}
    // Constructeur de recopie par défaut
    // Opérateur d'affectation par défaut
    virtual ~DigitalLiteral(){}
};

#endif // DIGITAL_LITERAL_H
