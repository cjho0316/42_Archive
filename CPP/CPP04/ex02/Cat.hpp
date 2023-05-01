# ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat: public Animal
{
	private:
		Brain* _brain;
	public:
		/* OCF */
		Cat();
        Cat(Cat const &copy);
		~Cat();
		Cat& operator=(Cat const &copy);

		/* member functions */
		void makeSound() const;

		/* getter, setter */
		std::string getCatIdea(int i) const;
		void setCatIdea(int i, std::string str) const;
};

#endif
