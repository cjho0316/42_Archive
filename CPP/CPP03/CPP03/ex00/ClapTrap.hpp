#ifndef ClapTrap_H
# define ClapTrap_H

#include <iostream>
#include <string>

class ClapTrap
{
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;


	public:
		ClapTrap(std::string _name);
		~ClapTrap();
		ClapTrap(ClapTrap const &copy);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif
