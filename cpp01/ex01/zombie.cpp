#include "zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie()
{
	std::cout << _name << "died and destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() : _name("NoName") {}
void Zombie::setName(std::string name) { _name = name; }