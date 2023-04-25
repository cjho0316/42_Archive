#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	std::cout << "MateriaSource Default Constructor Called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy): _name(copy._name){
	for (int i = 0; i < 4; i++)
		delete this->_materias[i];
	for (int i = 0; i < 4; i++)
		this->_materias[i] = copy._materias[i];
	std::cout << "MateriaSource Copy Constructor Called" << std::endl;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)
		delete this->_materias[i];	
	std::cout << "MateriaSource Destructor Called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy){
	for (int i = 0; i < 4; i++)
		delete this->_materias[i];
	for (int i = 0; i < 4; i++)
		this->_materias[i] = copy._materias[i];
	this->_name = copy._name;
	std::cout << "MateriaSource Copy operator Called" << std::endl;	
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m){
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->materia[i] = materia;
			std::cout << "MateriaSource leaned" << materia->getType() << std::endl;
			return ;
		}
		std::cout << "MateriaSource is full" << std::endl;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type){
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type)
		{
			std::cout << "MateriaSource created" << type << std::endl;
			return (this->materia[i]->clone());
		}
		std::cout << "Cannot create materias" << type << std::endl;
		return (NULL);
	}
}
