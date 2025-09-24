#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	int N = 5;

	Zombie* hordePtr = zombieHorde(N, "HordeZombie");

	if (hordePtr != NULL)
	{
		int i = 0;
		while (i < N)
		{
			hordePtr[i].announce();
			i++;
		}
		delete[] hordePtr;
	}
	return 0;
}