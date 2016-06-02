#ifndef CALCULATOREXCEPTION_H
#define CALCULATOREXCEPTION_H

#include <iostream>
#include <string>
#include <typeinfo>
#include <exception>

#include <QString>

using namespace std;

/*!
 * \brief La classe CalculatorException, basée sur std::exception.
 * \brief Permet de gérer les exceptions du programme.
 */

class CalculatorException : public exception {
private:
    QString info;

public:
    CalculatorException(const QString& s = "") throw() : info(s){}

    /*!
     * \brief Renvoie le message d'erreur contenu dans l'objet CalculatorException
     * \return Chaine de caractère standard
     */
    const char* what() const throw(){return info.toStdString().c_str();}
};

/*!
 * \brief Surchage de l'opérateur << pour la classe CalculatorException
 * \param Le flux
 * \param L'exception
 * \return Le flux modifié
 */
ostream& operator<<(ostream& f, const CalculatorException& e);

#endif // CALCULATOREXCEPTION_H
