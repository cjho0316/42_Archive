#include "Fixed.hpp"

const int Fixed::_frac = 8;

Fixed::Fixed() : _fixed(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Distructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy){
	std::cout << "Copy constructor operator called" << std::endl;
	this->_fixed = copy.getRawBits();
}

Fixed& Fixed::operator=(Fixed const &copy){
	std::cout << "Copy constructor operator called" << std::endl;
	this->_fixed = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits() const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void Fixed::setRawBits(int const raw){	
	this->_fixed = raw;
}
