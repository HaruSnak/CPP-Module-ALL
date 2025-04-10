/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:29:18 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/09 18:14:37 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon() : type("") {}

Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon(void) {}

const std::string&	Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std::string str_type)
{
	this->type = str_type;
	return ;
}