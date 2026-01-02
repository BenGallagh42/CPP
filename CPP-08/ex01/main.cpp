#include <iostream>
#include "Span.hpp"

int main()
{
    // Test from subject
    {
        std::cout << "- Test from subject -" << std::endl;
        Span sp = Span(5);
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    // Test with exception (too many numbers)
    {
        std::cout << "\n- Test exception (full) -" << std::endl;
        Span sp = Span(3);
        
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        
        try
        {
            sp.addNumber(4);
        }
        catch (std::exception& e)
        {
            std::cout << "Cannot add more numbers" << std::endl;
        }
    }

    // Test with not enough numbers
    {
        std::cout << "\n- Test exception (not enough numbers) -" << std::endl;
        Span sp = Span(5);
        
        sp.addNumber(42);
        
        try
        {
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "Not enough numbers for span" << std::endl;
        }
    }

    // Test with 10,000 numbers using addRange
    {
        std::cout << "\n- Test with 10,000 numbers -" << std::endl;
        Span sp = Span(10000);
        
        std::vector<int> numbers;
		// Fill the vector with pair numbers
        for (int i = 0; i < 10000; i++)
        {
            numbers.push_back(i * 2);
        }
        // Iterate through the vector and add numbers to the class object
        sp.addRange(numbers.begin(), numbers.end());
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    return (0);
}