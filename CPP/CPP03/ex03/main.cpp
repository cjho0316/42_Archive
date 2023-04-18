#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap a("[THE DIAMONDTRAP]");
	DiamondTrap b = a;

	std::cout << a.getName() << std::endl
			<< a.getHitPoint() << std::endl
			<< a.getEnergyPoint() << std::endl
			<< a.getAttackDamage() << std::endl;

	a.attack("Handsome Jack");
	std::cout << std::endl;
	a.takeDamage(8);
	std::cout << std::endl;
	a.beRepaired(4);
	std::cout << std::endl;
	a.attack("Psycho");
	std::cout << std::endl;
	a.takeDamage(8);
	std::cout << std::endl;
	a.beRepaired(4);
	std::cout << std::endl;
	a.attack("Zer0");
	std::cout << std::endl;
	a.whoAmI();
	std::cout << std::endl;

	return 0;
}