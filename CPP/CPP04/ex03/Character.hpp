# ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "ICharacter.hpp"


class Character: public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];
	public:
		/* OCF */
		Character();
		Character(std::string name);
		Character(const Character &copy);
		~Character();
		Character &operator=(const Character &copy);

		std::string const & getName() const;

		/* member functions */
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif