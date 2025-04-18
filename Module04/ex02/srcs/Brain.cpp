/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:10:40 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/15 18:10:41 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Brain::Brain()
{
	std::cout << "Default constructor called ~ Brain" << std::endl;
	return ;
}

Brain::Brain(Brain &copy) : ideas(copy.ideas)
{
	std::cout << "Name constructor called ~ Brain" << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Brain::~Brain()
{
	std::cout << "Destructor called ~ Brain" << std::endl;
	return ;
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
		std::cerr << "Error: Invalid number 0 > 100" << std::endl;
	return ;
}

void	Brain::getIdeas(void) const
{
	std::cout << "---------------------------------------" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (!this->ideas[i].empty())
			std::cout << "" << i << ": " << this->ideas[i] << std::endl;
	}
	std::cout << "---------------------------------------" << std::endl;
	return ;
}
 