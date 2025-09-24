#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
	std::string name;

public:
	Zombie(); // Ajout du constructeur par defaut
	Zombie(std::string name);
	~Zombie();

	void announce(void);
	void setName(std::string name);
};

#endif