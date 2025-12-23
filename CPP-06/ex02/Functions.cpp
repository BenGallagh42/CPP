#include "Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Randomly instantiates A, B, or C
Base* generate(void)
{
    // Seed random number generator with current time
    std::srand(std::time(0));
    
    int random = std::rand() % 3;
    
    if (random == 0)
    {
        std::cout << "Generated: A" << std::endl;
        return new A();
    }
    else if (random == 1)
    {
        std::cout << "Generated: B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "Generated: C" << std::endl;
        return new C();
    }
}

// Identify type using pointer
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// Identify type and throws exception if cast fails
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p); // Void because we don't store the result
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception&) {}
    
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception&) {}
    
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception&) {}
    
    std::cout << "Unknown type" << std::endl;
}