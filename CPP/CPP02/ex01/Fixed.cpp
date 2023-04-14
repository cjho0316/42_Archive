#include "Fixed.hpp"

const int Fixed::_frac = 8;

Fixed::Fixed(void) : _fixed(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value): _fixed(value << Fixed::_frac){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value): _fixed(static_cast<int>(roundf(value * (1 << Fixed::_frac)))) {
	std::cout << "Float constructor called" << std::endl;
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

float Fixed::toFloat() const{
	return static_cast<float>(this->_fixed) / (1 << Fixed::_frac);
}

int Fixed::toInt() const{
	return (_fixed >> Fixed::_frac);
}

std::ostream &operator<<(std::ostream &os, Fixed const &fp) {
		return (os << fp.toFloat());
}
