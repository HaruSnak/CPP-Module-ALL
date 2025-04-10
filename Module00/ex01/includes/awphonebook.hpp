/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awphonebook.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:55:41 by shmoreno          #+#    #+#             */
/*   Updated: 2025/02/24 16:40:18 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWPHONEBOOK_HPP
#define AWPHONEBOOK_HPP

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

int		ft_verifyalpha(std::string *input, int k, char c);
void	ft_ifeofcin(void);

#endif