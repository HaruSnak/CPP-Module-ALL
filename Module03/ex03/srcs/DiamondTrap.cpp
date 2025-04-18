/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:53:37 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/15 17:03:54 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), m_Name(name)
{
	this->m_Hit_point = this->FragTrap::M_HP;
	this->m_Attack_damage = this->FragTrap::M_DAMAGE;
	this->m_Energy_point = this->ScavTrap::M_ENERGY;
	std::cout << "DiamondTrap constructor called ~ " << this->m_Name << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	std::cout << "DiamondTrap constructor copy ~ " << this->m_Name << std::endl;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called ~ " << this->m_Name << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

DiamondTrap& DiamondTrap::operator=(DiamondTrap& copy)
{
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
		FragTrap::operator=(copy);
		ScavTrap::operator=(copy);
		this->m_Name = copy.m_Name;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << this->m_Name << " | " << "ClapTrap " << ClapTrap::m_Name << std::endl << std::endl;
	return ;
}

