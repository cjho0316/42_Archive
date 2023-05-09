#include "AForm.hpp"

/* OCF */
AForm::AForm(): _name(NULL), _signed(false), _gradeSign(-1), _gradeExecute(-1) {
	std::cout << "AForm created" << std::endl;
}

AForm::AForm(const std::string name, const int gradeSign, const int gradeExecute): _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	std::cout << "AForm w/ name and grade(Sign, Execute) created" << std::endl;
	this->_signed = false;
	if (this->_gradeSign < 1 || this->_gradeExecute < 1)
		throw AForm::GradeTooHighException();
	else if (this->_gradeSign > 150 || this->_gradeExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy): _name(copy._name), _signed(copy._signed), _gradeSign(copy._gradeSign), _gradeExecute(copy._gradeExecute) {
	std::cout << "AForm copied" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm destructor" << std::endl;
}

AForm &AForm::operator=(const AForm &copy) {
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

/* getter, setter */

const std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getSigned() const {
	return this->_signed;
}

int AForm::getGradeSign() const{
    return this->_gradeSign;
}

int AForm::getGradeExecute() const{
    return this->_gradeExecute;
}

/* member fuctions */

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() <= getGradeSign())
        this->_signed = true;
    else
        throw AForm::GradeTooLowException();
}

/* exception class */

const char *AForm::GradeTooHighException::what() const throw() {
	return ("error : your grade set is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("error : your grade set is too low");	
}

const char *AForm::ExecuteNotSignedException::what() const throw() {
	return ("error : your execution form is not Signed yet");
}

const char *AForm::ExecuteGradeTooLowException::what() const throw() {
	return ("error : your execution grade is too low for Signing");	
}

/* operator overloading (global) */

std::ostream& operator<< (std::ostream &str, AForm const &f) {
	str << f.getName() << "  " << f.getSigned() << "  " << f.getGradeSign() << "  " << f.getGradeExecute() << "  " << std::endl;
	return str;
}