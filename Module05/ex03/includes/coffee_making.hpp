/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coffee_making.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:34:58 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 14:34:59 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COFFEE_MAKING_HPP
# define COFFEE_MAKING_HPP

# include <string>
# include <iostream>
# include "../includes/Bureaucrat.hpp"
# include "../includes/PresidentialPardonForm.hpp"
# include "../includes/RobotomyRequestForm.hpp"
# include "../includes/ShrubberyCreationForm.hpp"
# include "../includes/Intern.hpp"

namespace	color
{
	const std::string COLOR_RED = "\033[31m";
	const std::string COLOR_GREEN = "\033[32m";
	const std::string COLOR_NONE = "\033[0m";
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
