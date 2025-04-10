/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/02/23 17:55:01 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(int argc, char *argv[])
{
	std::string	level[] = {"DEBUG", "INFO", "WARNING", "ERROR", "TEST"};
	Harl	harl;
	if (argc != 2)
	{
		std::cerr << "Error: One Argument!" << std::endl;
		exit(-1);
	}
	harl.complain(argv[1]);
	return (0);
}