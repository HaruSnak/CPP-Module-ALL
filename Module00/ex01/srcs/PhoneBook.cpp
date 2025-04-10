/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:55:29 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/08 23:53:11 by shmoreno         ###   ########.fr       */
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
