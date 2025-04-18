/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:11:27 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 16:02:31 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Serializer::Serializer()
{
	std::cout << "Serializer constructor called" << std::endl;
	return ;
}

Serializer::Serializer(const Serializer &copy)
{
	(void)copy;
	std::cout << "Serializer constructor copy" << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

Serializer& Serializer::operator=(const Serializer& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
