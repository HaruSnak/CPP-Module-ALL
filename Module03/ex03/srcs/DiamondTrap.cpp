#include "../includes/DiamondTrap.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->m_Name = name;
	std::cout << "Default constructor called ~ DiamondTrap " << this->m_Name << std::endl;
	this->m_Hit_point = FragTrap::m_Hit_point;
	this->m_Attack_damage = FragTrap::m_Attack_damage;
	this->m_Energy_point = ScavTrap::m_Energy_point;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	std::cout << "Copy constructor called ~ DiamondTrap " << this->m_Name << std::endl;
	this->m_Name = copy.m_Name;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called ~ DiamondTrap " << this->m_Name << std::endl;
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
}

