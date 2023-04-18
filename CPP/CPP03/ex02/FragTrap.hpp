#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    private:
    public:
		FragTrap();
		FragTrap(std::string const &_name);
		FragTrap(FragTrap const &copy);
		~FragTrap();
		FragTrap& operator=(FragTrap const &copy);
		
		void attack(const std::string& target);
		void highFivesGuys();
};

#endif
