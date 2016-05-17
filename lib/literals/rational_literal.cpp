#include <sstream>

#include "rational_literal.h"

const NumberLiteral<double>& RationalLiteral::toReal() const{
	double result = static_cast<double>(numerator / denominator);

	return NumberLiteral<double>(result);
}

void RationalLiteral::neg(){
	// On suppose que la fonction simplify donne la fraction de la forme -x/y
	numerator = -numerator;
}

const string& RationalLiteral::toString() const{
	stringstream s;
	s << numerator << "/" << denominator;

	return s.str();
}

void RationalLiteral::simplify(){
	
}