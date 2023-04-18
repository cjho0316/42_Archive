# ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string ideas[100];
		
	public:
		/* OCF */
		Brain();
		Brain(std::string type);
        Brain(Brain const &copy);
		~Brain();
		Brain& operator=(Brain const &copy);

		std::string getIdea(int i) const;
		void setIdea(int i, std::string idea);

};

#endif
