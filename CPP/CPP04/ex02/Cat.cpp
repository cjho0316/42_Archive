#include "Cat.hpp"

Cat::Cat(): Animal("Cat"){
	this->_brain = new Brain();
	std::cout << "Cat Consturctor created" << std::endl;
}

// Cat::Cat(const Cat &copy): Animal(copy._type)
Cat::Cat(Cat const &copy): Animal(copy._type){
	this->_brain = new Brain(*copy._brain);
	std::cout << "Cat Copy Consturctor created" << std::endl;

}

Cat::~Cat(){
	delete this->_brain;
	std::cout << "Cat Destructor" << std::endl;
}

Cat& Cat::operator=(Cat const &copy){
	this->_type = copy._type;
	delete this->_brain;
	this->_brain = new Brain(*copy._brain);
	std::cout << "Cat Copy constructor operator created" << std::endl;
	
	return *this;
}

/* member functions */

void Cat::makeSound() const{
	std::cout << this->_type << " makes 'meow' sounds " << std::endl;
}

/* getter, setter */

void Cat::setCatIdea(int i, std::string str) const{
	this->_brain->setIdea(i, str);
}

std::string Cat::getCatIdea(int i) const{
	return this->_brain->getIdea(i);
}