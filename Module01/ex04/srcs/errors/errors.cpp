/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:27:25 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/10 00:02:49 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sedloser.hpp"

void	ft_error_base(std::string str)
{
	std::cerr << "\033[31mError: " << str << std::endl;
	exit(-1);
}