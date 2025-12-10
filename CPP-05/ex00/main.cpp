#include "Bureaucrat.hpp"

int main()
{
    std::cout << "- Test 1: Valid bureaucrat -" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 2: Grade too high (0) -" << std::endl;
    try
    {
        Bureaucrat invalid("Invalid1", 0);
        std::cout << invalid << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 3: Grade too low (151) -" << std::endl;
    try
    {
        Bureaucrat invalid("Invalid2", 151);
        std::cout << invalid << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;


    std::cout << "- Test 4: Increment grade -" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 2);
        std::cout << alice << std::endl;
        
        alice.incrementGrade();
        std::cout << "After increment: " << alice << std::endl;
        
        alice.incrementGrade();  // This will throw exception (grade 0)
        std::cout << "This won't print" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "- Test 5: Decrement grade -" << std::endl;
    try
    {
        Bureaucrat charlie("Charlie", 149);
        std::cout << charlie << std::endl;
        
        charlie.decrementGrade();
        std::cout << "After decrement: " << charlie << std::endl;
        
        charlie.decrementGrade();  // This will throw exception (grade 151)
        std::cout << "This won't print" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}