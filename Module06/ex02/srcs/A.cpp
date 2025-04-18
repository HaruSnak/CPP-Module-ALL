/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:10:15 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 16:20:22 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

A::A()
{
	std::cout << "Default constructor called ~ A" << std::endl;
	return ;
}

A::A(const A &copy)
{
	(void)copy;
	std::cout << "Name constructor called ~ A" << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

A::~A()
{
	std::cout << "Destructor called ~ A" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

A& A::operator=(const A& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/
