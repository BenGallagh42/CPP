#include "Zombie.hpp"

// Constructeur
Zombie::Zombie(std::string name)
{
	this->name = name;
}

// Destructeur
Zombie::~Zombie()
{
	std::cout << this->name << ": destroyed!" << std::endl;
}

// Methode (Brainz Message)
void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}