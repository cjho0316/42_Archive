#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
	
	Zombie* zombiearmy = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombiearmy[i].setName(name);
	}
	
	return zombiearmy;
}