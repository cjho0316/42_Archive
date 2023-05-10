#include "Intern.hpp"

/* OCF */
Intern::Intern() {
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern &copy) {
	std::cout << "Intern copied" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destructor" << std::endl;
}

Intern &Intern::operator=(const Intern &copy) {
	// if (this != &copy)
	// 	this->_grade = copy._grade;
	return (*this);
}

/* getter, setter */

/* member fuctions */

void makeForm(std::string &form, std::string target) {

}

/* exception class */


// std::ostream& operator<< (std::ostream &str, Intern const &b) {
// 	str << b.getName() << " bureaucrat grade " << b.getGrade() << std::endl;
// 	return str;
// }