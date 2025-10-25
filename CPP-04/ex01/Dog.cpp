#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain(); // Heap allocation so each dog has it's own brain.
	std::cout << "[Dog] has arrived." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	brain = new Brain(*other.brain);		// Deep copy to create new object
	std::cout << "[Dog] Copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;						// Remove previous brain address to avoid leaks
		brain = new Brain(*other.brain);	// Deep copy of new brain
		std::cout << "[Dog] Assignment operator called." << std::endl;
	}
	return *this;
}

Dog::~Dog()
{
	delete brain;		// To free memory.
	std::cout << "[Dog] has left." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "[Dog] Woof woof?" << std::endl;
}

Brain* Dog::getBrain() const
{
	return brain;
}