#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include <iostream>

int main(void)
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    j->makeSound();
    i->makeSound();

    delete j;
    delete i;

    return (0);
}
