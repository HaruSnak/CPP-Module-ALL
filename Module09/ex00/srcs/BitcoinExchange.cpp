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
	this->m_DB = copy.m_DB;
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
		this->m_DB = copy.m_DB;
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
		if (!this->findErrors(key, key_value)) continue ;
		float value = std::strtof(key_value.c_str(), NULL);
		std::map<std::string, float>::iterator it = this->m_DB.lower_bound(key);
        if (it != this->m_DB.end() && it->first == key)
        {
            std::cout << key << " => " << key_value << " = " << (value * it->second) << std::endl;
        }
        else if (it != this->m_DB.begin())
        {
            --it;
            std::cout << key << " => " << key_value << " = " << (value * it->second) << std::endl;
        }
        else
            std::cout << "Error: no earlier date available." << std::endl;
	}
	file.close();
	return ;
}

bool	BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false); 
	for (size_t i = 0; i < date.size(); ++i)
	{
		if ((i == 4 || i == 7) && date[i] != '-') return (false);
		else if (i != 4 && i != 7 && !std::isdigit(date[i])) return (false);
	}
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 1000 || year > 9999) return (false);
    if (month < 1 || month > 12) return (false);
    if (day < 1 || day > 31) return (false);
    return (true);
}

bool	BitcoinExchange::findErrors(const std::string& key, const std::string& value)
{
	char* endptr;
	float val_brut = std::strtof(value.c_str(), &endptr);

	if (!this->isValidDate(key))
	{
        color::err_red("Error: bad input => " + key);
		return (false);
	}
	else if (*endptr != '\0')
	{
        color::err_red("Error: bad input => " + key);
		return (false);
	}
	else if (val_brut < 0.0f)
	{
        color::err_red("Error: not a positive number.");
		return (false);
	}
	else if (val_brut > 1000.0f)
	{
        color::err_red("Error: too large a number.");
		return (false);
	}
	return (true);
}
