#include "../includes/A.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

A::A()
{
	std::cout << "Default constructor called ~ A" << std::endl;
	return ;
}

A::A(const A &copy)
{
	std::cout << "Name constructor called ~ A" << std::endl;
	*this = copy;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

A::~A()
{
	std::cout << "Destructor called ~ A" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

A& A::operator=(const A& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/
