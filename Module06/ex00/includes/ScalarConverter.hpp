/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:44:18 by shmoreno          #+#    #+#             */
/*   Updated: 2025/07/21 15:03:25 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

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
		static bool isCharLiteral(const std::string &literal);
		static void convertFromChar(const std::string &literal);
		static bool parseNumeric(const std::string &literal, float &f, double &d);
		static void displayConversions(float f, double d);
	public:
		~ScalarConverter();
		static void convert(const std::string &literal);
};

#endif
