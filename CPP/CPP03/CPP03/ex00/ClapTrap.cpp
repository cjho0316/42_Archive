#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string _name) : _hitPoints(10), _energyPoints(10),  _attackDamage(0){
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "Distructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy){
	
}


void ClapTrap::takeDamage(unsigned int amount){
	this->_attackDamage
}

void ClapTrap::beRepaired(unsigned int amount){
	
}

void ClapTrap::attack(const std::string& target){
	cout << "ClapTrap " << name << "attacks " << target << "causing" << damage << "points of damage!" << std::endl;
}
