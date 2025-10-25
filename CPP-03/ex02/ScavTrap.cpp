#include "ScavTrap.hpp"
#include <iostream>
#include <sstream>

ScavTrap::ScavTrap() : ClapTrap()
{
	this->hitPoints = 0;
	this->energyPoints = 0;
	this->attackDamage = 0;
	std::cout << "[ScavTrap] default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hitPoints = 100;
	this ->energyPoints = 50;
	this ->attackDamage = 20;
	std::cout << "[ScavTrap] " << name << " has been modified with " << hitPoints << " HP, " 
	<< energyPoints << " EP, and with " << attackDamage << " attack power." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "[ScavTrap] copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "[ScavTrap] assignment operator called." << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] " << name << " has been deleted." << std::endl;
}

std::string ScavTrap::getStatus() const
{
    std::ostringstream oss;
    oss << name << " : HP = " << hitPoints << ", EP = " << energyPoints;
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const ScavTrap& st)
{
    os << st.getStatus();
    return os;
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints <= 0 || energyPoints <= 0)
		std::cout << "[ScavTrap] " << name << " is unable to attack! (Out of HP or EP)" << std::endl;
	energyPoints--;
	std::cout << "[ScavTrap] " << name << " launches an assault on " << target << " dealing " << attackDamage << " damage!" << std::endl;
	std::cout << getStatus() << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "[ScavTrap] " << name << " is now in Gate keeper mode!" << std::endl;
}