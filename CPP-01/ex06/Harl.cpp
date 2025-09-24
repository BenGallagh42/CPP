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

void Harl::filter(std::string level)
{
	// Indexage des niveaux
	int levelIndex = -1;
	if (level == "DEBUG")
		levelIndex = 0;
	else if (level == "INFO")
		levelIndex = 1;
	else if (level == "WARNING")
		levelIndex = 2;
	else if (level == "ERROR")
		levelIndex = 3;
	
	// Utilisation de switch
	switch (levelIndex)
	{
		case 3: this->error();
		case 2: this->warning();
		case 1: this->info();
		case 0: this->debug();
			break;
			
		default: std::cout << "Level not found" << std::endl;
			break;
	}
}