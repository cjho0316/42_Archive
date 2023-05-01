#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain Consturctor created" << std::endl;
	for (int i = 0; i < 100; i++){
		this->ideas[i] = "nothing";
	}
}

Brain::Brain(Brain const &copy){
	std::cout << "Brain Copy Consturctor created" << std::endl;
	for (int i = 0; i < 100; i++){
		this->ideas[i] = copy.ideas[i];
	}
}

Brain::~Brain(){
	std::cout << "Brain Destructor" << std::endl;
}

Brain& Brain::operator=(Brain const &copy){
	std::cout << "Brain Copy constructor operator created" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return *this;
}

std::string Brain::getIdea(int i) const {
	return (this->ideas[i]);
}

void Brain::setIdea(int i, std::string idea){
	this->ideas[i] = idea;
}
