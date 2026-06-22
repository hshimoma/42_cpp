#include "fragtrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "--- Creating FragTrap ---" << std::endl;
    FragTrap fraggy("Fraggy");

    std::cout << "\n--- Actions ---" << std::endl;
    fraggy.attack("a dangerous enemy");
    fraggy.highFivesGuys();

    std::cout << "\n--- Deleting FragTrap ---" << std::endl;
    return (0);
}
