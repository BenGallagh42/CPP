#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "- Test 1: Create valid form -" << std::endl;
    try
    {
        Form form1("Valid form", 50, 25);
        std::cout << form1 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 2: Invalid form (grade too high) -" << std::endl;
    try
    {
        Form invalidForm("Invalid form", 0, 50);
        std::cout << invalidForm << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 3: Invalid form (grade too low) -" << std::endl;
    try
    {
        Form invalidForm("Invalid form", 50, 151);
        std::cout << invalidForm << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 4: Successful signing -" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 30);
        Form form2("Contract", 50, 25);
        
        std::cout << form2 << std::endl;
        bob.signForm(form2);  // Bob's grade (30) is high enough (< 50)
        std::cout << form2 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 5: Failed signing (grade too low) -" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 100);
        Form importantForm("Important Contract", 50, 25);
        
        std::cout << importantForm << std::endl;
        intern.signForm(importantForm);  // Intern's grade (100) is too low (> 50)
        std::cout << importantForm << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 6: Multiple bureaucrats, one form -" << std::endl;
    try
    {
        Form permit("Building Permit", 75, 50);
        Bureaucrat alice("Alice", 100);
        Bureaucrat charlie("Charlie", 50);
        
        std::cout << permit << std::endl;
        
        alice.signForm(permit);    // Will fail
        charlie.signForm(permit);  // Will succeed
        
        std::cout << permit << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}