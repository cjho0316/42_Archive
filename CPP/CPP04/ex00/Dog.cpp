#include "Dog.hpp"

Dog::Dog(): Animal("Dog"){
	std::cout << "Dog Consturctor created" << std::endl;
}

// Dog::Dog(const Dog &copy): Animal(copy._type)
Dog::Dog(Dog const &copy){
	std::cout << "Dog Copy Consturctor created" << std::endl;
	this->_type = copy.getType();
}

Dog::~Dog(){
	std::cout << "Dog Destructor" << std::endl;
}

Dog& Dog::operator=(Dog const &copy){
	std::cout << "Dog Copy constructor operator created" << std::endl;
	this->_type = copy.getType();
	return *this;
}

/* member functions */

void Dog::makeSound() const{
	std::cout << this->_type << " makes 'bark' sounds " << std::endl;
}