#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== TEST 1: Array of Animals ===" << std::endl;
    const int size = 6;
    AAnimal* animals[size];

    // Fill the array 50/50
    for (int i = 0; i < size; ++i)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
	std::cout << std::endl;

    std::cout << "--- Testing sounds ---" << std::endl;
    for (int i = 0; i < size; ++i)
		animals[i]->makeSound();
	std::cout << std::endl;

    std::cout << "--- Deleting array ---" << std::endl;
    for (int i = 0; i < size; ++i)
		delete animals[i];  // Call virtual destructor
	std::cout << std::endl;

    std::cout << "=== TEST 2: Deep Copy Verification ===" << std::endl;
	std::cout << "--- Creating original ---" << std::endl;
    Dog* dog1 = new Dog();
    dog1->getBrain()->setIdea(0, "Chase the cat!");
	std::cout << "dog1 idea[0]: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

    std::cout << "--- Creating copy ---" << std::endl;
    Dog* dog2 = new Dog(*dog1);
	std::cout << std::endl;

    std::cout << "--- Deleting original ---" << std::endl;
    delete dog1;
	std::cout << std::endl;

    std::cout << "--- Accessing copy ---" << std::endl;
    std::cout << "dog2 idea[0]: " << dog2->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

    std::cout << "--- Deleting copy ---" << std::endl;
    delete dog2;
	std::cout << std::endl;

	std::cout << "=== TEST 3: Abstract class ===" << std::endl;
    // AAnimal a;
    // AAnimal* p = new AAnimal();
    std::cout << "Trying to do:" << std::endl;
    std::cout << "    AAnimal a;" << std::endl;
    std::cout << "    AAnimal* p = new AAnimal();" << std::endl;
    std::cout << "→ COMPILATION ERROR: 'AAnimal' is an abstract class." << std::endl;

    std::cout << "\n=== TEST 4: Polymorphism with abstract base ===" << std::endl;
    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();
	std::cout << std::endl;

    std::cout << "dog->getType(): " << dog->getType() << std::endl;
    std::cout << "cat->getType(): " << cat->getType() << std::endl;

    dog->makeSound();
    cat->makeSound();
	std::cout <<std::endl;

	delete dog;
	delete cat;

    return 0;
}