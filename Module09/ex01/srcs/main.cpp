/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:12:41 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/29 18:40:27 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

// Main test that comes from the subject
/*int main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}*/

int main(void)
{
    std::cout << "=== Basic Test (given example) ===" << std::endl;
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << "\n=== Basic Test 2 ===" << std::endl;
    {
        Span sp(10);
        sp.addNumber(600);
        sp.addNumber(17);
        sp.addNumber(0);
        sp.addNumber(9);
        sp.addNumber(35);
        sp.addNumber(60);
        sp.addNumber(55);
        sp.addNumber(16);
        sp.addNumber(1);
        sp.addNumber(61);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << "\n=== Error Test: Adding too many numbers ===" << std::endl;
    {
        Span sp(3);
        try {
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3);
            sp.addNumber(4);
            std::cout << "Error: No exception thrown!" << std::endl;
        }
		catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== Error Test: Span calculation with <2 numbers ===" << std::endl;
    {
        Span sp(5);
        sp.addNumber(42);

        try {
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << "Error: No exception thrown!" << std::endl;
        }
		catch (const std::exception& e) {
            std::cout << "Caught exception (shortestSpan): " << e.what() << std::endl;
        }

        try {
            std::cout << sp.longestSpan() << std::endl;
            std::cout << "Error: No exception thrown!" << std::endl;
        }
		catch (const std::exception& e) {
            std::cout << "Caught exception (longestSpan): " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== Large Scale Test (10,000 numbers) ===" << std::endl;
    {
        Span sp(10000);
        std::vector<int> numbers;

        for (int i = 0; i < 10000; ++i) {
            numbers.push_back(rand() % 1000000);
        }
        sp.addNumbers(numbers.begin(), numbers.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << "\n=== Iterator Range Test ===" << std::endl;
    {
        Span sp(10);
        int array[] = {5, 10, 15, 20, 25};

        std::vector<int> vec(array, array + 5);
        sp.addNumbers(vec.begin(), vec.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << "\n=== Edge Case: Identical numbers ===" << std::endl;
    {
        Span sp(4);
        sp.addNumber(5);
        sp.addNumber(5);
        sp.addNumber(5);
        sp.addNumber(5);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    return (0);
}