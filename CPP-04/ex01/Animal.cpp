#include "Animal.hpp"

Animal::Animal() : type("")
{
    std::cout << "[Animal] Default constructor called." << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << "[Animal] Copy constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "[Animal] Assignment operator called." << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "[Animal] Destructor called." << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "[Animal] Random animal sound." << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}