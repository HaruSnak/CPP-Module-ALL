#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <limits>
# include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter& operator=(const ScalarConverter& copy);
	public:
		~ScalarConverter();
		static void convert(const std::string &literal);
};

#endif
