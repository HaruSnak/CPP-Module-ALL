/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:49:55 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 14:20:59 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/exception.hpp"

void testBasicCreation(void)
{
    color::red("===== TEST BASIC CREATION =====");
    try {
        Bureaucrat normal("John", 50);
        std::cout << color::COLOR_GREEN << normal << color::COLOR_NONE << std::endl;

        Bureaucrat highest("Boss", 1);
        std::cout << color::COLOR_GREEN << highest << color::COLOR_NONE  << std::endl;

        Bureaucrat lowest("Intern", 150);
        std::cout << color::COLOR_GREEN << lowest << color::COLOR_NONE  << std::endl;
    }
	catch (const std::exception& e) {
        std::cerr << color::"Error: " << e.what() << color::COLOR_NONE << std::endl;
    }
}

void testInvalidGrades(void)
{
    color::red("\n===== TEST INVALID GRADES =====");
    try {
        Bureaucrat tooHigh("Error", 0);
    }
	catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << color::"Caught GradeTooHigh: " << e.what() << color::COLOR_NONE << std::endl;
    }

    try {
        Bureaucrat tooLow("Error", 151);
    }
	catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << color::COLOR_RED +  "Caught GradeTooLow: " << e.what() << color::COLOR_NONE << std::endl;
    }
}

void testGradeModification(void)
{
    color::red("\n===== TEST GRADE MODIFICATION =====");
    try {
        Bureaucrat b("Alice", 3);
        std::cout << color::COLOR_GREEN + "Before: " + color::COLOR_RED << b << std::endl;

        b.incrementGrade();
        std::cout << color::COLOR_GREEN + "After increment: " + color::COLOR_RED << b << std::endl;

        b.decrementGrade();
        std::cout << color::COLOR_GREEN + "After decrement: " + color::COLOR_RED << b << color::COLOR_NONE << std::endl;

        // Test edge cases
        Bureaucrat top("CEO", 1);
        top.incrementGrade();

    }
	catch (const std::exception& e) {
        std::cerr << color::"Error: " << e.what() << color::COLOR_NONE << std::endl;
    }
}

void testCopyAndAssignment(void)
{
    color::red("\n===== TEST COPY AND ASSIGNMENT =====");
    Bureaucrat original("Original", 10);
    Bureaucrat copy(original);
    Bureaucrat assigned("Temporary", 20);

    assigned = original;

    std::cout << color::COLOR_GREEN + "Original: " + color::COLOR_RED << original << std::endl;
    std::cout << color::COLOR_GREEN + "Copy: " + color::COLOR_RED << copy << std::endl;
    std::cout << color::COLOR_GREEN + "Assigned: " + color::COLOR_RED << assigned << color::COLOR_NONE << std::endl;
}

int main(void)
{
    testBasicCreation();
    testInvalidGrades();
    testGradeModification();
    testCopyAndAssignment();

    try {
        Bureaucrat b("Test", 100);
        for (int i = 0; i < 200; i++)
            b.decrementGrade();
    }
	catch (const std::exception& e) {
        std::cerr << color::"\nCaught in generic catch: " << e.what() << color::COLOR_NONE << std::endl;
    }
    return (0);
}