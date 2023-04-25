#include "Character.hpp"

Character::Character(){
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character Default Constructor Called" << std::endl;
}

Character::Character(std::string name): _name(name){
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character Constructor Called" << std::endl;
}

Character::Character(const Character &copy): _name(copy._name){
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = copy._inventory[i];
	std::cout << "Character Copy Constructor Called" << std::endl;
}

Character::~Character(){
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];	
	std::cout << "Character Destructor Called" << std::endl;
}

Character &Character::operator=(const Character &copy){
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = copy._inventory[i];
	this->_name = copy._name;
	std::cout << "Character Copy operator Called" << std::endl;	
	return (*this);
}

std::string const &Character::getName() const{
	return this->_name;
}

void Character::equip(AMateria *m){
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << "character " << this->_name << " equipped" << m->getType() <<std::endl;
			return ;
		}
	}
	std::cout << "character " << this->_name << " 's inventory is full" <<std::endl;
}

void Character::unequip(int idx){
	if (idx < 0 || idx > 3)
	{
		std::cout << "put oppropriate idx" << std::endl;
		return;	
	}
	this->_inventory = NULL;
	std::cout << "character " << this->_name << " unequipped " << idx <<std::endl;
}

// void Character::use(int idx, ICharacter &target){
// 	std::cout << "character" << this->_name << " ";
// 	this->_inventory[idx]->use(target);
// }
