#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[DEBUG] I love having extra bacon for my burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

// Definition des tableaux statiques
Harl::HarlFunctionPtr 	Harl::levels[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
const std::string 		Harl::levelNames[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl() {}

void Harl::complain(std::string level)
{
	int i = 0;
	while (i < 4)
	{
		if (level == levelNames[i])
		{
			(this->*levels[i])(); // Appel via ptr
			return;
		}
		i++;
	}
	std::cout << "Level not found" << std::endl;
}