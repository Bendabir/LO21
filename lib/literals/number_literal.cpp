#include <sstream>

#include "number_literal.h"

const string& NumberLiteral::toString() const {
	stringstream s;
	s << value;

	return s.str();
}