#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat"){
	std::cout << "WrongCat Consturctor created" << std::endl;
}

// WrongCat::WrongCat(const WrongCat &copy): Animal(copy._type)
WrongCat::WrongCat(WrongCat const &copy){
	std::cout << "WrongCat Copy Consturctor created" << std::endl;
	this->_type = copy.getType();
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat Destructor" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const &copy){
	std::cout << "WrongCat Copy constructor operator created" << std::endl;
	this->_type = copy.getType();
	return *this;
}

/* member functions */
void WrongCat::makeSound() const{
	std::cout << this->_type << " makes ' ??weom?? ' sounds " << std::endl;
}

/* getter setter */
std::string WrongCat::getType(void) const
{
	return _type;
}

void WrongCat::setType(std::string type)
{
	this->_type = type;
}