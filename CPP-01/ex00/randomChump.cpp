#include "Zombie.hpp"

// Allocation sur stack automatique
void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}