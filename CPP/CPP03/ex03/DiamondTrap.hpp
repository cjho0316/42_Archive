#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    private:
		std::string _name;
    public:
		DiamondTrap();
		DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &copy);
		~DiamondTrap();

		DiamondTrap& operator=(DiamondTrap const &copy);
		
		void whoAmI();
};

#endif
