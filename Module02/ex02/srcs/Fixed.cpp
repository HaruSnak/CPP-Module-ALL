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

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

Fixed& Fixed::operator=(const Fixed& fixed_b)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = fixed_b.value;
	return (*this);
}

bool	Fixed::operator<=(const Fixed& fixed_b) const
{
	return (value <= fixed_b.value);
}

bool	Fixed::operator>=(const Fixed& fixed_b) const
{
	return (value >= fixed_b.value);
}

bool	Fixed::operator<(const Fixed& fixed_b) const
{
	return (value < fixed_b.value);
}

bool Fixed::operator>(const Fixed& fixed_b) const
{
	return (value > fixed_b.value);
}

bool Fixed::operator==(const Fixed& fixed_b) const
{
	return (value == fixed_b.value);
}

bool Fixed::operator!=(const Fixed& fixed_b) const
{
	return (value != fixed_b.value);
}

Fixed Fixed::operator+(const Fixed& fixed_b) const
{
	Fixed tmp;
	tmp.setRawBits(this->value + fixed_b.value);
	return (tmp);
}

Fixed Fixed::operator-(const Fixed& fixed_b) const
{
	Fixed tmp;
	tmp.setRawBits(this->value - fixed_b.value);
	return (tmp);
}

Fixed Fixed::operator*(const Fixed& fixed_b) const
{
	Fixed tmp;
	tmp.setRawBits((this->toFloat() * fixed_b.toFloat()) * (1 << bits));
	return (tmp);
}

Fixed Fixed::operator/(const Fixed& fixed_b) const
{
	Fixed tmp;
	tmp.setRawBits((this->toFloat() / fixed_b.toFloat()) * (1 << bits));
	return (tmp);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->value++;
	return (tmp);
}

Fixed& Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->value--;
	return (tmp);
}

Fixed& Fixed::operator--()
{
	this->value--;
	return (*this);
}
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
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

Fixed& Fixed::min(Fixed& value1, Fixed& value2)
{
	return (value1 < value2 ? value1 : value2);
}

const Fixed& Fixed::min(const Fixed& value1, const Fixed& value2)
{
	return (value1 < value2 ? value1 : value2);
}

Fixed& Fixed::max(Fixed& value1, Fixed& value2) 
{
	return (value1 > value2 ? value1 : value2);
}

const Fixed& Fixed::max(const Fixed& value1, const Fixed& value2)
{
	return (value1 > value2 ? value1 : value2);
}