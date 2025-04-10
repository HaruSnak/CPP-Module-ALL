#include "../includes/Fixed.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = a;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
	Fixed::value = raw;
}
