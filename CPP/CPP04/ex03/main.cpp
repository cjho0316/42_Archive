#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <stdlib.h>

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		tmp = src->createMateria("ice"); // create -> clone -> copy
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->unequip(0);
		me->unequip(1);
		me->unequip(2);
		me->unequip(3);
		
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
		std::cout << std::endl;
	}
	{
		std::cout << "-----------------------------------\n" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		Character* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		Character* sam = new Character("sam");
		*sam = *me;
		Character* bob = new Character("bob");
		std::cout << "---------- 'me' actions ----------" << std::endl;
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);
		me->use(4, *bob);
		me->use(5, *bob);
		std::cout << "---------- 'sam' actions ----------" << std::endl;
		tmp = src->createMateria("ice");
		sam->equip(tmp);
		sam->use(0, *bob);
		sam->use(1, *bob);
		sam->use(2, *bob);
		sam->use(3, *bob);
		sam->use(4, *bob);
		sam->use(5, *bob);

		delete bob;
		delete me;
		delete sam;
		delete src;
		// system("leaks AMateria");
		return 0;
	}
}