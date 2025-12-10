#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "- Test 1: Intern creates RobotomyRequestForm -" << std::endl;
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        std::cout << *rrf << std::endl;
        
        // Use the form
        Bureaucrat bob("Bob", 1);
        bob.signForm(*rrf);
        bob.executeForm(*rrf);
        
        delete rrf;  // Important: free allocated memory
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 2: Intern creates ShrubberyCreationForm -" << std::endl;
    try
    {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("shrubbery creation", "garden");
        
        Bureaucrat alice("Alice", 1);
        alice.signForm(*form);
        alice.executeForm(*form);
        
        delete form;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 3: Intern creates PresidentialPardonForm -" << std::endl;
    try
    {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("presidential pardon", "Criminal");
        
        Bureaucrat president("President", 1);
        president.signForm(*form);
        president.executeForm(*form);
        
        delete form;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 4: Unknown form type -" << std::endl;
    try
    {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("unknown form", "target");
        
        // This won't be reached
        delete form;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 5: Create all three forms -" << std::endl;
    try
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        
        AForm* form1 = intern.makeForm("shrubbery creation", "home");
        AForm* form2 = intern.makeForm("robotomy request", "target1");
        AForm* form3 = intern.makeForm("presidential pardon", "target2");
        
        boss.signForm(*form1);
        boss.signForm(*form2);
        boss.signForm(*form3);
        
        boss.executeForm(*form1);
        boss.executeForm(*form2);
        boss.executeForm(*form3);
        
        // Clean up
        delete form1;
        delete form2;
        delete form3;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 6: Case sensitivity test -" << std::endl;
    try
    {
        Intern intern;
        AForm* form;
        
        // Try with uppercase (should fail)
        form = intern.makeForm("Robotomy Request", "target");
        
        delete form;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}