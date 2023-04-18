# ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat: public WrongAnimal
{
	public:
		/* OCF */
		WrongCat();
        WrongCat(WrongCat const &copy);
		~WrongCat();
		WrongCat& operator=(WrongCat const &copy);

		/* member functions */
		virtual void makeSound() const;

};

#endif