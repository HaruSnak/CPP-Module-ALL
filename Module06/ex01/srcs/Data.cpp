/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:48:10 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 15:10:53 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Data::Data() : value(0), name("")
{
	std::cout << "Default constructor called ~ Data" << std::endl;
	return ;
}

Data::Data(const Data &copy) : value(copy.value), name(copy.name)
{
	std::cout << "Name constructor called ~ Data" << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Data::~Data()
{
	std::cout << "Destructor called ~ Data" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

Data& Data::operator=(const Data& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/



