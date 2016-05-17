#ifndef DIGITAL_LITERAL_H
#define DIGITAL_LITERAL_H

#include "literal.h"

class DigitalLiteral : public Literal {
public:
	DigitalLiteral(){};
	virtual ~DigitalLiteral(){};

	virtual void neg() = 0;
	virtual const string& toString() const = 0;
};


#endif // DIGITAL_LITERAL_H