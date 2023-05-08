#include "Form.hpp"

/* OCF */
Form::Form(): _name(NULL), _signed(false), _gradeSign(-1), _gradeExecute(-1) {
	std::cout << "Form created" << std::endl;
}

Form::Form(const std::string name, const int gradeSign, const int gradeExecute): _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	std::cout << "Form w/ name and grade(Sign, Execute) created" << std::endl;
	if (this->_gradeSign < 1 || this->_gradeExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->_gradeSign > 150 || this->_gradeExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy): _name(copy._name), _signed(copy._signed), _gradeSign(copy._gradeSign), _gradeExecute(copy._gradeExecute) {
	std::cout << "Form copied" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor" << std::endl;
}

Form &Form::operator=(const Form &copy) {
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

/* getter, setter */

const std::string Form::getName() const {
	return this->_name;
}

bool Form::getSigned() const {
	return this->_signed;
}

int Form::getGradeSign() const{
    return this->_gradeSign;
}

int Form::getGradeExecute() const{
    return this->_gradeExecute;
}

/* member fuctions */

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() < getGradeSign())
        this->_signed = true;
    else
        throw Form::GradeTooLowException();
}

/* exception class */

const char *Form::GradeTooHighException::what() const throw() {
	return ("error : your grade set is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("error : your grade set is too low");	
}

std::ostream& operator<< (std::ostream &str, Form const &f) {
	str << f.getName() << "  " << f.getSigned() << "  " << f.getGradeSign() << "  " << f.getGradeExecute() << "  " << std::endl;
	return str;
}
