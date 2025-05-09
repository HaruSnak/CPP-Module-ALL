/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:06:30 by shmoreno          #+#    #+#             */
/*   Updated: 2025/05/09 20:28:07 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <deque>
# include <algorithm>
# include <ctime>
# include "utils.hpp"

class PmergeMe
{
	private:
		std::vector<int> result_vec;
		std::deque<int> result_deq;
	public:
		PmergeMe(char *argv[]);
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& copy);
		void	printSort(void);
};

#endif
