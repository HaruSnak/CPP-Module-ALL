/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:07:08 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 12:14:22 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/form_up.hpp"

void testFormCreation(void)
{
    std::cout << "\n\033[1;36m=== TEST FORM CREATION ===\033[0m" << std::endl;
    try {
        Form taxForm("Tax Return", 50, 30);
        std::cout << taxForm << std::endl;
        Form topSecret("Top Secret", 1, 1);
        std::cout << topSecret << std::endl;
        Form invalid("Test", 0, 150);
    }
	catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void testFormSigning(void)
{
    std::cout << "\n\033[1;36m=== TEST FORM SIGNING ===\033[0m" << std::endl;
    try {
        Bureaucrat boss("CEO", 1);
        Bureaucrat intern("Intern", 150);

        Form important("Important Document", 10, 5);
        std::cout << important << std::endl;

        boss.signForm(important);
        std::cout << important << std::endl;

        Form confidential("Confidential", 50, 40);
        intern.signForm(confidential);

    }
	catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
}

void testEdgeCases(void)
{
    std::cout << "\n\033[1;36m=== TEST EDGE CASES ===\033[0m" << std::endl;
    try {
        Bureaucrat midLevel("Manager", 75);
        Form edgeForm("Edge Case", 75, 75);

        midLevel.signForm(edgeForm);
        std::cout << edgeForm << std::endl;
        midLevel.signForm(edgeForm);
    }
	catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void testCopyAndAssignment(void)
{
    std::cout << "\n\033[1;36m=== TEST COPY/ASSIGNMENT ===\033[0m" << std::endl;
    Form original("Original", 25, 25);
    Form copy(original);
    Form assigned("Temporary", 50, 50);
    assigned = original;
    std::cout << "Original: " << original << std::endl;
    std::cout << "Copy: " << copy << std::endl;
    std::cout << "Assigned: " << assigned << std::endl;
}

int main(void)
{
    std::cout << "===== FORM TEST SUITE =====\033[0m" << std::endl;

    testFormCreation();
    testFormSigning();
    testEdgeCases();
    testCopyAndAssignment();

    try {
        Bureaucrat b("Tester", 100);
        Form f("Test Form", 99, 99);
        b.signForm(f);
    }
	catch (const std::exception& e) {
        std::cerr << "\nCaught in generic catch: " << e.what() << std::endl;
    }
    return (0);
}