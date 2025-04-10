#include "../includes/Brain.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Brain::Brain()
{
	std::cout << "Default constructor called ~ Brain" << std::endl;
}

Brain::Brain(Brain &copy)
{
	std::cout << "Name constructor called ~ Brain" << std::endl;
	*this = copy;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Brain::~Brain()
{
	std::cout << "Destructor called ~ Brain" << std::endl;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

Brain& Brain::operator=(Brain& copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = copy.ideas[i];
		}
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

void	Brain::setIdeas(unsigned int i, std::string addIdeas)
{
	if (i < 100)
		this->ideas[i] = addIdeas;
	else
		std::cerr << "\033[31mError: Invalid number 0 > 100\033[0m" << std::endl;
	return ;
}

void	Brain::getIdeas(void) const
{
	std::cout << "\033[31m---------------------------------------\033[0m" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (!this->ideas[i].empty())
			std::cout << "\033[31m" << i << ": \033[0m" << this->ideas[i] << std::endl;
	}
	std::cout << "\033[31m---------------------------------------\033[0m" << std::endl;
	return ;
}
