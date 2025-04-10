#include "../includes/ClapTrap.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

ClapTrap::ClapTrap(std::string name) : m_Name(name), m_Hit_point(10), m_Energy_point(10), m_Attack_damage(0)
{
	std::cout << "Default constructor called ~ ClapTrap " << this->m_Name << std::endl;
	if (name.size() == 0)
	{
		std::cerr << "Error: The ClapTrap instance does not have a name, please give it one!" << std::endl;
		exit(1);
	}
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Name constructor called ~ ClapTrap " << this->m_Name << std::endl;
	m_Name = copy.m_Name;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called ~ ClapTrap " << this->m_Name << std::endl;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

ClapTrap& ClapTrap::operator=(ClapTrap& copy)
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
		std::cout << "ClapTrap " << this->m_Name << " recalculates his energy, he has " << this->m_Hit_point << "!" << std::endl;
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
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
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
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
	else
		std::cout << "ClapTrap " << this->m_Name << " is already completely broken, here are his " << this->m_Hit_point << "hp!" << std::endl;
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
}
