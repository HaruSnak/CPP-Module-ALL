#include "../includes/Dog.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Dog::Dog() : Animal()
{
	std::cout << "Default constructor called ~ Dog" << std::endl;
	this->type = "Dog";
	m_Brain = new Brain();
	return ;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Copy constructor called ~ Dog" << std::endl;
	m_Brain = new Brain(*copy.m_Brain);
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Dog::~Dog()
{
    std::cout << "Destructor called ~ Dog" << std::endl;
	if (m_Brain != NULL)
		delete	m_Brain;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

Dog	&Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete m_Brain;
		m_Brain = new Brain(*copy.m_Brain);
	}
	return *this;
}

/*------------------------------- FUNCTIONS --------------------------------*/

void	Dog::makeSound(void) const
{
	std::cout << "The " << this->type << " barks!" << std::endl << std::endl;
	return ;
}

void	Dog::setIdeasDog(unsigned int i, std::string addIdeas)
{
	this->m_Brain->setIdeas(i, addIdeas);
	return ;
}

void	Dog::getIdeasDog(void)
{
	this->m_Brain->getIdeas();
	return ;
}
