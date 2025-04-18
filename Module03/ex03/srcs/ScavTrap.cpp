/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:53:41 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/15 16:53:42 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called ~ " << this->m_Name << std::endl;
	this->m_Hit_point = M_DAMAGE;
	this->m_Energy_point = M_HP;
	this->m_Attack_damage = M_ENERGY;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy.m_Name)
{
	std::cout << "ScavTrap constructor copy ~ " << this->m_Name << std::endl;
	this->m_Hit_point = copy.m_Hit_point;
	this->m_Energy_point = copy.m_Energy_point;
	this->m_Attack_damage = copy.m_Attack_damage;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called ~ " << this->m_Name << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	if (this != &copy)
	{
		this->m_Name = copy.m_Name;
		this->m_Hit_point = copy.m_Hit_point;
		this->m_Energy_point = copy.m_Energy_point;
		this->m_Attack_damage = copy.m_Attack_damage;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "__________________________________________________________________" << std::endl;
	if (this->m_Energy_point > 0 && this->m_Hit_point > 0)
	{
		std::cout << "ScavTrap " << this->m_Name << " attacks " << target << ", causing " << this->m_Attack_damage << " points of damage!" << std::endl;
		this->m_Energy_point--;
		std::cout << "ScavTrap " << this->m_Name << " recalculates his energy, he has " << this->m_Energy_point << "!" << std::endl;
	}
	else if (this->m_Energy_point < 1)
		std::cout << "ClapTrap " << this->m_Name << " has no more energy!" << std::endl;
	else
		std::cout << "ClapTrap " << this->m_Name << " is already completely broken, here are his " << this->m_Hit_point << "hp!" << std::endl;
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->m_Energy_point > 0 && this->m_Hit_point > 0)
		std::cout << "ScavTrap " << this->m_Name << " now switches to GateKeeper mode!" << std::endl << std::endl;
	else
		std::cout << "ScavTrap " << this->m_Name << " can't enter Gate Keeper mode (no energy or no HP)!" << std::endl << std::endl;
}

