/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:10:23 by shmoreno          #+#    #+#             */
/*   Updated: 2025/05/09 21:10:24 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string>
# include <iostream>
# include "../includes/Serializer.hpp"

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
	static inline std::ostream &mix_rg(const std::string &src)
	{
		return (std::cout << COLOR_RED << src << COLOR_GREEN);
	}
}

#endif
