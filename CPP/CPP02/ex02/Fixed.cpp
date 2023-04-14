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
	return (this->_fixed >> Fixed::_frac);
}

std::ostream &operator<<(std::ostream &os, Fixed const &fp) {
		return (os << fp.toFloat());
}

Fixed& Fixed::operator=(Fixed const &copy){
	std::cout << "Copy constructor operator called" << std::endl;
	this->_fixed = copy.getRawBits();
	return *this;
}

/* 6 comparison operators */

bool Fixed::operator>(Fixed const &value) const{
	return (this->toFloat() > value.toFloat());
}

bool Fixed::operator<(Fixed const &value) const{
	return (this->toFloat() < value.toFloat());
}

bool Fixed::operator>=(Fixed const &value) const{
	return (this->toFloat() >= value.toFloat());
}

bool Fixed::operator<=(Fixed const &value) const{
	return (this->toFloat() <= value.toFloat());
}

bool Fixed::operator==(Fixed const &value) const{
	return (this->toFloat() == value.toFloat());
}

bool Fixed::operator!=(Fixed const &value) const{
	return (this->toFloat() != value.toFloat());
}

/* 4 arithmetic operators */
Fixed Fixed::operator+(Fixed const &value){
	Fixed tmp(this->toFloat() + value.toFloat());
	return tmp;
}

Fixed Fixed::operator-(Fixed const &value){
	Fixed tmp(this->toFloat() - value.toFloat());
	return tmp;
}

Fixed Fixed::operator*(Fixed const &value){
	Fixed tmp(this->toFloat() * value.toFloat());
	return tmp;
}

Fixed Fixed::operator/(Fixed const &value){
	Fixed tmp(this->toFloat() / value.toFloat());
	return tmp;
}

/* post, pre increment and decrement operators */
/* post increment, decrement */
Fixed &Fixed::operator++(void){
	this->_fixed = this->_fixed + 1;
	return (*this);
}

Fixed &Fixed::operator--(void){
	this->_fixed = this->_fixed - 1;
	return (*this);
}

/* pre increment, decrement */
Fixed Fixed::operator++(int){
	Fixed tmp = *this;
	(++(this->_fixed));
	return tmp;
}


Fixed Fixed::operator--(int){
	Fixed tmp = *this;
	(--(this->_fixed));
	return tmp;
}

/* min,max function overloading */

Fixed& Fixed::min(Fixed &value1, Fixed &value2){
	if (value1 > value2)
		return value2;
	else
		return value1;
}

Fixed& Fixed::max(Fixed &value1, Fixed &value2){
	if (value1 > value2)
		return value1;
	return value2;
}

const Fixed& Fixed::min(Fixed const &value1, Fixed const &value2){
	if (value1 > value2)
		return value2;
	return value1;
}

const Fixed& Fixed::max(Fixed const &value1, Fixed const &value2){
	if (value1 > value2)
		return value1;
	return value2;
}




