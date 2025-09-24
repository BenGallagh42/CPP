#include "Fixed.hpp"

Fixed::Fixed()
{
	_value = 0;
	std::cout << "Default constructor called" << std::endl; // Debug
}

Fixed::Fixed(const Fixed& other)
{
	_value = other._value;
	std::cout << "Copy constructor called" << std::endl; //Debug
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		_value = other._value;
	std::cout <<"Copy assignment operator called" << std::endl; // Debug
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl; // Debug
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl; // Debug
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}