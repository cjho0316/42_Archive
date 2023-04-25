#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
	std::cout << "cure created" << std::endl;
}

Cure::Cure(const Cure &copy): AMateria(copy){
	std::cout << "cure copied" << std::endl;
}

Cure::~Cure(){
	std::cout << "cure destructor" << std::endl;
}

Cure &Cure::operator=(const Cure &copy){
	this->_type = copy._type;
	std::cout << "cure assigned" << std::endl;
	return (*this);
}

AMateria *Cure::clone() const{
	retrun (new Cure(*this));
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
