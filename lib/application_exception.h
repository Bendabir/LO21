#ifndef APPLICATION_EXCEPTION_H
#define APPLICATION_EXCEPTION_H

#include <iostream>
#include <string>

// A voir pour implémenter une exception de la STL

class ApplicationException {
	string info;

public:
	ApplicationException(const string& i) : info(i){}
	~ApplicationException(){}

	const string& getInfo() const {return info;}
};

#endif // APPLICATION_EXCEPTION_H