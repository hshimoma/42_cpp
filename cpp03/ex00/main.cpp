#include "claptrap.hpp"

int main(void)
{
    ClapTrap clappy("Clappy");

    clappy.attack("Handsome Jack");
    clappy.takeDamage(5);
    clappy.beRepaired(3);

    int i;

	i = 0;
	while (i < 9)
	{
        clappy.attack("a target");
		i++;
    }
    return 0;
}
