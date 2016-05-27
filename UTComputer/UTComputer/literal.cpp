#include "literal.h"

ostream& operator<<(ostream& f, const Literal& l){
    f << l.toString().toStdString();
    return f;
}

ostream& operator<<(ostream& f, const Literal* l){
    f << *l;
    return f;
}

// Opérateurs pour faciliter la gestion
//Literal* operator+(const Literal* l1, const Literal* l2){
//    return (*l1) + (*l2);
//}
Literal* operator+(const Literal* l1, const Literal& l2){
    return (*l1) + l2;
}

//Literal* operator-(const Literal* l1, const Literal* l2){
//    return (*l1) - (*l2);
//}
Literal* operator-(const Literal* l1, const Literal& l2){
    return (*l1) - l2;
}

//Literal* operator*(const Literal* l1, const Literal* l2){
//    return (*l1) * (*l2);
//}
Literal* operator*(const Literal* l1, const Literal& l2){
    return (*l1) * l2;
}

//Literal* operator/(const Literal* l1, const Literal* l2){
//    return (*l1) / (*l2);
//}
Literal* operator/(const Literal* l1, const Literal& l2){
    return (*l1) / l2;
}

