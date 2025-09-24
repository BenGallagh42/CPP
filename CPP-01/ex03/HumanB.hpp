#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
private:
	std::string	name;
	Weapon*		weapon;

public:
	HumanB(std::string name);		// Constructeur
	void setWeapon(Weapon* weapon);	// Methode pour assigner arme
	void attack() const;			// Methode pour attaque
};

#endif