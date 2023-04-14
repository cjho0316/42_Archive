#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL){}

HumanB::~HumanB(void){
	std::cout << "HumanB Destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}

void HumanB::attack(void){
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
