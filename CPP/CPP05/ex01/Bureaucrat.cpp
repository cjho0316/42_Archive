#include "Bureaucrat.hpp"

/* OCF */
Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {
	std::cout << "Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade) {
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat w/ name and grade created" << std::endl;
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

void	Bureaucrat::signForm(const Form& f) const
{
	if (f.getSigned() == true && this->_grade <= f.getGradeSign())
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	else if (f.getSigned() == true && this->_grade > f.getGradeSign())
		std::cout << this->_name << " couldn't sign " << f.getName() \
			<< " because his/her grade is lower than it's grade " << std::endl;
	else if (f.getSigned() == false)
		std::cout << this->_name << " couldn't sign " << f.getName() \
			<< " because form not signed yet" << std::endl;
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