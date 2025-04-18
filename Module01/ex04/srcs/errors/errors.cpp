/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:27:25 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/12 16:58:39 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sedloser.hpp"

void	ft_error_base(std::string str)
{
	std::cerr << color::COLOR_RED + "Error: " << str << std::endl;
	exit(-1);
}