#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
    private:
    public:
		FragTrap();
		FragTrap(std::string const &_name);
		FragTrap(FragTrap const &copy);
		virtual ~FragTrap();
		FragTrap& operator=(FragTrap const &copy);
		
		void highFivesGuys();
};

#endif
