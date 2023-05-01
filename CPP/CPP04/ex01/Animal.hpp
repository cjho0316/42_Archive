# ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string _type;

	public:
		/* OCF */
		Animal();
		Animal(std::string type);
        Animal(Animal const &copy);
		virtual ~Animal();
		Animal& operator=(Animal const &copy);

		/* member functions */
		virtual void makeSound() const = 0;

		/* getter, setter */
		std::string getType() const;
		void setType(std::string type);
};

#endif
