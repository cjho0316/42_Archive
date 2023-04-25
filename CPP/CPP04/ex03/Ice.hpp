# ifndef ICE_H
#define ICE_H

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		/* OCF */
		Ice();
		Ice(const Ice &copy);
		~Ice();
		Ice &operator=(const Ice &copy);

		/* member fuctions */
		AMateria *clone() const;
		void use(ICharacter& target);
};

#endif