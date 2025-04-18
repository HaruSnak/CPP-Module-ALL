/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:24:39 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/15 17:24:40 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Dog::Dog() : Animal()
{
	std::cout << "Default constructor called ~ Dog" << std::endl;
	this->type = "Dog";
	return ;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Copy constructor called ~ Dog" << std::endl;
	this->type = copy.type;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Dog::~Dog()
{
    std::cout << "Destructor called ~ Dog" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

Dog	&Dog::operator=(Dog const &copy)
{
	if ( this != &copy )
	{
		this->type = copy.type;
	}
	return *this;
}


/*------------------------------- FUNCTIONS --------------------------------*/

void	Dog::makeSound(void) const
{
	std::cout << "The " << this->type << " barks!" << std::endl << std::endl;
	return ;
}

