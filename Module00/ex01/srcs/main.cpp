/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:55:23 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/09 00:14:59 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/awphonebook.hpp"

void	baseGetLine(std::string input[], int index)
{
	std::getline(std::cin, input[index]);
	ft_ifeofcin();
}

void	boucleAddImplement(PhoneBook *phonebook, std::string input[])
{
	while (1)
	{
		(std::cout << "\033[32mFirst Name:\033[0m ", baseGetLine(input, 1));
		if (ft_verifyalpha(input, 1, 'T') == -1)
			continue ;
		(std::cout << "\033[32mLast Name:\033[0m ", baseGetLine(input, 2));
		if (ft_verifyalpha(input, 2, 'T') == -1)
			continue ;
		(std::cout << "\033[32mNickname:\033[0m ", baseGetLine(input, 3));
		if (ft_verifyalpha(input, 3, 'A') == -1)
			continue ;
		(std::cout << "\033[32mPhone Number:\033[0m ", baseGetLine(input, 4));
		if (ft_verifyalpha(input, 4, 'N') == -1)
			continue ;
		(std::cout << "\033[32mSecret:\033[0m ", baseGetLine(input, 5));
		if (ft_verifyalpha(input, 5, 'A') == -1)
			continue ;
		phonebook->addContacts(input[1], input[2], input[3], input[4], input[5]);
		break ;
	}
}

int	main(void)
{
	PhoneBook phonebook;
	std::string input[6];

	while (1)
	{
		std::cout << "\n\033[31mThe ADD command is used to add a contact, SEARCH to search for a contact and EXIT to exit the program.\033[0m" << std::endl;
		std::cout << "\033[32mEnter a command:\033[0m ";
		std::cin >> input[0];
		ft_ifeofcin();
		std::cin.ignore(10000, '\n');
		if (input[0].compare("ADD") == 0)
			boucleAddImplement(&phonebook, input);
		else if (input[0].compare("SEARCH") == 0)
		{
			phonebook.searchContacts('A', 0);
			(std::cout << "\033[32mSelect an index for more information:\033[0m ", std::cin >> input[0], ft_ifeofcin());
			if (ft_verifyalpha(input, 0, 'N') == -1)
					continue ;
			phonebook.searchContacts('O', std::atoi(input[0].c_str()));
		}
		else if (input[0].compare("EXIT") == 0)
			break ;
		else
			std::cout << "\033[32mError: Command invalid, retry!\033[0m" << std::endl;
	}
	return (0);
}
