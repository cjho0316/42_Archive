#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	std::cout << "Default Constructor Called" << std::endl;
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDmg = FragTrap::_attackDmg;
}

DiamondTrap::DiamondTrap(std::string const &name): _name(name){
	std::cout << "Constructor w/ name Called" << std::endl;
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDmg = FragTrap::_attackDmg;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy){
	this->_name = copy.getName();
	this->_hitPoint = copy.getHitPoint();
	this->_energyPoint = copy.getAttackDamage();
	this->_attackDmg = copy.getAttackDamage();
}

DiamondTrap::~DiamondTrap(){
	std::cout << "Diamond Trap " << this->_name << "is gone" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &copy){
	std::cout << "Copy constructor operator Called" << std::endl;
	this->_name = copy.getName();
	this->_hitPoint = copy.getHitPoint();
	this->_energyPoint = copy.getEnergyPoint();
	this->_attackDmg = copy.getAttackDamage();
	return *this;
}

void DiamondTrap::whoAmI(void){
	std::cout << "I am a DiamondTrap named " << this->_name << "!" << std::endl;
	std::cout << "And my grandparent ClapTrap's name is " << ClapTrap::_name << "!" << std::endl;
}
