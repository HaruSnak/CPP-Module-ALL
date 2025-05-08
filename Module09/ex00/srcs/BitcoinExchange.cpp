/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:52:30 by shmoreno          #+#    #+#             */
/*   Updated: 2025/05/05 14:55:43 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

BitcoinExchange::BitcoinExchange() : M_DB_PATH("data.csv")
{
	std::cout << "BitcoinExchange constructor called" << std::endl;
	this->createDB();
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	std::cout << "BitcoinExchange constructor copy" << std::endl;
	*this = copy;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

void	BitcoinExchange::createDB(void)
{
	std::ifstream file(this->M_DB_PATH.c_str());
	std::string buff;
	char *endptr;
	size_t occurence;
	if (!file)
		errorType("File access problem or non-existent!");
	std::getline(file, buff);
	while (std::getline(file, buff))
	{
		occurence = buff.find(',');
		if (occurence != std::string::npos)
		{
			this->m_DB.insert(std::make_pair(buff.substr(0, occurence), std::strtof(buff.substr(occurence + 1).c_str(), &endptr)));
		}
		else
			continue;
	}
	file.close();
	return ;
}

void	BitcoinExchange::searchInDB(char *argv)
{
	std::ifstream file(argv);
	std::string buff;
	size_t occurence;
	if (!file)
		errorType("File access problem or non-existent!");
	std::getline(file, buff);
	while (std::getline(file, buff))
	{
		occurence = buff.find('|');
		if (occurence == std::string::npos)
		{
			color::err_red("bad input => " + buff);
			continue ;
		}
		std::string key = buff.substr(0, occurence);
		std::string key_value = buff.substr(occurence + 1);
		key.erase(key.find_last_not_of(" \t") + 1);
		key_value.erase(0, key_value.find_first_not_of(" \t"));
		if (this->findErrors(key, key_value) != 0) continue ;
		std::map<std::string, float>::iterator it = this->m_DB.lower_bound(key);
		if (it != this->m_DB.end() && it->first == key)
		{
			if (it->first == key)
				std::cout << key << " => " << key_value << " = " << (std::strtof(key_value.c_str(), NULL) * it->second) << std::endl;
			else
			{
				it--;
				std::cout << key << " => " << key_value << " = " << (std::strtof(key_value.c_str(), NULL) * it->second) << std::endl;
			}
		}
		else
		{
			it--;
			std::cout << key << " => " << key_value << " = " << (std::strtof(key_value.c_str(), NULL) * it->second) << std::endl;
		}
	}
	file.close();
	return ;
}

int BitcoinExchange::findErrors(const std::string& key, const std::string& value)
{
	char* endptr;
	float val_brut = std::strtof(value.c_str(), &endptr);

	if (*endptr != '\0')
	{
		color::err_red("Invalid value for float.");
		return (-1);
	}
	else if (key.size() != 10 || key[4] != '-' || key[7] != '-')
	{
		color::err_red("Invalid date (YYYY-MM-DD)");
		return (-1);
	}
	else if (val_brut < 0.0f)
	{
		color::err_red("Not a positive number.");
		return (-1);
	}
	else if (isFloat(val_brut) && (val_brut < 0 || val_brut > 1000))
	{
		color::err_red("Error: Float value exceeding maximum or minimum limits.");
		return (-1);
	}
	else if (!isFloat(val_brut) && (val_brut < 0 || val_brut > 1000))
	{
		color::err_red("Value exceeding maximum or minimum limits. 0 <=> 1000");
		return (-1);
	}
	else
	{
		for (size_t i = 0; i < key.size(); ++i)
		{
			if ((i == 4 || i == 7) && key[i] != '-')
			{
				color::err_red("Invalid date (YYYY-MM-DD)");
				return (-1);
			}
			else if (i != 4 && i != 7 && !std::isdigit(key[i]))
			{
				color::err_red("Invalid date (YYYY-MM-DD)");
				return (-1);
			}
		}
	}
	return (0);
}
