#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "[Dog] has arrived." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "[Dog] Copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "[Dog] Assignment operator called." << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "[Dog] has left." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "[Dog] Woof woof?" << std::endl;
}