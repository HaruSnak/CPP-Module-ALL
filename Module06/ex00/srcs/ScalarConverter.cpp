/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:45:35 by shmoreno          #+#    #+#             */
/*   Updated: 2025/07/21 15:25:02 by shmoreno         ###   ########.fr       */
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
	*this = copy;
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
    
    if (isCharLiteral(literal))
    {
        convertFromChar(literal);
        return;
    }
    if (!parseNumeric(literal, f, d))
    {
        std::cerr << "Error: Invalid input format!" << std::endl;
        return;
    }
    displayConversions(f, d);
}

bool ScalarConverter::isCharLiteral(const std::string &literal)
{
    return ((literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
        || (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])));
}

void ScalarConverter::convertFromChar(const std::string &literal)
{
    char c = literal.length() == 3 ? literal[1] : literal[0];
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

bool ScalarConverter::parseNumeric(const std::string &literal, float &f, double &d)
{
	if (literal.empty())
		return (false);
    char *end;
    d = strtod(literal.c_str(), &end);
    if (*end == 'f' && end[1] == '\0')
        f = strtof(literal.c_str(), NULL);
    else
        f = static_cast<float>(d);
    
    return (*end == '\0' || (*end == 'f' && end[1] == '\0'));
}

void ScalarConverter::displayConversions(float f, double d)
{
    // Gestion des cas spéciaux (NaN et infinis)
    if (std::isnan(d))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    
    if (std::isinf(d))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (std::isinf(f) ? (f < 0 ? "-inff" : "+inff") : (d < 0 ? "-inff" : "+inff")) << std::endl;
        std::cout << "double: " << (d < 0 ? "-inf" : "+inf") << std::endl;
        return;
    }
    
    // Conversion char
    int intValue = static_cast<int>(d);
    if (intValue < 0 || intValue > 255)
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<unsigned char>(intValue)))
        std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    
    // Conversion int
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    
    // Conversion float
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    
    // Conversion double
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

