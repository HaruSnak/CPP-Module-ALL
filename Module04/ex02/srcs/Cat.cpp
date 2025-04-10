#include "../includes/Cat.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Cat::Cat() : Animal()
{
	std::cout << "Default constructor called ~ Cat" << std::endl;
	this->type = "Cat";
	m_Brain = new Brain();
	return ;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Copy constructor called ~ Cat" << std::endl;
	m_Brain = new Brain(*copy.m_Brain);
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Cat::~Cat()
{
    std::cout << "Destructor called ~ Cat" << std::endl;
	if (m_Brain != NULL)
		delete	m_Brain;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

Cat	&Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		delete m_Brain;
		m_Brain = new Brain(*copy.m_Brain);
	}
	return *this;
}

/*------------------------------- FUNCTIONS --------------------------------*/

void	Cat::makeSound(void) const
{
	std::cout << "The " << this->type << " meows!" << std::endl << std::endl;
	return ;
}

void	Cat::setIdeasCat(unsigned int i, std::string addIdeas)
{
	this->m_Brain->setIdeas(i, addIdeas);
	return ;
}

void	Cat::getIdeasCat(void)
{
	this->m_Brain->getIdeas();
	return ;
}
