#include "Dog.hpp"

Dog::Dog(): Animal("Dog"){
	this->_brain = new Brain();
	std::cout << "Dog Consturctor created" << std::endl;
}

// Dog::Dog(const Dog &copy): Animal(copy._type)
Dog::Dog(Dog const &copy): Animal(copy._type){
	this->_brain = new Brain(*copy._brain);
	std::cout << "Dog Copy Consturctor created" << std::endl;
}

Dog::~Dog(){
	delete this->_brain;
	std::cout << "Dog Destructor" << std::endl;
}

Dog& Dog::operator=(Dog const &copy){
	this->_type = copy._type;
	delete this->_brain;
	this->_brain = new Brain(*copy._brain);
	std::cout << "Dog Copy constructor operator created" << std::endl;
	
	return *this;
}
/* member functions */

void Dog::makeSound() const{
	std::cout << this->_type << " makes 'bark' sounds " << std::endl;
}

/* getter, setter */

void Dog::setDogIdea(int i, std::string str) const{
	this->_brain->setIdea(i, str);
}

std::string Dog::getDogIdea(int i) const{
	return this->_brain->getIdea(i);
}