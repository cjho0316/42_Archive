# ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		/* OCF */
		WrongAnimal();
		WrongAnimal(std::string type);
        WrongAnimal(WrongAnimal const &copy);
		virtual ~WrongAnimal();
		WrongAnimal& operator=(WrongAnimal const &copy);

		/* member functions */
		virtual void makeSound() const;

		/* getter, setter */
		std::string getType() const;
		void setType(std::string type);
};

#endif
