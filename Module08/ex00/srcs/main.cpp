/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:30:20 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/29 18:43:16 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

int main(void)
{
    std::cout << "=== Test easyfind ===" << std::endl;

    // Test 1: Vector (random access)
    {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        std::cout << "\nTest 1: vector [10, 20, 30] -> find 20" << std::endl;
        std::vector<int>::const_iterator it = easyfind(vec, 20);
        std::cout << "Find: " << *it << " (position: " << (it - vec.begin()) << ")" << std::endl;
    }

    // Test 2: List (sequential access)
    {
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);

        std::cout << "\nTest 2: list [1, 2, 3] -> find 3" << std::endl;
        std::list<int>::const_iterator it = easyfind(lst, 3);
        std::cout << "Find: " << *it << std::endl;
    }

    // Test 3: Deque (random access)
    {
        std::deque<int> dq;
        dq.push_back(42);
        dq.push_back(21);
        dq.push_back(84);

        std::cout << "\nTest 3: deque [42, 21, 84] -> find 21" << std::endl;
        std::deque<int>::const_iterator it = easyfind(dq, 21);
        std::cout << "Find: " << *it << " (position: " << (it - dq.begin()) << ")" << std::endl;
    }

    // Test 4: Exception else if Find (vector)
    {
        std::vector<int> vec;
        vec.push_back(5);
        vec.push_back(10);

        std::cout << "\nTest 4: vector [5, 10] -> find 99 (must throw an exception)" << std::endl;
        try {
            easyfind(vec, 99);
            std::cout << "ERROR: Should have thrown an exception!" << std::endl;
        }
		catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }

    // Test 5: empty container (list)
    {
        std::list<int> lst;

        std::cout << "\nTest 5: list vide -> find 123 (must throw an exception)" << std::endl;
        try {
            easyfind(lst, 123);
            std::cout << "ERROR: Should have thrown an exception!" << std::endl;
        }
		catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }

    return (0);
}