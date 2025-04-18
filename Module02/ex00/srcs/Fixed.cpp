/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:09:48 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/13 21:06:09 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Fixed::Fixed() : value(0)
{
	std::cout << "Fixed constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &a) : value(a.value)
{
	std::cout << "Fixed constructor copy" << std::endl;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Fixed::~Fixed()
{
	std::cout << "Fixed destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed_b)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = fixed_b.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}
