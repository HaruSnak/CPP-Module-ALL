#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iostream>
# include "../includes/ClapTrap.hpp"
# include "../includes/ScavTrap.hpp"
# include "../includes/FragTrap.hpp"

namespace	color
{
	const std::string COLOR_RED = "\033[31m";
	const std::string COLOR_GREEN = "\033[32m";
	const std::string COLOR_NONE = "\033[0m";
	const std::string COLOR_YELLOW = "\033[33m";
	const std::string COLOR_BLUE ="\033[34m";
	const std::string COLOR_MAGENTA = "\033[35m";
	const std::string COLOR_CYAN = "\033[36m";
	static inline std::ostream &red(const std::string &src)
	{
		return (std::cout << COLOR_RED << src << COLOR_NONE << std::endl);
	}
	static inline std::ostream &err_red(const std::string &src)
	{
		return (std::cerr << COLOR_RED << src << COLOR_NONE << std::endl);
	}
	static inline std::ostream &green(const std::string &src)
	{
		return (std::cout << COLOR_GREEN << src << COLOR_NONE << std::endl);
	}
	static inline std::ostream &err_green(const std::string &src)
	{
		return (std::cerr << COLOR_GREEN << src << COLOR_NONE << std::endl);
	}
}

#endif
