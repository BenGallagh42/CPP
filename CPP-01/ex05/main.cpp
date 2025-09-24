#include "Harl.hpp"

int main()
{
	Harl harl;

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", "TEST"};
	int 		i = 0;
	while (i < 5)
	{
		std::cout << "Testing level: " << levels[i] << std::endl;
		harl.complain(levels[i]);
		std::cout << std::endl;
		i++;
	}
	return 0;
}