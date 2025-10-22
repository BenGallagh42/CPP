#include <iostream>
#include "Fixed.hpp"

int main(void) {
    Fixed		a;				// Default constructor
    Fixed const b(10);			// Int constructor
    Fixed const c(42.42f);		// Float constructor
    Fixed const d(b);			// Copy constructor

    a = Fixed(1234.4321f);		// Float constructor + assignment

	std::cout << std::endl;
	std::cout << "=== Tests constructors + assignment ===" << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
	std::cout << std::endl;

	std::cout << "=== Tests function toInt ===" << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	std::cout << "=== Tests function toFloat ===" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
    std::cout << "b is " << b.toFloat() << " as float" << std::endl;
    std::cout << "c is " << c.toFloat() << " as float" << std::endl;
    std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	std::cout << std::endl;

    return 0;
}