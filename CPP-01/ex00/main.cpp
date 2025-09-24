#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	// Test randomChump (stack, everything automatic)
	randomChump("StackZombie");
	
	// Test newZombie (heap, everything manual)
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce(); // use -> instead of . because heapZombie = pointer
	delete heapZombie; // No delete = Leak

	return 0;
}