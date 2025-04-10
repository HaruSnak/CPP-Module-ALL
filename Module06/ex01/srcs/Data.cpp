#include "../includes/Data.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Data::Data() : value(0), name("")
{
	std::cout << "Default constructor called ~ Data" << std::endl;
	return ;
}

Data::Data(const Data &copy)
{
	std::cout << "Name constructor called ~ Data" << std::endl;
	*this = copy;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Data::~Data()
{
	std::cout << "Destructor called ~ Data" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

Data& Data::operator=(const Data& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/



