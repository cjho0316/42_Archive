#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("undefined"){
	std::cout << "'undefinded' WrongAnimal Consturctor created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type){
	std::cout << this->_type << " w/ name WrongAnimal Consturctor created" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy){
	std::cout << "WrongAnimal Consturctor created" << std::endl;
	this->_type = copy.getType();
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &copy){
	std::cout << "WrongAnimal Copy constructor operator created" << std::endl;
	this->_type = copy.getType();
	return *this;
}

/* member functions */

void WrongAnimal::makeSound() const{
	std::cout << this->_type << " animal sounds like" << std::endl;
}

/* getter, settter */

std::string WrongAnimal::getType() const{
	return this->_type;
}

void WrongAnimal::setType(std::string type){
	this->_type = type;
}