/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:21:11 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 16:21:23 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/C.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

C::C()
{
	std::cout << "Default constructor called ~ C" << std::endl;
	return ;
}

C::C(const C &copy)
{
	(void)copy;
	std::cout << "Name constructor called ~ C" << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

C::~C()
{
	std::cout << "Destructor called ~ C" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

C& C::operator=(const C& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

