/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:45:57 by shmoreno          #+#    #+#             */
/*   Updated: 2025/05/05 22:14:59 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exchange.hpp"

void	errorType(std::string errorMsg)
{
	color::err_red("Error: " + errorMsg);
	std::exit(-1);
}