#include "../includes/WrongAnimal.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

WrongAnimal::WrongAnimal()
{
	std::cout << "Default constructor called ~ WrongAnimal" << std::endl;
	this->type = "WrongAnimal";
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "Copy constructor called ~ WrongAnimal" << std::endl;
	this->type = copy.type;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor called ~ WrongAnimal" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

WrongAnimal&WrongAnimal::operator=(WrongAnimal const &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

/*------------------------------- FUNCTIONS --------------------------------*/

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal are making noises in the distance!" << std::endl << std::endl;
	return ;
}

const std::string&	WrongAnimal::getType(void) const
{
	return (this->type);
}