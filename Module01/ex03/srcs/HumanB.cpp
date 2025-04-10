/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:42:56 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/09 18:14:48 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL) {}

HumanB::~HumanB(void) {}

void	HumanB::setWeapon(Weapon& w)
{
	this->weapon = &w;
}

void	HumanB::attack(void)
{
	if (!this->weapon)
	{
		std::cerr << "Error: " << this->name << " does not own a weapon!" << std::endl;
		return ;
	}
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}