#include "Zombie.hpp"

Zombie* newZombie(std::string str);
void randomChump(std::string str);

int main(void)
{
	Zombie *z1 = newZombie("heapZombie");
	z1->announce();

	randomChump("stackZombie");

	delete z1;
	return (0);
}