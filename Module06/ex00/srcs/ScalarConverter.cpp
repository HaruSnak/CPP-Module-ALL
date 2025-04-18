/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:45:35 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 14:46:42 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructor called" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	std::cout << "ScalarConverter constructor copy" << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

void ScalarConverter::convert(const std::string &literal)
{
	float f;
	double d;
	if ((literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
	|| (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])))
	{
		char c = literal.length() == 3 ? literal[1] : literal[0];
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return ;
	}
	else
	{
		char *end;
		d = strtod(literal.c_str(), &end);
		if (*end == 'f' && end[1] == '\0')
			f = strtof(literal.c_str(), NULL);
		else
			f = static_cast<float>(d);
		if (!(*end == '\0' || (*end == 'f' && end[1] == '\0')))
		{
			std::cerr << "Error: Invalid input format!" << std::endl;
			return ;
		}
	}
	if (std::isnan(d))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan"<< std::endl;
		return ;
	}
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
			std::cout << "char: impossible" << std::endl;
		else if (std::isprint(static_cast<int>(d)))
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "char: No Displaylable" << std::endl;
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (std::isinf(f) && !std::isinf(d))
	{
		std::cout << "float: " << (f < 0 ? "-inff" : "+inff") << std::endl;
	}
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	if (std::isinf(d))
	{
		std::cout << "double: " << (d < 0 ? "-inf" : "+inf") << std::endl;
	}
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

