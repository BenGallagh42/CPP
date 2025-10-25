#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
    std::cout << "[WrongCat] is born." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "[WrongCat] Copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << "[WrongCat] Assignment operator called." << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] is un-born." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong meow meow?" << std::endl;
}
