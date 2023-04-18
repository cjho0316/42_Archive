# ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include <iostream>
#include <string>

class Cat: public Animal
{
	public:
		/* OCF */
		Cat();
        Cat(Cat const &copy);
		~Cat();
		Cat& operator=(Cat const &copy);

		/* member functions */
		virtual void makeSound() const;
};

#endif