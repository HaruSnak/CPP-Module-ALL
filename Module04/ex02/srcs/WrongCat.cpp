#include "../includes/WrongCat.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "Default constructor called ~ WrongCat" << std::endl;
	this->type = "WrongCat";
	return ;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    std::cout << "Copy constructor called ~ WrongCat" << std::endl;
	this->type = copy.type;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

WrongCat::~WrongCat()
{
    std::cout << "Destructor called ~ WrongCat" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

WrongCat	&WrongCat::operator=(WrongCat const &copy)
{
	if ( this != &copy )
	{
		this->type = copy.type;
	}
	return *this;
}

/*------------------------------- FUNCTIONS --------------------------------*/

void	WrongCat::makeSound(void) const
{
	std::cout << "The " << this->type << " meows!" << std::endl << std::endl;
	return ;
}