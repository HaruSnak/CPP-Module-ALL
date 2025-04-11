/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awphonebook.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:55:41 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/10 22:42:08 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWPHONEBOOK_HPP
#define AWPHONEBOOK_HPP

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>

enum Error {
	ERROR_ALPHA,
	ERROR_DIGIT,
	ERROR_ALNUM
};

const std::string COLOR_RED = "\033[31m";
const std::string COLOR_GREEN = "\033[32m";
const std::string COLOR_NONE = "\033[0m";

int		ft_verifyalpha(std::string *input, int k, Error nbr);
void	baseGetLine(std::string input[], int index);
void	ft_ifeofcin(void);

#endif