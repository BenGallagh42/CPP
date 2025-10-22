#include "Fixed.hpp"
#include <cmath> // Pour roundf

Fixed::Fixed()
{
	_value = 0;
	// std::cout << "Default constructor called" << std::endl; // Debug
}

Fixed::Fixed(const Fixed& other)
{
	_value = other._value; // Copie la valeur de l'objet (other)
	// std::cout << "Copy constructor called" << std::endl; // Debug
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other) // Verifie si ce n'est pas une auto-assignation (ne pas se copier soit meme)
		_value = other._value;
	// std::cout <<"Copy assignment operator called" << std::endl; // Debug
	return *this; // Retourne l'objet courant pour chainage
}

Fixed::Fixed(const int value)
{
	_value = value << _fractionalBits; // Decale de 8 bits (multiplie par 2^8)
	// std::cout << "Int constructor called" << std::endl; // Debug
}

Fixed::Fixed(const float value)
{
	_value = roundf(value * (1 << _fractionalBits)); // Arrondit apres multiplication
	// std::cout << "Float constructor called" << std::endl; // Debug
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl; // Debug
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl; // Debug
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

// Operateurs de comparaison
bool Fixed::operator>(const Fixed& other) const
{
    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const
{
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return _value != other._value;
}

// Operateurs arithmetic
Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result._value = _value + other._value;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result._value = _value - other._value;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result._value = (_value * other._value) >> _fractionalBits;  // Ajuste pour la precision
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    if (other._value == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        exit(1);  // Crash acceptable selon le sujet
    }
    Fixed result;
    result._value = (_value << _fractionalBits) / other._value;  // Ajuste la précision
    return result;
}

// Operateurs d'incrementation/decrementation
// Pre-incr
Fixed& Fixed::operator++()
{
    _value += 1;  // Increment minimal (1 unité = 1/256)
    return *this;
}

//Post-incr
Fixed Fixed::operator++(int)
{
    Fixed temp(*this);  // Copie actuelle
    _value += 1;       // Increment
    return temp;       // Retourne la valeur avant increment
}

Fixed& Fixed::operator--() 
{
    _value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _value -= 1;
    return temp;
}

// Fonctions statiques
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a._value < b._value)
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a._value < b._value)
        return a;
    else
        return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a._value > b._value)
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a._value > b._value)
        return a;
    else
        return b;
}