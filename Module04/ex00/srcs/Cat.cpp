#include "../includes/Cat.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Cat::Cat() : Animal()
{
	std::cout << "Default constructor called ~ Cat" << std::endl;
	this->type = "Cat";
	return ;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Copy constructor called ~ Cat" << std::endl;
	*this = copy;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Cat::~Cat()
{
    std::cout << "Destructor called ~ Cat" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

Cat	&Cat::operator=(Cat const &copy)
{
	if ( this != &copy )
	{
		this->type = copy.type;
	}
	return *this;
}

/*------------------------------- FUNCTIONS --------------------------------*/

void	Cat::makeSound(void) const
{
	std::cout << "The " << this->type << " meows!" << std::endl << std::endl;
	return ;
}

