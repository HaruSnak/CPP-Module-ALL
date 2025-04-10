#include "../includes/ScavTrap.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Default constructor called ~ ScavTrap " << this->m_Name << std::endl;
	this->m_Energy_point = 50;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy.m_Name)
{
	std::cout << "Name constructor called ~ ScavTrap " << this->m_Name << std::endl;
	this->m_Hit_point = copy.m_Hit_point;
	this->m_Energy_point = copy.m_Energy_point;
	this->m_Attack_damage = copy.m_Attack_damage;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called ~ ScavTrap " << this->m_Name << std::endl;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

ScavTrap& ScavTrap::operator=(ScavTrap& copy)
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
		std::cout << "ScavTrap " << this->m_Name << " recalculates his energy, he has " << this->m_Hit_point << "!" << std::endl;
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->m_Name << " now switches to GateKeeper mode!" << std::endl;
}

