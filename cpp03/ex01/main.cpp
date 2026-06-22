#include "scavtrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Creating ScavTrap ---" << std::endl;
    ScavTrap scavenger("Scavvy");

    std::cout << "\n--- Actions ---" << std::endl;
    scavenger.attack("an intruder");
    scavenger.takeDamage(30);
    scavenger.guardGate();

    std::cout << "\n--- Deleting ScavTrap ---" << std::endl;
    return (0);
}
