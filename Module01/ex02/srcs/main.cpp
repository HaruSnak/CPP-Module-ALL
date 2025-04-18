/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/12 16:35:29 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/brain_shout.hpp"

int main(void)
{
	std::string str;
	std::string *stringPTR;
	std::string& stringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	color::red("Memory address string: ") << &str << std::endl;
	color::red("Memory address pointer: ") << &stringPTR << std::endl;
	color::red("Memory address reference: ") << &stringREF << std::endl;
	color::red("Value string: ") << str << std::endl;
	color::red("Value pointer: ") << stringPTR << std::endl;
	color::red("Value reference: ") << stringREF << std::endl;
	return (0);
}