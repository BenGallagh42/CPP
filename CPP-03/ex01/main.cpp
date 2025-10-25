#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");
	std::cout << std::endl;

    clap.attack("Enemy 1");
    clap.takeDamage(5);
    clap.beRepaired(3);
	clap.beRepaired(2);
    clap.takeDamage(10);
    clap.beRepaired(5);
	std::cout << std::endl;

	scav.attack("Enemy 2");
    scav.takeDamage(5);
    scav.beRepaired(3);
	scav.guardGate();
    scav.takeDamage(100);
    scav.beRepaired(5);
	std::cout << std::endl;

	std::cout << clap << std::endl;
    std::cout << scav << std::endl;
	std::cout << std::endl;

    return 0;
}