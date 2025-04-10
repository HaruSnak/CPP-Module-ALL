#ifndef Fixed_HPP
# define Fixed_HPP

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
		Fixed(const Fixed &a);
		Fixed(const int number_int);
		Fixed(const float number_float);
		~Fixed();
		Fixed& operator=(const Fixed& fixed);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
