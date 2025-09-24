#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
	std::string type;

public:
	Weapon(std::string type);			// Constructeur
	void setType(std::string type);		// Setter
	const std::string& getType() const;	// Getter
};

#endif