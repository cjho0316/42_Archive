#include "ClapTrap.hpp"


ClapTrap::ClapTrap(){
	std::cout << "Default constructor called" << std::endl;
    this->_name = "Default name";
    this->_hitPoint = 10;
    this->_energyPoint = 10;
    this->_attackDmg = 0;
}

ClapTrap::ClapTrap(std::string name){
	std::cout << "Default constructor called" << std::endl;
    this->_name = name;
    this->_hitPoint = 10;
    this->_energyPoint = 10;
    this->_attackDmg = 0;    
}

ClapTrap::ClapTrap(ClapTrap const &copy) {
    this->_name = copy.getName();
    this->_hitPoint = copy.getHitPoint();
    this->_energyPoint = copy.getEnergyPoint();
    this->_attackDmg = copy.getAttackDamage();
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &copy){
	std::cout << "Copy constructor operator called" << std::endl;
	this->_name = copy.getName();
	this->_hitPoint = copy.getHitPoint();
	this->_energyPoint = copy.getEnergyPoint();
	this->_attackDmg = copy.getAttackDamage();
	return *this;
}

void ClapTrap::attack(const std::string& target){
    if (this->_hitPoint <= 0)
        std::cout << "You don't have enough hit point" << std::endl;
    else if (this->_energyPoint <= 0)
        std::cout << "You don't have enough energy point" << std::endl;
	else
        std::cout << "ClapTrap " << this->_name << "attacks " << target << " causing " << this->_attackDmg << " points of damage! " << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->_hitPoint <= 0)
        std::cout << "You don't have enough hit point" << std::endl;
    
    this->_hitPoint -= amount;
    if (this->_hitPoint > 0)
        std::cout << "ClapTrap " << this->_name << "take " << amount << " damage!" << std::endl;
    else
        std::cout << "ClapTrap " << this->_name << "died" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->_hitPoint <= 0)
        std::cout << "You don't have enough hit point" << std::endl;
    else if (this->_energyPoint <= 0)
        std::cout << "You don't have enough energy point" << std::endl;    
    else
    {
        this->_hitPoint += amount;
        std::cout << "You've repaired yourself, what a coward" << std::endl;
    }
}

/* getter functions */

std::string const ClapTrap::getName() const {
    return  this->_name;
}

int ClapTrap::getHitPoint() const {
    return  this->_hitPoint;
}
int ClapTrap::getEnergyPoint() const {
    return  this->_energyPoint;
}
int ClapTrap::getAttackDamage() const {
    return  this->_attackDmg;
}

/* setter functions */

void ClapTrap::setName(std::string& name){
    this->_name = name;
}
void ClapTrap::setHitPoint(unsigned int amount){
    this->_hitPoint = amount;
}
void ClapTrap::setEnergyPoint(unsigned int amount){
    this->_energyPoint = amount;
}
void ClapTrap::setAttackDamage(unsigned int amount){
    this->_attackDmg = amount;
}