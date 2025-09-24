#include "Zombie.hpp"

// Constructuer par defaut (nom vide)
Zombie::Zombie()
{
	this->name = "";
}

// Constructeur avec nom
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

void Zombie::setName(std::string name)
{
	this->name = name;
}