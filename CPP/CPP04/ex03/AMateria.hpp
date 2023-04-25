# ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp"

// class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &copy);
		virtual ~AMateria();

		AMateria &operator=(const AMateria &copy);

		std::string const & getType() const; 	//Returns the materia type
		virtual AMateria* clone() const = 0;	// pure virtual function
		virtual void use(ICharacter& target);	// virtual function
};

#endif