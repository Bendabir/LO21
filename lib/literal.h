#ifndef LITERAL_H
#define LITERAL_H

#include <iostream>
#include <string>

#include "operand.h"

using namespace std;

class Literal : public Operand {

public:
	Literal(){}
	virtual ~Literal(){}

	virtual string toString() const = 0;
};

#endif // LITERAL_H