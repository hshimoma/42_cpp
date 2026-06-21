#include "zombie.hpp"

int main(void)
{
	randomChump("Stack_Zombie");

	Zombie* heapZombie = newZombie("Heap_Zombie");
	heapZombie->announce();

	delete heapZombie;

	return (0);
}