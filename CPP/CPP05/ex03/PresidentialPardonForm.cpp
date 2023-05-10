#include "PresidentialPardonForm.hpp"

/* OCF */
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target(NULL) {
	std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm w/ name and grade(Sign, Execute) created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExecute()), _target(copy._target) {
	std::cout << "PresidentialPardonForm copied" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	if (this != &copy) {
		this->_target = copy._target;
	}
	return (*this);
}

/* member functions */

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (this->getGradeExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	else if (this->getSigned() == false)
		throw AForm::ExecuteNotSignedException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
