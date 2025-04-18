/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:34:38 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/15 17:36:42 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Brain::Brain()
{
	std::cout << "Default constructor called ~ Brain" << std::endl;
	return ;
}

Brain::Brain(const Brain &copy) : ideas(copy.ideas)
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

Brain& Brain::operator=(const Brain& copy)
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
		std::cerr << "Error:" << std::endl;
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
