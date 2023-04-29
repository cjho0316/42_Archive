#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
	std::cout << "ice created" << std::endl;
}

Ice::Ice(const Ice &copy): AMateria(copy){
	std::cout << "ice copied" << std::endl;
}

Ice::~Ice(){
	std::cout << "ice destructor" << std::endl;
}

Ice &Ice::operator=(const Ice &copy){
	this->_type = copy._type;
	std::cout << "ice assigned" << std::endl;
	return (*this);
}

AMateria *Ice::clone() const{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
