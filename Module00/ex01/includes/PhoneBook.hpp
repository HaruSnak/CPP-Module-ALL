/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:55:32 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/08 23:52:36 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact m_contacts[8];
		int m_index;
		int m_count;

	public:
		PhoneBook();
		void	addContacts(std::string first_name, std::string last_name, std::string nick_name,
			std::string phone_number, std::string secret);
		void	searchContacts(char c, int b_index);
};

#endif