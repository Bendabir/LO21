#include "integer_literal.h"

std::ostream& operator<<(std::ostream& f, const IntegerLiteral& l){
    f << l.toString().toStdString();

    return f;
}

QString IntegerLiteral::toString() const {
    return QString::number(value);
}
