/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:26:36 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/13 21:06:56 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Fixed::Fixed() : value(0)
{
	std::cout << "Fixed constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : value(src.value)
{
	std::cout << "Fixed constructor copy" << std::endl;
}

Fixed::Fixed(const int number_int)
{
	std::cout << "Fixed ~ Int constructor called" << std::endl;
	this->value = number_int << bits;
}

Fixed::Fixed(const float number_float)
{
	std::cout << "Fixed ~ Float constructor called" << std::endl;
	this->value = roundf(number_float * (1 << bits));
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Fixed::~Fixed()
{
	std::cout << "Fixed destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed_b)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = fixed_b.value;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	std::cout << fixed.toFloat();
	return (os);
}

/*------------------------------- FUNCTIONS --------------------------------*/

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	Fixed::value = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->value) / (1 << bits));
}

int	Fixed::toInt( void ) const
{
	return (static_cast<float>(roundf(this->value) / (1 << bits)));
}
