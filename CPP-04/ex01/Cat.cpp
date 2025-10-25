#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
	brain = new Brain();		// Heap allocation so each cat has it's own brain.
    std::cout << "[Cat] is awake." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	brain = new Brain(*other.brain);		// Deep copy to create new object
    std::cout << "[Cat] Copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
	{
        Animal::operator=(other);
		delete brain;						// Remove previous brain address to avoid leaks
		brain = new Brain(*other.brain);	// Deep copy of new brain
    	std::cout << "[Cat] Assignment operator called." << std::endl;
	}
    return *this;
}

Cat::~Cat()
{
	delete brain;
    std::cout << "[Cat] went back to sleep." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "[Cat] Meow meow?" << std::endl;
}

Brain* Cat::getBrain() const
{
	return brain;
}