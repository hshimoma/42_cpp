#include "zombie.hpp"

int main(void)
{
	int N;
	int i;

	N = 5;
	Zombie* horde = zombieHorde(N, "Chump");
	i = 0;
	while (i < N)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;

	return (0);
}
