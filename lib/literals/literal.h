#ifndef LITERAL_H
#define LITERAL_H

#include "../operand.h"

class Literal : public Operand {
public:
	Literal(){};
	virtual ~Literal(){};

	virtual const string& toString() const = 0;
};

#endif // LITERAL_H