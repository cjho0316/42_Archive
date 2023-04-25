#include "Amateria.hpp"

AMateria::AMateria(){
	std::cout << "AMateria Default Constructor Called" << std::endl;
}

AMateria::AMateria(std::string const &type): _type(type){
	std::cout << "AMateria Constructor Called" << std::endl;
}

AMateria::AMateria(const AMateria &copy): _type(copy._type){
	std::cout << "AMateria Copy Constructor Called" << std::endl;
}

AMateria::~AMateria(){
	std::cout << "AMateria Destructor Called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &copy){
	this->_type = copy._type;
	return (*this);
}

std::string const &AMateria::getType() const{
	return this->_type;
}

// void AMateria::use(ICharacter &target){
// 	std::cout << "used" << this->_type << " to " << target.getName() << std::endl;
// }
