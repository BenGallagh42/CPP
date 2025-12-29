#include "iter.hpp"
#include <iostream>
#include <string>

// Template function to print an element (const: read-only)
template <typename T>
void print(const T& element)
{
    std::cout << element << " ";
}

// Template function to increment a number (non-const: modifies)
template <typename T>
void increment(T& element)
{
    element++;
}

// Function to convert char to uppercase
void toUpper(char& c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 32;
}

int main(void)
{
    std::cout << "- Test 1: Integer array -" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = 5;
    
    std::cout << "Before increment: ";
    ::iter(intArray, intLen, print<int>);
    std::cout << std::endl;
    
    ::iter(intArray, intLen, increment<int>);
    
    std::cout << "After increment: ";
    ::iter(intArray, intLen, print<int>);
    std::cout << std::endl << std::endl;
    
    std::cout << "- Test 2: String array -" << std::endl;
    std::string strArray[] = {"Hello", "World", "42", "School"};
    size_t strLen = 4;
    
    std::cout << "Strings: ";
    ::iter(strArray, strLen, print<std::string>);
    std::cout << std::endl << std::endl;
    
    std::cout << "- Test 3: Double array -" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    size_t doubleLen = 4;
    
    std::cout << "Before increment: ";
    ::iter(doubleArray, doubleLen, print<double>);
    std::cout << std::endl;
    
    ::iter(doubleArray, doubleLen, increment<double>);
    
    std::cout << "After increment: ";
    ::iter(doubleArray, doubleLen, print<double>);
    std::cout << std::endl << std::endl;
    
    std::cout << "- Test 4: Char array -" << std::endl;
    char charArray[] = {'h', 'e', 'l', 'l', 'o'};
    size_t charLen = 5;
    
    std::cout << "Before toUpper: ";
    ::iter(charArray, charLen, print<char>);
    std::cout << std::endl;
    
    ::iter(charArray, charLen, toUpper);
    
    std::cout << "After toUpper: ";
    ::iter(charArray, charLen, print<char>);
    std::cout << std::endl;
    
    return 0;
}