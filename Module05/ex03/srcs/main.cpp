/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:21:53 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 14:42:39 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coffee_making.hpp"

void testWithTryCatch(const std::string& testName, void (*testFunc)())
{
    std::cout << color::COLOR_RED + "\n=== " << testName << " ===" + color::COLOR_NONE << std::endl;
    try
	{
        testFunc();
    }
	catch (const std::exception& e)
	{
        std::cerr << color::COLOR_RED + "❌ Exception: " << e.what() << color::COLOR_NONE << std::endl;
    }
}

void testValidShrubbery(void)
{
    Intern intern;
    AForm* form = intern.makeForm("shrubbery creation", "Garden");
    if (!form)
		throw std::runtime_error("Failed to create shrubbery form");
    Bureaucrat gardener("Gardener", 137);
    gardener.signForm(*form);
    gardener.executeForm(*form);
    delete (form);
}

void testValidRobotomy(void)
{
    Intern intern;
    AForm* form = intern.makeForm("robotomy request", "Bender");
    if (!form)
		throw std::runtime_error("Failed to create robotomy form");
    Bureaucrat surgeon("Surgeon", 45);
    surgeon.signForm(*form);
    surgeon.executeForm(*form);
    delete (form);
}

void testValidPardon(void)
{
    Intern intern;
    AForm* form = intern.makeForm("presidential pardon", "Zaphod");
    if (!form)
		throw std::runtime_error("Failed to create pardon form");
    Bureaucrat president("President", 5);
    president.signForm(*form);
    president.executeForm(*form);
    delete (form);
}

void testInvalidForm(void)
{
    Intern intern;
    AForm* form = intern.makeForm("invalid form", "Target");
    if (form)
	{
        delete (form);
        throw std::runtime_error("Should not have created invalid form");
    }
    color::green("✓ Correctly rejected invalid form");
}

void testEdgeCaseEmptyTarget(void)
{
    Intern intern;
    AForm* form = intern.makeForm("robotomy request", "");
    if (!form)
		throw std::runtime_error("Failed to create form with empty target");
    Bureaucrat b("Tester", 45);
    b.signForm(*form);
    b.executeForm(*form);
    delete (form);
}

int main(void)
{
    testWithTryCatch("Valid Shrubbery Creation", testValidShrubbery);
    testWithTryCatch("Valid Robotomy Request", testValidRobotomy);
    testWithTryCatch("Valid Presidential Pardon", testValidPardon);
    testWithTryCatch("Invalid Form Name", testInvalidForm);
    testWithTryCatch("Empty Target Edge Case", testEdgeCaseEmptyTarget);
    std::cout << "\n=== TESTS COMPLETED ===" << std::endl;
    return (0);
}