#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Use command: " << argv[0] << " <level>" << std::endl;
		return 1;
	}

	Harl harl;
	std::string	level = argv[1];

	// Utilisation d'un filtre car methodes privees
	harl.filter(level);

	return 0;
}