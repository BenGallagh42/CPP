#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

private:
	int					_value;
	static const int	_fractionalBits = 8;

public:
	Fixed();								// Default constructor
	Fixed(const Fixed& other);				// Copy constructor
	Fixed& operator=(const Fixed& other);	// Assignment operator
	Fixed(const int value);					// Int constructor
	Fixed(const float value);				// Float constructor
	~Fixed();								// Destructor

	int		getRawBits() const;				// Retourne _value sans modif
	void	setRawBits(int const raw);		// Definit _value
	float	toFloat(void) const;			// Convert to Float
	int		toInt(void) const;				// Convert to Int
};

// Surcharge de l'operateur << (operator overloading)
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif