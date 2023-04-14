#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
	int amount;
	std::string name;

	std::cout << "How many zombie army do you need?" << std::endl;
	std::cin >> amount;
	std::cout << "and armyname is?" << std::endl;
	std::cin >> name; 

	Zombie *z1 = zombieHorde(amount, name);
	
	for (int i = 0; i < amount; i++)
		z1[i].announce();

	delete[] z1;
	return (0);
}