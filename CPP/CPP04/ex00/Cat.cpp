#include "Cat.hpp"

Cat::Cat(): Animal("Cat"){
	std::cout << "Cat Consturctor created" << std::endl;
}

// Cat::Cat(const Cat &copy): Animal(copy._type)
Cat::Cat(Cat const &copy){
	std::cout << "Cat Copy Consturctor created" << std::endl;
	this->_type = copy.getType();
}

Cat::~Cat(){
	std::cout << "Cat Destructor" << std::endl;
}

Cat& Cat::operator=(Cat const &copy){
	std::cout << "Cat Copy constructor operator created" << std::endl;
	this->_type = copy.getType();
	return *this;
}

/* member functions */

void Cat::makeSound() const{
	std::cout << this->_type << " makes 'meow' sounds " << std::endl;
}