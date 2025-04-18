/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:49 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/12 17:08:49 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/harlFilter.hpp"

int main(int argc, char *argv[])
{
	std::string	level[] = {"DEBUG", "INFO", "WARNING", "ERROR", "TEST"};
	Harl	harl;
	if (argc != 2)
	{
		color::err_red("Error: One Argument!");
		exit(-1);
	}
	harl.complain(argv[1]);
	return (0);
}