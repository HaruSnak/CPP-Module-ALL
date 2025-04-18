/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:39:50 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/12 17:40:18 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int	value;
		static const int bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed(const int number_int);
		Fixed(const float number_float);
		~Fixed();
		Fixed& 	operator=(const Fixed& fixed_b);
		bool	operator<=(const Fixed& fixed_b) const;
		bool	operator>=(const Fixed& fixed_b) const;
		bool	operator<(const Fixed& fixed_b) const;
		bool	operator>(const Fixed& fixed_b) const;
		bool	operator==(const Fixed& fixed_b) const;
		bool	operator!=(const Fixed& fixed_b) const;
		Fixed	operator+(const Fixed& fixed_b) const;
		Fixed	operator-(const Fixed& fixed_b) const;
		Fixed	operator*(const Fixed& fixed_b) const;
		Fixed	operator/(const Fixed& fixed_b) const;
		Fixed	operator++(int);
		Fixed&	operator++();
		Fixed	operator--(int);
		Fixed&	operator--();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		static Fixed& min(Fixed& value1, Fixed& value2);
		static const Fixed& min(const Fixed& value1, const Fixed& value2);
		static Fixed& max(Fixed& value1, Fixed& value2);
		static const Fixed& max(const Fixed& value1, const Fixed& value2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
