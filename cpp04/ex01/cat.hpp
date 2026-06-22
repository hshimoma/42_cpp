#ifndef CAT_HPP
#define CAT_HPP
#include "animal.hpp"
#include "brain.hpp"

class Cat : public Animal
{
	public:
    	Cat();
    	Cat(const Cat& other);
    	Cat& operator=(const Cat& other);
    	virtual ~Cat();

    	virtual void makeSound() const;
    	Brain* getBrain() const;

	private:
    	Brain* _brain; 
};

#endif
