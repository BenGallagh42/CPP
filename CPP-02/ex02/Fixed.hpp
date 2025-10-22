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

	// Operateurs de comparaisons
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// Operateurs arithmetiques
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// Incremention/Decrementation
	Fixed&	operator++();		// Pre-incr
    Fixed	operator++(int);	// Post-incr
    Fixed&	operator--();		// Pre-decr
    Fixed	operator--(int);	// Post-decr

	// Fonctions statiques
    static 			Fixed& min(Fixed& a, Fixed& b);
    static const	Fixed& min(const Fixed& a, const Fixed& b);
    static			Fixed& max(Fixed& a, Fixed& b);
    static const	Fixed& max(const Fixed& a, const Fixed& b);
};

// Surcharge de l'operateur << (operator overloading)
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif