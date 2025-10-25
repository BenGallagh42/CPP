#include "ClapTrap.hpp"
#include <iostream>
#include <sstream>

ClapTrap::ClapTrap() : name("Default"), hitPoints(0), energyPoints(0), attackDamage(0)
{
	std::cout << "[ClapTrap] default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "[ClapTrap] " << name << " has been constructed with " << hitPoints << " HP, " 
	<< energyPoints << " EP, and with " << attackDamage << " attack power." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), 
	  energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << "[ClapTrap] copy constructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "[ClapTrap] assignment operator called." << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] " << name << " has been destructed." << std::endl;
}

std::string ClapTrap::getStatus() const
{
	std::ostringstream oss;
	oss << name << " : HP = " << hitPoints << ", EP = " << energyPoints;
	return oss.str();
}

std::ostream& operator<<(std::ostream& os, const ClapTrap& ct)
{
	os << ct.getStatus();
	return os;
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "[ClapTrap] " << name << " can't attack! (Out of HP or EP)" << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "[ClapTrap] " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	std::cout << getStatus() << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "[ClapTrap] " << name << " is already destroyed!" << std::endl;
		return;
	}
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout << "[ClapTrap] " << name << " takes " << amount << " points of damage!" << std::endl;
	std::cout << getStatus() << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "[ClapTrap] " << name << " can't repair itself! (Out of HP or EP)" << std::endl;
		return;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout << "[ClapTrap] " << name << " is repaired by " << amount << " hit points!" << std::endl;
	std::cout << getStatus() << std::endl;
}