#include "ClapTrap.hpp"


ClapTrap::ClapTrap(){
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "Distructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	cout << "ClapTrap " << name << "attacks " << target << "causing" << damage << "points of damage!" << std::endl;
}

void ClapTrap::