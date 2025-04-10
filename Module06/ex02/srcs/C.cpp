#include "../includes/C.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

C::C()
{
	std::cout << "Default constructor called ~ C" << std::endl;
	return ;
}

C::C(const C &copy)
{
	std::cout << "Name constructor called ~ C" << std::endl;
	*this = copy;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

C::~C()
{
	std::cout << "Destructor called ~ C" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

C& C::operator=(const C& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

