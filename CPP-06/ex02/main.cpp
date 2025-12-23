#include "Functions.hpp"
#include <iostream>

int main()
{
    Base* ptr = generate();
    std::cout << std::endl;
    
    std::cout << "Identify by pointer: ";
    identify(ptr);
    
    std::cout << "Identify by reference: ";
    identify(*ptr);
        
    delete ptr;
    
    return 0;
}