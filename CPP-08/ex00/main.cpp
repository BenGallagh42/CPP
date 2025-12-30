#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	// Test1: with vector
    {
		std::cout << "- Test with std::vector -" << std::endl;
        std::vector<int> vec;
        
        // Fill vector with some numbers
        vec.push_back(1);
        vec.push_back(5);
        vec.push_back(10);
        vec.push_back(15);
        vec.push_back(20);
        
        try
        {
            // Search for 10 (should be found)
            std::vector<int>::iterator it = easyfind(vec, 10);
            std::cout << "Found: " << *it << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "Value not found" << std::endl;
        }
        
        try
        {
            // Search for 42 (should NOT be found)
            std::vector<int>::iterator it = easyfind(vec, 42);
            std::cout << "Found: " << *it << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "Value not found" << std::endl;
        }
    }
    
	// Test 2: With list
    {
		std::cout << "\n- Test with std::list -" << std::endl;
        std::list<int> lst;
        
        // Fill list with some numbers
        lst.push_back(100);
        lst.push_back(200);
        lst.push_back(300);
        lst.push_back(400);
        
        try
        {
            // Search for 200 (should be found)
            std::list<int>::iterator it = easyfind(lst, 200);
            std::cout << "Found: " << *it << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "Value not found" << std::endl;
        }
        
        try
        {
            // Search for 999 (should NOT be found)
            std::list<int>::iterator it = easyfind(lst, 999);
            std::cout << "Found: " << *it << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "Value not found" << std::endl;
        }
    }
    
	// Test 3: With deque
    {
		std::cout << "\n- Test with std::deque -" << std::endl;
        std::deque<int> deq;
        
        // Fill deque with some numbers
        deq.push_back(7);
        deq.push_back(14);
        deq.push_back(21);
        deq.push_back(28);
        
        try
        {
            // Search for 21 (should be found)
            std::deque<int>::iterator it = easyfind(deq, 21);
            std::cout << "Found: " << *it << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "Value not found" << std::endl;
        }
    }
    
	// Test 4: empty container
    {
		std::cout << "\n- Test with empty container -" << std::endl;
        std::vector<int> empty_vec;
        
        try
        {
            // Search in empty container (should NOT be found)
            std::vector<int>::iterator it = easyfind(empty_vec, 5);
            std::cout << "Found: " << *it << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "Value not found" << std::endl;
        }
    }

    return (0);
}