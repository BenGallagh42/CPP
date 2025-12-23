#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Base.hpp"

// Randomly instantiates A, B, or C and returns as Base pointer
Base* generate(void);

// Prints the actual type using pointer
void identify(Base* p);

// Prints the actual type using reference
void identify(Base& p);

#endif