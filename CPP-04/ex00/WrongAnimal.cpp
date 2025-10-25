#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("")
{
    std::cout << "[WrongAnimal] Constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout << "[WrongAnimal] Copy constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[WrongAnimal] Destructor called." << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "[WrongAnimal] Wrong sound." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}