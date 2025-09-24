#include "Zombie.hpp"

// Allocation sur heap
Zombie* newZombie(std::string name) 
{
	Zombie* zombie = new Zombie(name);
	return zombie;
}