#include "Fixed.hpp"
#include <cmath> // Pour roundf

Fixed::Fixed()
{
	_value = 0;
	std::cout << "Default constructor called" << std::endl; // Debug
}

Fixed::Fixed(const Fixed& other)
{
	_value = other._value; // Copie la valeur de l'objet (other)
	std::cout << "Copy constructor called" << std::endl; //Debug
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other) // Verifie si ce n'est pas une auto-assignation (ne pas se copier soit meme)
		_value = other._value;
	std::cout <<"Copy assignment operator called" << std::endl; // Debug
	return *this; // Retourne l'objet courant pour chainage
}

Fixed::Fixed(const int value)
{
	_value = value << _fractionalBits; // Decale de 8 bits (multiplie par 2^8)
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	_value = roundf(value * (1 << _fractionalBits)); // Arrondit apres multiplication
	std::cout << "Float constructor called" << std::endl;
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

float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << _fractionalBits); // Divise par 2^8
}

int Fixed::toInt(void) const
{
	return _value >> _fractionalBits; // Decale de 8 bits a droite
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat(); // Convert en Float
	return os;
}