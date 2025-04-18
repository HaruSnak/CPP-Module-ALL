/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:09:35 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/15 17:11:16 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Animal::Animal()
{
	std::cout << "Default constructor called ~ Animal" << std::endl;
	this->type = "Animal";
	return ;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Copy constructor called ~ Animal" << std::endl;
	this->type = copy.type;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Animal::~Animal()
{
    std::cout << "Destructor called ~ Animal" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

Animal&Animal::operator=(Animal const &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

/*------------------------------- FUNCTIONS --------------------------------*/

void	Animal::makeSound(void) const
{
	std::cout << "Animals are making noises in the distance!" << std::endl << std::endl;
	return ;
}

const std::string&	Animal::getType(void) const
{
	return (this->type);
}

