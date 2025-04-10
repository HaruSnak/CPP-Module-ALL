#include "../includes/FragTrap.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Default constructor called ~ FragTrap " << this->m_Name << std::endl;
	this->m_Hit_point = 100;
	this->m_Attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy.m_Name)
{
	std::cout << "Name constructor called ~ FragTrap " << this->m_Name << std::endl;
	this->m_Hit_point = copy.m_Hit_point;
	this->m_Energy_point = copy.m_Energy_point;
	this->m_Attack_damage = copy.m_Attack_damage;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

FragTrap::~FragTrap()
{
	std::cout << "Destructor called ~ FragTrap " << this->m_Name << std::endl;
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
	std::cout << "FragTrap " << this->m_Name << " gives a high five!" << std::endl;
}