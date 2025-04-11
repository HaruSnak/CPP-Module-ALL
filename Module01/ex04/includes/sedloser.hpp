/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sedloser.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:28:55 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/11 22:28:22 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDLOSER_HPP
#define SEDLOSER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>

const std::string COLOR_RED = "\033[31m";
const std::string COLOR_GREEN = "\033[32m";
const std::string COLOR_NONE = "\033[0m";

void	ft_error_base(std::string str);

#endif