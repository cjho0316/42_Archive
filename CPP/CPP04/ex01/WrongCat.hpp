# ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat: public WrongAnimal
{
	protected:
		std::string _type;
	public:
		/* OCF */
		WrongCat();
        WrongCat(WrongCat const &copy);
		~WrongCat();
		WrongCat& operator=(WrongCat const &copy);

		/* member functions */
		virtual void makeSound() const;
		
		/* getter setter */
		std::string getType(void) const;
		void setType(std::string type);
};

#endif