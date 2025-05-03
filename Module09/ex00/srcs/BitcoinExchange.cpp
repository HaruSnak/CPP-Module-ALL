#include "../includes/BitcoinExchange.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

BitcoinExchange::BitcoinExchange()
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
	std::ifstream file(this->M_DB_PATH);
	std::string buff;
	size_t occurence;
	if (!file)
	{
		std::cerr << "Error: File access problem or non-existent!" << std::endl;
		std::exit(-1);
	}
	std::getline(file, buff);
	while (std::getline(file, buff))
	{
		occurence = buff.find(',');
		if (occurence != std::string::npos)
		{
			this->m_db.insert(std::make_pair(buff.substr(0, occurence), std::stof(buff.substr(occurence + 1))));
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
	if (!file)
	{
		std::cerr << "Error: File access problem or non-existent!" << std::endl;
		std::exit(-1);
	}
	std::getline(file, buff);
	while (std::getline(file, buff))
	{
		
	}
	return ;
}
