# ifndef FLOOR_H
#define FLOOR_H

#include <iostream>

class Floor: {
	private:
		
	public:
		/* OCF */
		Floor();
		Floor(const Floor &copy);
		~Floor();
		Floor &operator=(const Floor &copy);

		// /* member fuctions */
		// AMateria *clone() const;
		// void use(ICharacter& target);
};

#endif