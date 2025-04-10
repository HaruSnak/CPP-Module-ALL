/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:55:48 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/08 23:52:24 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact {
	private:
		std::string m_first_name;
		std::string m_last_name;
		std::string m_nick_name;
		std::string m_phone_number;
		std::string m_secret;

	public:
		Contact();
		Contact(std::string first_name, std::string last_name, std::string nick_name,
			std::string phone_number, std::string secret);
		void	displayAllContacts(int index);
		void	displayOneContact(void);
};

#endif