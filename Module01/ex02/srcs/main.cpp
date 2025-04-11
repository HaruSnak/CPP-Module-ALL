/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/11 22:17:55 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

const std::string COLOR_RED = "\033[31m";
const std::string COLOR_GREEN = "\033[32m";
const std::string COLOR_NONE = "\033[0m";

int main(void)
{
	std::string str;
	std::string *stringPTR;
	std::string& stringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	std::cout << COLOR_RED + "Memory address string: " + COLOR_NONE << &str << std::endl;
	std::cout << COLOR_RED + "Memory address pointer: " + COLOR_NONE << &stringPTR << std::endl;
	std::cout << COLOR_RED + "Memory address reference: " + COLOR_NONE << &stringREF << std::endl;
	std::cout << COLOR_RED + "Value string: " + COLOR_NONE << str << std::endl;
	std::cout << COLOR_RED + "Value pointer: " + COLOR_NONE << stringPTR << std::endl;
	std::cout << COLOR_RED + "Value reference: " + COLOR_NONE << stringREF << std::endl;
	return (0);
}