/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/09 12:54:56 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string str;
	std::string *stringPTR;
	std::string& stringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	std::cout << "\033[32mMemory address string:\033[0m " << &str << std::endl;
	std::cout << "\033[32mMemory address pointer:\033[0m " << &stringPTR << std::endl;
	std::cout << "\033[32mMemory address reference:\033[0m " << &stringREF << std::endl;
	std::cout << "\033[32mValue string:\033[0m " << str << std::endl;
	std::cout << "\033[32mValue pointer:\033[0m " << stringPTR << std::endl;
	std::cout << "\033[32mValue reference:\033[0m " << stringREF << std::endl;
	return (0);
}