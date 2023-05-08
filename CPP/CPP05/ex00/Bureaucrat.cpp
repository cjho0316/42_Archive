#include "Bureaucrat.hpp"

/* OCF */
Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {
	std::cout << "Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade) {
	std::cout << "Bureaucrat w/ name and grade created" << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade) {
	std::cout << "Bureaucrat copied" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	if (this != &copy)
		this->_grade = copy._grade;
	return (*this);
}

/* getter, setter */

const std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

/* member fuctions */

void Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		--(this->_grade);
}

void Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		++(this->_grade);
}

/* exception class */

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("error : your grade set is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("error : your grade set is too low");	
}

std::ostream& operator<< (std::ostream &str, Bureaucrat const &b) {
	str << b.getName() << " bureaucrat grade " << b.getGrade() << std::endl;
	return str;
}