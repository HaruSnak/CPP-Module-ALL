/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:55:36 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/10 22:45:38 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/awphonebook.hpp"

int	ft_verifyalpha(std::string *input, int k, Error nbr)
{
	for (size_t i = 0; i < input[k].length(); i++)
	{
		if ((nbr == ERROR_ALPHA || nbr == ERROR_ALNUM) && std::isspace(input[k][i]))
				continue ;
		if (nbr == ERROR_ALPHA && (std::isalpha(input[k][i]) == 0 || std::isspace(input[k][i]) != 0))
		{
			std::cout << COLOR_RED + "Error: Please put only alphabetical letters!" + COLOR_NONE << std::endl;
			return (-1);
		}
		else if (nbr == ERROR_DIGIT && std::isdigit(input[k][i]) == 0)
		{
			std::cout << COLOR_RED + "Error: Please enter numbers only!" + COLOR_NONE << std::endl;
			return (-1);
		}
		else if (nbr == ERROR_ALNUM && (std::isalnum(input[k][i]) == 0 || std::isspace(input[k][i]) != 0))
		{
			std::cout << COLOR_RED + "Error: Please enter only numbers or alphabetical letters!" + COLOR_NONE << std::endl;
			return (-1);
		}
	}
	return (0);
}

void	ft_ifeofcin(void)
{
	if (std::cin.eof())
	{
		std::cout << COLOR_RED + "Error: End of input detected. Program closing." + COLOR_NONE << std::endl;
		exit(-1);
	}
}