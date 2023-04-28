#include "Floor.hpp"

Floor::Floor() {
	std::cout << "Floor created" << std::endl;
}

Floor::Floor(const Floor &copy){
	std::cout << "Floor copied" << std::endl;
}

Floor::~Floor(){
	std::cout << "Floor destructor" << std::endl;
}

Floor &Floor::operator=(const Floor &copy){
	this->_type = copy._type;
	std::cout << "Floor assigned" << std::endl;
	return (*this);
}

// AMateria *Floor::clone() const{
// 	return (new Floor(*this));
// }

// void Floor::use(ICharacter& target){
// 	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
// }
