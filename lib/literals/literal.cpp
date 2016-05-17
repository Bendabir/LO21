#include "literal.h"

ostream& operator<<(ostream& f, const Literal& literal){
	f << literal.toString();
	return f;
}