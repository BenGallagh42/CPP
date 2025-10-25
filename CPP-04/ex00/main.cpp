#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Basic tests ===" << std::endl;
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
	std::cout << std::endl;

	// Non-Virtual: Call the same function whatever the pointer
	std::cout << "=== getType tests ===" << std::endl;
    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;
	std::cout << std::endl;

	// Virtual function: Call the function corresponding to the pointer
	std::cout << "=== makeSound tests ===" << std::endl;
    cat->makeSound();
    dog->makeSound();
    animal->makeSound();
	std::cout << std::endl;

	// Virtual destructor: Call the destructor corresponding to the pointer
	std::cout << "=== Destructor tests ===" << std::endl;
    delete animal;
    delete dog;
    delete cat;
	std::cout << std::endl;

	 // To show what happens when not virtual function
    std::cout << "=== Wrong animal test ===" << std::endl;
    const WrongAnimal* wrong = new WrongCat();
    wrong->makeSound();
    delete wrong;
	std::cout << std::endl;

	// To show when use directlw WrongCat* instead of WrongAnimal*
	std::cout << "=== WrongCat used as WrongCat ===" << std::endl;
    WrongCat* direct_cat = new WrongCat();
    direct_cat->makeSound();
    delete direct_cat;
	
    return 0;
}