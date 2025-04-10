/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:55:46 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/08 23:55:11 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(): m_first_name(""), m_last_name(""), m_nick_name(""),
		m_phone_number(""), m_secret("") {}

Contact::Contact(std::string first_name, std::string last_name,
				std::string nick_name, std::string phone_number, std::string secret) :
				m_first_name(first_name), m_last_name(last_name), m_nick_name(nick_name),
				m_phone_number(phone_number), m_secret(secret) {}

std::string	truncContacts(std::string str, int width = 10)
{
	if (str.length() > 10)
		return (str.substr(0, width - 1) + ".");
	return (str);
}

void	Contact::displayAllContacts(int index)
{
	std::cout << "|" <<  std::setw(10) << index + 1
	<< "|" << std::setw(10) << truncContacts(this->m_first_name)
	<< "|" << std::setw(10) << truncContacts(this->m_last_name)
	<< "|" << std::setw(10) << truncContacts(this->m_nick_name)
	<< "|" << std::endl;
}

void	Contact::displayOneContact(void)
{
	std::cout << "\n--------------------" << std::endl;
	std::cout << "First Name: " << this->m_first_name << std::endl;
	std::cout << "Last Name: " << this->m_last_name << std::endl;
	std::cout << "Nickname: " << this->m_nick_name << std::endl;
	std::cout << "Phone Number: " << this->m_phone_number << std::endl;
	std::cout << "Secret: " << this->m_secret << std::endl;
	std::cout << "--------------------" << std::endl;
}

