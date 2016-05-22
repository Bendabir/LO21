#include "literal.h"

// Surchages d'opérateurs
std::ostream& operator<<(std::ostream& f, const Literal& l){
    f << l.toString().toStdString();

    return f;
}


