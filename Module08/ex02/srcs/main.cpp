/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:15:01 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/18 14:22:06 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.tpp"

void test_empty_array(void)
{
    std::cout << "\n\033[1;36m=== TEST EMPTY ARRAY ===\033[0m\n";
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    try {
        std::cout << "Try access index 0: ";
        std::cout << empty[0] << std::endl;
    }
	catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void test_int_array(void)
{
    std::cout << "\n\033[1;36m=== TEST INT ARRAY ===\033[0m\n";
    Array<int> numbers(5);
    
    for (unsigned int i = 0; i < numbers.size(); ++i)
        numbers[i] = rand() % 100;
    std::cout << "Array content: ";
    for (unsigned int i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << "\nSize: " << numbers.size() << std::endl;
    try {
        std::cout << "Try access index 10: ";
        std::cout << numbers[10] << std::endl;
    }
	catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void test_copy_and_assignment(void)
{
    std::cout << "\n\033[1;36m=== TEST COPY AND ASSIGNMENT ===\033[0m\n";
    Array<std::string> names(3);
    names[0] = "Alice";
    names[1] = "Bob";
    names[2] = "Charlie";
    
    Array<std::string> copy(names);
    copy[1] = "Robert";
    
    Array<std::string> assigned;
    assigned = names;
    assigned[2] = "Charles";
    std::cout << "Original: " << names[0] << " " << names[1] << " " << names[2] << std::endl;
    std::cout << "Copy:     " << copy[0] << " " << copy[1] << " " << copy[2] << std::endl;
    std::cout << "Assigned: " << assigned[0] << " " << assigned[1] << " " << assigned[2] << std::endl;
}

void test_different_types(void)
{
    std::cout << "\n\033[1;36m=== TEST DIFFERENT TYPES ===\033[0m\n";
    
    Array<double> doubles(2);
    doubles[0] = 3.14;
    doubles[1] = 2.718;
    std::cout << "Doubles: " << doubles[0] << ", " << doubles[1] << std::endl;
    
    Array<bool> bools(4);
    bools[0] = true;
    bools[1] = false;
    std::cout << "Bools: " << std::boolalpha << bools[0] << ", " << bools[1] << std::endl;
}

int main(void)
{
    std::cout << "\033[1;35m===== ARRAY TEST SUITE =====\033[0m\n";
    test_empty_array();
    test_int_array();
    test_copy_and_assignment();
    test_different_types();
    
    try {
        Array<int> arr(3);
        arr[3] = 42;
    }
	catch (const std::exception& e) {
        std::cerr << "\nCaught exception: " << e.what() << std::endl;
    }
    return (0);
}