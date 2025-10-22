#include "Fixed.hpp"

int main(void) {
	Fixed a;			// Call default constructor
	Fixed b(a);			// Call copy constructor
	Fixed c;			// Default constructor again

	c = b;				// Call assignment operator

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}