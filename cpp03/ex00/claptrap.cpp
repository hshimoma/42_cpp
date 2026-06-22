#include "claptrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap constructor for " << _name << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &other)
	{
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor for " << _name << " called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_hitPoints == 0 || this->_energyPoints == 0)
	{
        std::cout << "ClapTrap " << _name << " has no hit points or energy to attack!" << std::endl;
        return;
    }
    this->_energyPoints -= 1;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0)
	{
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
        return;
    }
    if (amount >= this->_hitPoints)
	{
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount << " damage and dies!" << std::endl;
    }
	else
	{
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " damage! (Remaining HP: " << _hitPoints << ")" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints == 0 || this->_energyPoints == 0)
	{
        std::cout << "ClapTrap " << _name << " cannot repair itself because it has no HP or energy!" << std::endl;
        return;
    }
    this->_energyPoints -= 1;
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself, regaining " << amount << " hit points! (Current HP: " << _hitPoints << ")" << std::endl;
}
