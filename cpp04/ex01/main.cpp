#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include <iostream>

int main(void)
{
    const int size = 4;
    Animal* animals[size];
	int i;

    std::cout << "=== 1. Create Array ===" << std::endl;
	i = 0;
    while (i < size / 2)
	{
		animals[i] = new Dog();
		i++;
	}
	i = size / 2;
    while (i < size)
	{ 
		animals[i] = new Cat();
		i++;
	}

    std::cout << "\n=== 2. Deep Copy Test ===" << std::endl;
    Dog basic;
    basic.getBrain()->ideas[0] = "Original Idea";
    
    Dog clone(basic);
    std::cout << "Clone idea: " << clone.getBrain()->ideas[0] << std::endl;
    
    basic.getBrain()->ideas[0] = "Changed Idea";
    std::cout << "Clone idea after original changed: " << clone.getBrain()->ideas[0] << std::endl;

    std::cout << "\n=== 3. Clean Up ===" << std::endl;
    i = 0;
	while (i < size)
	{
        delete animals[i];
		i++;
    }

    return (0);
}
