#include "../includes/FragTrap.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called ~ " << this->m_Name << std::endl;
	this->m_Hit_point = 100;
	this->m_Energy_point = 100;
	this->m_Attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy.m_Name)
{
	std::cout << "FragTrap constructor copy ~ " << this->m_Name << std::endl;
	this->m_Hit_point = copy.m_Hit_point;
	this->m_Energy_point = copy.m_Energy_point;
	this->m_Attack_damage = copy.m_Attack_damage;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called ~ " << this->m_Name << std::endl;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

FragTrap& FragTrap::operator=(FragTrap& copy)
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

void	FragTrap::highFivesGuys(void)
{
	if (this->m_Hit_point > 0 && this->m_Energy_point > 0)
		std::cout << "FragTrap " << this->m_Name << " gives a high five!" << std::endl << std::endl;
	else
		std::cout << "FragTrap " << this->m_Name << " can't high five (no HP left)" << std::endl << std::endl;
}