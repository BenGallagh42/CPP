#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "- Test 1: ShrubberyCreationForm -" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 137);
        ShrubberyCreationForm shrub("home");
        
        std::cout << shrub << std::endl;
        bob.signForm(shrub);
        bob.executeForm(shrub);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 2: Execute without signing -" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 1);
        ShrubberyCreationForm shrub("garden");
        
        alice.executeForm(shrub);  // Should fail: not signed
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 3: RobotomyRequestForm -" << std::endl;
    try
    {
        Bureaucrat charlie("Charlie", 45);
        RobotomyRequestForm robot("Bender");
        
        std::cout << robot << std::endl;
        charlie.signForm(robot);
        charlie.executeForm(robot);
        charlie.executeForm(robot);  // Try again to see different result
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 4: PresidentialPardonForm -" << std::endl;
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << pardon << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 5: Grade too low to execute -" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 50);
        PresidentialPardonForm pardon("Someone");
        
        intern.signForm(pardon);   // Can sign (grade 25 required)
        intern.executeForm(pardon);  // Cannot execute (grade 5 required)
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 6: All forms with single bureaucrat -" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        
        ShrubberyCreationForm shrub("office");
        RobotomyRequestForm robot("Employee");
        PresidentialPardonForm pardon("Criminal");
        
        boss.signForm(shrub);
        boss.signForm(robot);
        boss.signForm(pardon);
        
        boss.executeForm(shrub);
        boss.executeForm(robot);
        boss.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}