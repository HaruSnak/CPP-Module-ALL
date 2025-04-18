/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:12:56 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/13 21:05:00 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

ClapTrap::ClapTrap(std::string name) : m_Name(name), m_Hit_point(10), m_Energy_point(10), m_Attack_damage(0)
{
	std::cout << "ClapTrap constructor called ~ " << this->m_Name << std::endl;
	if (name.size() == 0)
	{
		std::cerr << "Error: The ClapTrap instance does not have a name, please give it one!" << std::endl;
		exit(1);
	}
}

ClapTrap::ClapTrap(const ClapTrap &copy) : m_Name(copy.m_Name), m_Hit_point(copy.m_Hit_point), m_Energy_point(copy.m_Energy_point), m_Attack_damage(copy.m_Attack_damage)
{
	std::cout << "ClapTrap constructor copy ~ " << this->m_Name << std::endl;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called ~ " << this->m_Name << std::endl;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	if (this != &copy)
	{
		m_Name = copy.m_Name;
		m_Hit_point = copy.m_Hit_point;
		m_Energy_point = copy.m_Energy_point;
		m_Attack_damage = copy.m_Attack_damage;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

void ClapTrap::attack(const std::string& target)
{
	std::cout << "__________________________________________________________________" << std::endl;
	if (this->m_Energy_point > 0 && this->m_Hit_point > 0)
	{
		std::cout << "ClapTrap " << this->m_Name << " attacks " << target << ", causing " << this->m_Attack_damage << " points of damage!" << std::endl;
		this->m_Energy_point--;
		std::cout << "ClapTrap " << this->m_Name << " recalculates his energy, he has " << this->m_Energy_point << "!" << std::endl;
	}
	else if (this->m_Energy_point < 1)
		std::cout << "ClapTrap " << this->m_Name << " has no more energy!" << std::endl;
	else if (this->m_Hit_point < 1)
		std::cout << "ClapTrap " << this->m_Name << " is already completely broken, here are his " << this->m_Hit_point << "hp!" << std::endl;
	std::cout << "__________________________________________________________________" << std::endl << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "__________________________________________________________________" << std::endl;
	if (this->m_Hit_point > 0)
	{
		std::cout << "ClapTrap " << this->m_Name << " is being attacked, he loses " << amount << "hp!" << std::endl;
		this->m_Hit_point -= amount;
	}
	if (this->m_Hit_point < 0)
	{
		this->m_Hit_point = 0;
		std::cout << "ClapTrap " << this->m_Name << " is already completely broken, here are his " << this->m_Hit_point << "hp!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->m_Name << " recalculates his HP, he has " << this->m_Hit_point << "hp!" << std::endl;
	std::cout << "__________________________________________________________________" << std::endl << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "__________________________________________________________________" << std::endl;
	if (this->m_Energy_point > 0 && this->m_Hit_point > 0)
	{
		std::cout << "ClapTrap " << this->m_Name << " is being repaired, he is regaining " << amount << "hp!" << std::endl << std::endl;
		this->m_Hit_point += amount;
		this->m_Energy_point--;
		std::cout << "ClapTrap " << this->m_Name << " recalculates his HP, he has " << this->m_Hit_point << "hp!" << std::endl;
		std::cout << "ClapTrap " << this->m_Name << " recalculates his energy, he has " << this->m_Hit_point << "!" << std::endl;
	}
	else if (this->m_Energy_point < 1)
		std::cout << "ClapTrap " << this->m_Name << " has no more energy!" << std::endl;
	else
		std::cout << "ClapTrap " << this->m_Name << " is already completely broken, here are his " << this->m_Hit_point << "hp!" << std::endl;
	std::cout << "__________________________________________________________________" << std::endl << std::endl;
}
