#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
private:
	std::string	name;
	Weapon& 	weapon; 						//Reference a Weapon

public:
	HumanA(std::string name, Weapon& weapon);	// Constructeur
	void attack() const;						// Methode pour attaque
};

#endif