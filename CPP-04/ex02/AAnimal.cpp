#include "AAnimal.hpp"

AAnimal::AAnimal() : type("")
{
    std::cout << "[AAnimal] Default constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type)
{
    std::cout << "[AAnimal] Copy constructor called." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "[AAnimal] Assignment operator called." << std::endl;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "[AAnimal] Destructor called." << std::endl;
}

std::string AAnimal::getType() const
{
    return this->type;
}