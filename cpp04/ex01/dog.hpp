#ifndef DOG_HPP
#define DOG_HPP
#include "animal.hpp"
#include "brain.hpp"

class Dog : public Animal
{
	public:
    	Dog();
    	Dog(const Dog& other);
    	Dog& operator=(const Dog& other);
    	virtual ~Dog();

    	virtual void makeSound() const;
    	Brain* getBrain() const;

	private:
    	Brain* _brain; 
};

#endif
