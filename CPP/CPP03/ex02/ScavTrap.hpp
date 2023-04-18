#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    private:
    public:
		ScavTrap();
		ScavTrap(std::string const &_name);
		ScavTrap(ScavTrap const &copy);
		~ScavTrap();
		ScavTrap& operator=(ScavTrap const &copy);
		
		void attack(const std::string& target);
		void guardGate();
};

#endif
