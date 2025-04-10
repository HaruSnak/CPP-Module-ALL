#include "../includes/B.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

B::B()
{
	std::cout << "Default constructor called ~ B" << std::endl;
	return ;
}

B::B(const B &copy)
{
	std::cout << "Name constructor called ~ B" << std::endl;
	*this = copy;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

B::~B()
{
	std::cout << "Destructor called ~ B" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

B& B::operator=(const B& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/



