#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string str);
		~Zombie(void);

		void announce(void);
		Zombie* newZombie(std::string str);
		void randomChump(std::string str);
		
};

#endif