/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:45:57 by shmoreno          #+#    #+#             */
/*   Updated: 2025/05/07 18:31:50 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.hpp"

void	errorType(std::string errorMsg)
{
	color::err_red("Error: " + errorMsg);
	exit(-1);
}