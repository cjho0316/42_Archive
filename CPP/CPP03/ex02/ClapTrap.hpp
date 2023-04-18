#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string _name;
        int _hitPoint;
        int _energyPoint;
        int _attackDmg;

	public:
		ClapTrap();
		ClapTrap(std::string _name);
        ClapTrap(ClapTrap const &copy); // copy operator
		~ClapTrap();

        ClapTrap& operator=(ClapTrap const &copy);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

        std::string const getName() const;
        int getHitPoint() const;
        int getEnergyPoint() const;
        int getAttackDamage() const;

        void setName(std::string& name);
        void setHitPoint(unsigned int const amount);
        void setAttackDamage(unsigned int const amount);
        void setEnergyPoint(unsigned int const amount);

};

#endif
