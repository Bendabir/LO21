#ifndef NUMBER_LITERAL_H
#define NUMBER_LITERAL_H

#include "digital_literal.h"


// Par défaut, c'est de l'entier
template<class T = int>
class LiteralNumber : public DigitalLiteral {
private:
	T value;

public:
	// On autorise les conversions implicites
	LiteralNumber(T v = 0) : value(v){}

	const T& getValue() const {return value;}

	void neg() {value = -value;}
	const string& toString() const;
};

#endif // NUMBER_LITERAL_H