#include "Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
	// Test 1 : empty array
    std::cout << "- Test 1: Empty array -" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    std::cout << std::endl;
    
	// Test 2 . Int array
    std::cout << "- Test 2: Integer array -" << std::endl;
    Array<int> intArray(5);
    std::cout << "Created array of size: " << intArray.size() << std::endl;
    
    std::cout << "Default values: ";
    for (unsigned int i = 0; i < intArray.size(); i++)
        std::cout << intArray[i] << " ";
    std::cout << std::endl;
    
    std::cout << "Setting values..." << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++)
        intArray[i] = i * 10;
    
    std::cout << "New values: ";
    for (unsigned int i = 0; i < intArray.size(); i++)
        std::cout << intArray[i] << " ";
    std::cout << std::endl << std::endl;
    
	// Test 3 : copy constructor
    std::cout << "- Test 3: Copy constructor -" << std::endl;
    Array<int> copy(intArray);
    std::cout << "Copy size: " << copy.size() << std::endl;
    std::cout << "Copy values: ";
    for (unsigned int i = 0; i < copy.size(); i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;
    
    std::cout << "Modifying original array..." << std::endl;
    intArray[0] = 999;
    std::cout << "Original[0]: " << intArray[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;
    std::cout << "(Should be different - deep copy)" << std::endl << std::endl;
    
	// Test 4 : assignment operator
    std::cout << "- Test 4: Assignment operator -" << std::endl;
    Array<int> assigned;
    assigned = intArray;
    std::cout << "Assigned size: " << assigned.size() << std::endl;
    std::cout << "Assigned values: ";
    for (unsigned int i = 0; i < assigned.size(); i++)
        std::cout << assigned[i] << " ";
    std::cout << std::endl << std::endl;
    
	// Test 5 : string array
    std::cout << "- Test 5: String array -" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "42";
    
    std::cout << "String array: ";
    for (unsigned int i = 0; i < strArray.size(); i++)
        std::cout << strArray[i] << " ";
    std::cout << std::endl << std::endl;
    
	// Test 6 : out of bounds error
    std::cout << "- Test 6: Out of bounds exception -" << std::endl;
    try {
        std::cout << "Trying to access index 10 (size is 5)..." << std::endl;
        std::cout << intArray[10] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: index out of bounds" << std::endl;
    }
    
    try {
        std::cout << "Trying to access index 0 of empty array..." << std::endl;
        std::cout << empty[0] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: index out of bounds" << std::endl;
    }
    
    return 0;
}