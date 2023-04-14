#ifndef ClapTrap_H
# define ClapTrap_H

#include <iostream>
#include <string>

class ClapTrap
{
	private:
		std::string name;


	public:
		ClapTrap();
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif
