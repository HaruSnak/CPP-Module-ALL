/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:16:27 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/17 14:20:59 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/form_28B.hpp"

void testSuccessfulShrubbery(void)
{
    color::red("\n=== TEST ShrubberyCreationForm (SUCCESS) ===");
    try
	{
        Bureaucrat gardener("Master Gardener", 130);
        ShrubberyCreationForm garden("SecretGarden");

        gardener.signForm(garden);
        gardener.executeForm(garden);
        color::green("✓ Successfully created shrubbery file\n");
    }
	catch (const std::exception& e)
	{
        std::cerr << color::"✗ Unexpected error: " << e.what() << color::COLOR_NONE << std::endl;
    }
}

void testSuccessfulRobotomy(void)
{
    color::red("\n=== TEST RobotomyRequestForm (SUCCESS) ===");
    try
	{
        Bureaucrat surgeon("Dr. Robot", 30);
        RobotomyRequestForm patient("Bender");
        
        surgeon.signForm(patient);
        surgeon.executeForm(patient);
        color::green("✓ Robotomy procedure completed\n");
    }
	catch (const std::exception& e)
	{
        std::cerr << color::"✗ Unexpected error: " << e.what() << color::COLOR_NONE << std::endl;
    }
}

void testSuccessfulPardon(void)
{
    color::red("\n=== TEST PresidentialPardonForm (SUCCESS) ===");
    try
	{
        Bureaucrat president("Zaphod Beeblebrox", 1);
        PresidentialPardonForm convict("Marvin");
        
        president.signForm(convict);
        president.executeForm(convict);
        color::green("✓ Presidential pardon granted\n");
    }
	catch (const std::exception& e)
	{
        std::cerr << color::"✗ Unexpected error: " << e.what() << color::COLOR_NONE << std::endl;
    }
}

void testEdgeCases(void)
{
    color::red("\n=== EDGE CASE TESTS ===");
    try
	{
        Bureaucrat exactGrade("Precision Worker", 137);
        ShrubberyCreationForm exactForm("PrecisionGarden");
        
        exactGrade.signForm(exactForm);
        exactGrade.executeForm(exactForm);
        color::green("✓ Exact grade requirement test passed\n");
    }
	catch (const std::exception& e)
	{
        std::cerr << color::"✗ Exact grade test failed: " << e.what() << color::COLOR_NONE << std::endl;
    }
}

void testFailureCases(void)
{
    color::red("\n=== FAILURE TESTS (EXPECTED ERRORS) ===");
    
    try
	{
        Bureaucrat clerk("Junior Clerk", 140);
        ShrubberyCreationForm form("Backyard");
        
        clerk.executeForm(form);
        color::red("✗ Unexpected success - should have failed (unsigned form)\n");
    }
	catch (const std::exception& e)
	{
        std::cerr << color::COLOR_GREEN + "✓ Properly caught unsigned form error: " << e.what() << color::COLOR_NONE << std::endl;
    }
    try
	{
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm pardon("Nobody");
        
        intern.signForm(pardon);
        intern.executeForm(pardon);
        color::red("✗ Unexpected success - should have failed (grade too low)\n");
    }
	catch (const std::exception& e)
	{
        std::cerr << color::COLOR_GREEN + "✓ Properly caught grade requirement error: " << e.what() << color::COLOR_NONE << std::endl;
    }
}

int main(void)
{
    try
	{
        testSuccessfulShrubbery();
        testSuccessfulRobotomy();
        testSuccessfulPardon();
        testEdgeCases();
        testFailureCases();
    }
	catch (...)
	{
        color::err_red("UNHANDLED EXCEPTION IN MAIN");
        return (EXIT_FAILURE);
    }
    color::red("\n\033[1;32m=== ALL TESTS COMPLETED ===");
    return (EXIT_SUCCESS);
}