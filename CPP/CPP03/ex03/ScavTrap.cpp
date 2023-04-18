#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout << "Default Constructor Called" << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDmg = 50;	
}

ScavTrap::ScavTrap(std::string const &name){
	std::cout << "Constructor w/ name Called" << std::endl;
	this->_name = name;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDmg = 50;
}

ScavTrap::ScavTrap(ScavTrap const &copy){
	this->_name = copy.getName();
	this->_hitPoint = copy.getHitPoint();
	this->_energyPoint = copy.getAttackDamage();
	this->_attackDmg = copy.getAttackDamage();
}

ScavTrap::~ScavTrap(){
	std::cout << "Destructor Called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &copy){
	std::cout << "Copy constructor operator Called" << std::endl;
	this->_name = copy.getName();
	this->_hitPoint = copy.getHitPoint();
	this->_energyPoint = copy.getEnergyPoint();
	this->_attackDmg = copy.getAttackDamage();

	return *this;
}

void ScavTrap::attack(const std::string& target){
    if (this->_hitPoint <= 0)
        std::cout << "You don't have enough hit point" << std::endl;
    else if (this->_energyPoint <= 0)
        std::cout << "You don't have enough energy point" << std::endl;
	else
        std::cout << "ScavTrap " << this->_name << "attacks " << target << " causing " << this->_attackDmg << " points of damage! " << std::endl;
}

void ScavTrap::guardGate(void){
	if (this->_hitPoint <= 0)
		std::cout << "You don't have enough hit point" << std::endl;
	else
		std::cout << "ScavTrap activated guard-gate mode" << std::endl;
}