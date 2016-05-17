#ifndef RATIONAL_LITERAL_H
#define RATIONAL_LITERAL_H

#include "digital_literal.h"
#include "number_literal.h"

class RationalLiteral : public DigitalLiteral {
private:
	NumberLiteral<int> numerator;
	NumberLiteral<int> denominator;

	void simplify();

public:
	RationalLiteral(const NumberLiteral<int>& num = 0, const NumberLiteral<int>& num = 1) : numerator(num), denominator(dem){
		simplify();
	}

	const NumberLiteral<int>& getNumerator() const {return numerator;}
	const NumberLiteral<int>& getDenominator() const {return denominator;}
	const NumberLiteral<double>& toReal() const;
	void neg();
	const string& toString() const;
};

#endif // RATIONAL_LITERAL_H