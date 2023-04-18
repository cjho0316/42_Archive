# ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog: public Animal
{
	public:
		/* OCF */
		Dog();
        Dog(Dog const &copy);
		~Dog();
		Dog& operator=(Dog const &copy);

		/* member functions */
		virtual void makeSound() const;

};

#endif