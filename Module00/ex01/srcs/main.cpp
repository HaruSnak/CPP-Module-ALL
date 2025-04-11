/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:55:23 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/10 22:44:09 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/awphonebook.hpp"

void	baseGetLine(std::string input[], int index)
{
	std::getline(std::cin, input[index]);
	ft_ifeofcin();
}

int	main(void)
{
	PhoneBook phonebook;
	std::string input[6];

	while (1)
	{
		std::cout << COLOR_RED + "\nThe ADD command is used to add a contact, SEARCH to search for a contact and EXIT to exit the program." + COLOR_NONE << std::endl;
		std::cout << COLOR_GREEN + "Enter a command: " + COLOR_NONE;
		std::cin >> input[0];
		ft_ifeofcin();
		std::cin.ignore(10000, '\n');
		if (input[0].compare("ADD") == 0)
			phonebook.boucleAddImplement(input);
		else if (input[0].compare("SEARCH") == 0)
		{
			phonebook.searchContacts('A', 0);
			(std::cout << COLOR_GREEN + "Select an index for more information: " + COLOR_NONE, std::cin >> input[0], ft_ifeofcin());
			if (ft_verifyalpha(input, 0, ERROR_DIGIT) == -1)
					continue ;
			phonebook.searchContacts('O', std::atoi(input[0].c_str()));
		}
		else if (input[0].compare("EXIT") == 0)
			break ;
		else
			std::cout << COLOR_RED + "Error: Command invalid, retry!" + COLOR_NONE << std::endl;
	}
	return (0);
}
