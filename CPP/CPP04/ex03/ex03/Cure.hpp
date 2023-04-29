# ifndef CURE_H
#define CURE_H

#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria {
	public:
		/* OCF */
		Cure();
		Cure(const Cure &copy);
		~Cure();
		Cure &operator=(const Cure &copy);

		/* member fuctions */
		AMateria *clone() const;
		void use(ICharacter& target);
};

#endif