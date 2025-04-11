/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:55:29 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/10 22:46:14 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook() : m_index(0), m_count(0) {}

void	PhoneBook::addContacts(std::string first_name, std::string last_name, std::string nick_name,
			std::string phone_number, std::string secret)
{
	if (this->m_index == 8)
		this->m_index = 0;
	this->m_contacts[m_index] = Contact(first_name, last_name, nick_name, phone_number, secret);
	this->m_index++;
	if (this->m_count < 8)
		this->m_count++;
}

void	PhoneBook::searchContacts(char c, int b_index)
{
	if (c == 'A')
	{
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "|" << std::setw(10) << "Index"
		<< "|" << std::setw(10) << "First Name" << "|" << std::setw(10)
		<< "Last Name" << "|" << std::setw(10) << "NickName" << "|" << std::endl;
		for (int i = 0; i < this->m_count; i++)
		{
			this->m_contacts[i].displayAllContacts(i);
		}
		std::cout << "---------------------------------------------" << std::endl;
	}
	else
	{
		if (b_index < 1 || b_index > 8 || b_index > this->m_count || this->m_count == 0)
		{
			std::cout << "Error: Invalid index!" << std::endl;
			return ;
		}
		m_contacts[b_index - 1].displayOneContact();
	}
}

void	PhoneBook::boucleAddImplement(std::string input[])
{
	while (1)
	{
		(std::cout << COLOR_GREEN + "First Name: " + COLOR_NONE, baseGetLine(input, 1));
		if (ft_verifyalpha(input, 1, ERROR_ALPHA) == -1)
			continue ;
		(std::cout << COLOR_GREEN + "Last Name: " + COLOR_NONE, baseGetLine(input, 2));
		if (ft_verifyalpha(input, 2, ERROR_ALPHA) == -1)
			continue ;
		(std::cout << COLOR_GREEN + "Nickname: " + COLOR_NONE, baseGetLine(input, 3));
		if (ft_verifyalpha(input, 3, ERROR_ALNUM) == -1)
			continue ;
		(std::cout << COLOR_GREEN + "Phone Number: " + COLOR_NONE, baseGetLine(input, 4));
		if (ft_verifyalpha(input, 4, ERROR_DIGIT) == -1)
			continue ;
		(std::cout << COLOR_GREEN + "Secret: " + COLOR_NONE, baseGetLine(input, 5));
		if (ft_verifyalpha(input, 5, ERROR_ALNUM) == -1)
			continue ;
		this->addContacts(input[1], input[2], input[3], input[4], input[5]);
		break ;
	}
}
