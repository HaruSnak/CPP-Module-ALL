/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:03:33 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/10 19:25:39 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc == 1 || argv[1][0] == '\0')
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; ++i)
	{
		for (int k = 0; argv[i][k] != '\0'; ++k)
		{
			if (std::isalpha(argv[i][k]))
				std::cout << static_cast<char>(std::toupper(argv[i][k]));
			else
				std::cout << argv[i][k];
		}
	}
	std::cout << std::endl;
	return (0);
}
