#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {} // Initialisation dans constructeur

void Weapon::setType(std::string newType)
{
	type = newType;
}

const std::string& Weapon::getType() const
{
	return type;
}