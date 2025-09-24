#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return NULL;
	
	Zombie* hordePtr = new Zombie[N];

	int i = 0;
	while (i < N)
	{
		hordePtr[i].setName(name);
		i++;
	}
	return hordePtr;
}