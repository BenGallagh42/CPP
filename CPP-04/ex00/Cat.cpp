#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "[Cat] is awake." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "[Cat] Copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "[Cat] Assignment operator called." << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "[Cat] went back to sleep." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "[Cat] Meow meow?" << std::endl;
}