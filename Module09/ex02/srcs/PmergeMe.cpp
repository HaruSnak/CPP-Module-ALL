/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:06:38 by shmoreno          #+#    #+#             */
/*   Updated: 2025/05/07 22:40:28 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

PmergeMe::PmergeMe(char *argv)
{
	std::cout << "PmergeMe constructor called" << std::endl;
	std::stringstream ss(argv);
	std::string token;
	for (std::string::iterator it = token.begin(); it != token.end(); ++it)
	{
		if (!std::isdigit(*it))
			errorType("Only Numbers !");
	}
	while (ss >> token)
	{
		tmp.push_back(std::atoi(token.c_str()));
	}
	return ;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	std::cout << "PmergeMe constructor copy" << std::endl;
	*this = copy;
	return ;
}

/*------------------------------- DESTRUCTOR --------------------------------*/

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called" << std::endl;
	return ;
}

/*------------------------------- OVERLOAD OPERATOR --------------------------------*/

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

/*------------------------------- FUNCTIONS --------------------------------*/

void	PmergeMe::FordJohnsonSort(void)
{
	for (size_t i = 0; i < this->tmp.size(); i += 2)
	{
		if (this->tmp[i] > this->tmp[i + 1])
			std::swap(this->tmp[i], this->tmp[i + 1]);
	}
	for (size_t i = 1; i < this->tmp.size(); i += 2)
	{
		this->result.push_back(this->tmp[i]);
	}
	this->FordJohnsonSort();
	
}

