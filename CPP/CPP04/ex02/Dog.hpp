# ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog: public Animal
{
	private:
		Brain* _brain;
	public:
		/* OCF */
		Dog();
        Dog(Dog const &copy);
		~Dog();
		Dog& operator=(Dog const &copy);

		/* member functions */
		virtual void makeSound() const;

		/* getter, setter */
		std::string getDogIdea(int i) const;
		void setDogIdea(int i, std::string str) const;
};

#endif
