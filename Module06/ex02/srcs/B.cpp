/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:21:06 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 16:21:07 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/B.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

B::B()
{
	std::cout << "Default constructor called ~ B" << std::endl;
	return ;
}

B::B(const B &copy)
{
	(void)copy;
	std::cout << "Name constructor called ~ B" << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

B::~B()
{
	std::cout << "Destructor called ~ B" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

B& B::operator=(const B& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/



