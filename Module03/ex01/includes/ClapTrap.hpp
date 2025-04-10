#ifndef ClapTrap_HPP
# define ClapTrap_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class ClapTrap
{
	protected:
		std::string m_Name;
		int m_Hit_point;
		int m_Energy_point;
		int m_Attack_damage;

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();
		ClapTrap& operator=(ClapTrap& copy);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
