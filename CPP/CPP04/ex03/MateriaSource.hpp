# ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria *_materias[4];
	public:
		/* OCF */
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		~MateriaSource();

		MateriaSource &operator=(const MateriaSource &copy);

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);		
};

#endif