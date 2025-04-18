/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:09:39 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/15 17:24:19 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	this->type = copy.type;
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

