/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:55:36 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/08 23:57:37 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/awphonebook.hpp"

int	ft_verifyalpha(std::string *input, int k, char c)
{
	for (size_t i = 0; i < input[k].length(); i++)
	{
		if ((c == 'T' || c == 'A') && std::isspace(input[k][i]))
				continue ;
		if (c == 'T' && (std::isalpha(input[k][i]) == 0 || std::isspace(input[k][i]) != 0))
		{
			std::cout << "\033[31mError: Please put only alphabetical letters!\033[0m" << std::endl;
			return (-1);
		}
		else if (c == 'N' && std::isdigit(input[k][i]) == 0)
		{
			std::cout << "\033[31mError: Please enter numbers only!\033[0m" << std::endl;
			return (-1);
		}
		else if (c == 'A' && (std::isalnum(input[k][i]) == 0 || std::isspace(input[k][i]) != 0))
		{
			std::cout << "\033[31mError: Please enter only numbers or alphabetical letters!\033[0m" << std::endl;
			return (-1);
		}
	}
	return (0);
}

void	ft_ifeofcin(void)
{
	if (std::cin.eof())
	{
		std::cout << "\n\033[31mError: End of input detected. Program closing.\033[0m" << std::endl;
		exit(-1);
	}
}