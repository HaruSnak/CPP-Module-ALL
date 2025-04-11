#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

void testSuccessfulShrubbery() {
    std::cout << "\n\033[1;36m=== TEST ShrubberyCreationForm (SUCCESS) ===COLOR_RED + " << std::endl;
    try
	{
        Bureaucrat gardener("Master Gardener", 130);
        ShrubberyCreationForm garden("SecretGarden");

        gardener.signForm(garden);
        gardener.executeForm(garden);
        std::cout << "✓ Successfully created shrubbery file\n";
    } catch (const std::exception& e)
	{
        std::cerr << "✗ Unexpected error: " << e.what() << std::endl;
    }
}

void testSuccessfulRobotomy() {
    std::cout << "\n\033[1;36m=== TEST RobotomyRequestForm (SUCCESS) ===COLOR_RED + " << std::endl;
    try
	{
        Bureaucrat surgeon("Dr. Robot", 30);
        RobotomyRequestForm patient("Bender");
        
        surgeon.signForm(patient);
        surgeon.executeForm(patient);
        std::cout << "✓ Robotomy procedure completed\n";
    } catch (const std::exception& e)
	{
        std::cerr << "✗ Unexpected error: " << e.what() << std::endl;
    }
}

void testSuccessfulPardon() {
    std::cout << "\n\033[1;36m=== TEST PresidentialPardonForm (SUCCESS) ===COLOR_RED + " << std::endl;
    try
	{
        Bureaucrat president("Zaphod Beeblebrox", 1);
        PresidentialPardonForm convict("Marvin");
        
        president.signForm(convict);
        president.executeForm(convict);
        std::cout << "✓ Presidential pardon granted\n";
    } catch (const std::exception& e)
	{
        std::cerr << "✗ Unexpected error: " << e.what() << std::endl;
    }
}

void testEdgeCases() {
    std::cout << "\n\033[1;36m=== EDGE CASE TESTS ===COLOR_RED + " << std::endl;
    
    // Test: Exact minimum grade for execution
    try
	{
        Bureaucrat exactGrade("Precision Worker", 137);
        ShrubberyCreationForm exactForm("PrecisionGarden");
        
        exactGrade.signForm(exactForm);
        exactGrade.executeForm(exactForm);
        std::cout << "✓ Exact grade requirement test passed\n";
    } catch (const std::exception& e)
	{
        std::cerr << "✗ Exact grade test failed: " << e.what() << std::endl;
    }
}

void testFailureCases() {
    std::cout << "\n\033[1;36m=== FAILURE TESTS (EXPECTED ERRORS) ===COLOR_RED + " << std::endl;
    
    // Test: Unsigned form execution
    try
	{
        Bureaucrat clerk("Junior Clerk", 140);
        ShrubberyCreationForm form("Backyard");
        
        clerk.executeForm(form);
        std::cerr << "✗ Unexpected success - should have failed (unsigned form)\n";
    } catch (const std::exception& e)
	{
        std::cout << "✓ Properly caught unsigned form error: " << e.what() << std::endl;
    }
    
    // Test: Grade too low for execution
    try
	{
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm pardon("Nobody");
        
        intern.signForm(pardon);
        intern.executeForm(pardon);
        std::cerr << "✗ Unexpected success - should have failed (grade too low)\n";
    } catch (const std::exception& e)
	{
        std::cout << "✓ Properly caught grade requirement error: " << e.what() << std::endl;
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
    } catch (...)
	{
        std::cerr << "\033[1;31mUNHANDLED EXCEPTION IN MAINCOLOR_RED + " << std::endl;
        return (EXIT_FAILURE);
    }

    std::cout << "\n\033[1;32m=== ALL TESTS COMPLETED ===COLOR_RED + " << std::endl;
    return (EXIT_SUCCESS);
}