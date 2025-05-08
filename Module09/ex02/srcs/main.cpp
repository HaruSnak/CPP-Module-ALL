/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:15:01 by shmoreno          #+#    #+#             */
/*   Updated: 2025/05/07 17:52:23 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Only one argument is valid, it must be a file containing a Database!" << std::endl;
		return (-1);
	}
	PmergeMe johnson;
	try
	{
		std::cout << rpn.ResultRPN(argv[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    return (0);
}