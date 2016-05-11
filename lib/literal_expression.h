#ifndef LITERAL_EXPRESSION_H
#define LITERAL_EXPRESSION_H

#include "literal.h"

class LiteralExpression : public Literal {
	string expression;

public:
	LiteralExpression(const string& exp) : expression(exp){}

	const string& getExpression() const {return expression;}

	Operand* evaluate() const;
	bool checkExpression() const;
};

#endif // LITERAL_EXPRESSION_H