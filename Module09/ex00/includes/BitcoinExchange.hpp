/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:24:31 by shmoreno          #+#    #+#             */
/*   Updated: 2025/05/05 14:43:59 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <cstring>
# include <cmath>
# include <limits>
# include <cstdlib>
# include "exchange.hpp"

class BitcoinExchange
{
	private:
		const std::string M_DB_PATH;
		std::map<std::string, float> m_DB;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& copy);
		void	createDB(void);
		void	searchInDB(char *argv);
		int		findErrors(const std::string& key, const std::string& value);
};

#endif
