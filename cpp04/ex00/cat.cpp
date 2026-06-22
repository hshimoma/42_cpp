#include "cat.hpp"
#include <iostream>

Cat::Cat()
{
	this->type = "Cat"; std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other) this->type = other.type; return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow~" << std::endl;
}
