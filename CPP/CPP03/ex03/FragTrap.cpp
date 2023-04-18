#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout << "Default Constructor Called" << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDmg = 30;
}

FragTrap::FragTrap(std::string const &name){
	std::cout << "Constructor w/ name Called" << std::endl;
	this->_name = name;
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDmg = 30;
}

FragTrap::FragTrap(FragTrap const &copy){
	this->_name = copy.getName();
	this->_hitPoint = copy.getHitPoint();
	this->_energyPoint = copy.getAttackDamage();
	this->_attackDmg = copy.getAttackDamage();
}

FragTrap::~FragTrap(){
	std::cout << "Destructor Called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &copy){
	std::cout << "Copy constructor operator Called" << std::endl;
	this->_name = copy.getName();
	this->_hitPoint = copy.getHitPoint();
	this->_energyPoint = copy.getEnergyPoint();
	this->_attackDmg = copy.getAttackDamage();

	return *this;
}

void FragTrap::highFivesGuys(void){
	if (this->_hitPoint <= 0)
		std::cout << "You don't have enough hit point" << std::endl;
	else
		std::cout << "FragTrap wants to get your highFives" << std::endl;
}