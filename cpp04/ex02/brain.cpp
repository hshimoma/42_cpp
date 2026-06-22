#include "brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other) { *this = other; }

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assignment called" << std::endl;
    if (this != &other)
	{
        int i;
		
		i = 0;
		while (i < 100)
		{
            this->ideas[i] = other.ideas[i];
			i++;
        }
    }
    return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
