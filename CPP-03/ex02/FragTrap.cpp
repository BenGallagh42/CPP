#include "FragTrap.hpp"
#include <iostream>
#include <sstream>

FragTrap::FragTrap() : ClapTrap()
{
	this->hitPoints = 0;
	this->energyPoints = 0;
	this->attackDamage = 0;
	std::cout << "[FragTrap] default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "[FragTrap] " << name << " has been activated with " << hitPoints << " HP, " 
	<< energyPoints << " EP, and with " << attackDamage << " attack power." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "[FragTrap] copy constructor called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "[FragTrap] assignment operator called." << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "[FragTrap] " << name << " has been deactivated." << std::endl;
}

std::string FragTrap::getStatus() const
{
    std::ostringstream oss;
    oss << name << " : HP = " << hitPoints << ", EP = " << energyPoints;
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const FragTrap& ft)
{
    os << ft.getStatus();
    return os;
}

void FragTrap::attack(const std::string& target)
{
    if (hitPoints <= 0 || energyPoints <= 0)
	{
        std::cout << "[FragTrap] " << name << " is out of action! (Out of HP or EP)" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "[FragTrap] " << name << " unleashes a barrage on " << target << ", for " << attackDamage << " points of damage!" << std::endl;
	std::cout << getStatus() << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "[FragTrap] " << name << " requests a high five! 🙌" << std::endl;
}