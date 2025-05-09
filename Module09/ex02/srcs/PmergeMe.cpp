/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:06:38 by shmoreno          #+#    #+#             */
/*   Updated: 2025/05/09 21:00:11 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/*------------------------------- CONSTRUCTOR --------------------------------*/

PmergeMe::PmergeMe(char *argv[])
{
	std::cout << "PmergeMe constructor called" << std::endl;
	for (size_t i = 1; argv[i] != NULL; i++)
	{
		for (size_t k = 0; argv[i][k] != '\0'; k++)
		{
			if (argv[i][k] < '0' || argv[i][k] > '9')
				errorType("Only Numbers !");
		}
	}
	std::cout << "Before: ";
	for (size_t i = 1; argv[i] != NULL; i++)
	{
		std::cout << argv[i] << " ";
		this->result_vec.push_back(std::atoi(argv[i]));
		this->result_deq.push_back(std::atoi(argv[i]));
	}
	std::cout << std::endl;
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
template<typename Container>
void binaryInsert(Container& sorted, int value)
{
	typename Container::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
	return ;
}

template<typename Container>
Container fordJohnsonSort(Container& input)
{
    Container bigs;
    Container smalls;
    size_t n = input.size();

    if (n <= 1)
        return input;
    size_t i = 0;
    for (; i + 1 < n; i += 2)
	{
        if (input[i] < input[i + 1])
		{
            bigs.push_back(input[i + 1]);
            smalls.push_back(input[i]);
        }
		else
		{
            bigs.push_back(input[i]);
            smalls.push_back(input[i + 1]);
        }
    }
    bool hasOdd = (n % 2 != 0);
    int lastOdd = 0;
    if (hasOdd)
        lastOdd = input[n - 1];
    Container sorted = fordJohnsonSort(bigs);
    for (size_t j = 0; j < smalls.size(); ++j) 
        binaryInsert(sorted, smalls[j]);
    if (hasOdd)
        binaryInsert(sorted, lastOdd);
    return (sorted);
}

void	PmergeMe::printSort(void)
{
	clock_t start = clock();
	this->result_vec = fordJohnsonSort(this->result_vec);
	clock_t end = clock();
	double durationVec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	start = clock();
	this->result_deq = fordJohnsonSort(this->result_deq);
	end = clock();
	double durationDeq = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "After: ";
	for (size_t i = 0; i < this->result_vec.size() || i < this->result_deq.size(); i++)
	{
		std::cout << result_vec[i] << " ";
	}
	std::cout << std::endl << "Time to process a range of " << result_vec.size() <<  " elements with std::vector : " << durationVec << " us" << std::endl;
	std::cout << "Time to process a range of " << result_deq.size() <<  " elements with std::deque : " << durationDeq << " us" << std::endl;
	return ;
}