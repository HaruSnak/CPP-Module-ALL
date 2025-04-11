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
		std::cerr << COLOR_RED + "Error: Invalid number 0 > 100COLOR_RED + " << std::endl;
	return ;
}

void	Brain::getIdeas(void) const
{
	std::cout << "COLOR_RED + "---------------------------------------COLOR_RED + " << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (!this->ideas[i].empty())
			std::cout << COLOR_RED + "" << i << ": COLOR_RED + " << this->ideas[i] << std::endl;
	}
	std::cout << "COLOR_RED + "---------------------------------------COLOR_RED + " << std::endl;
	return ;
}
