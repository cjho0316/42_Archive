#include "Animal.hpp"

Animal::Animal(): _type("undefined"){
	std::cout << "'undefinded' Animal Consturctor created" << std::endl;
}

Animal::Animal(std::string type): _type(type){
	std::cout << this->_type << " Animal Consturctor created" << std::endl;
}

Animal::Animal(Animal const &copy){
	std::cout << "Animal Consturctor created" << std::endl;
	this->_type = copy.getType();
}

Animal::~Animal(){
	std::cout << "Animal Destructor" << std::endl;
}

Animal& Animal::operator=(Animal const &copy){
	std::cout << "Animal Copy constructor operator created" << std::endl;
	this->_type = copy.getType();
	return *this;
}

/* member functions */

void Animal::makeSound() const{
	std::cout << this->_type << " animal sounds like" << std::endl;
}

/* getter, settter */

std::string Animal::getType() const{
	return this->_type;
}

void Animal::setType(std::string type){
	this->_type = type;
}