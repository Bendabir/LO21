#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <stdexcept>
#include <exception>
#include <typeinfo>

/*!
 * \brief The CalculatorException class
 */

class CalculatorException : public std::exception {
private:
    std::string info;

public:
    CalculatorException(const char* s) throw() : info(s) {}
    virtual ~CalculatorException() throw() {}
    virtual const char* what() const throw() {return info.c_str();}
};

#endif // EXCEPTIONS_H
