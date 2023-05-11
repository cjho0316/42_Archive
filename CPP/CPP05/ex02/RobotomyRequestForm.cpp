#include "RobotomyRequestForm.hpp"

/* OCF */
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target(NULL) {
	std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm w/ name and grade(Sign, Execute) created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExecute()), _target(copy._target) {
	std::cout << "RobotomyRequestForm copied" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	if (this != &copy) {
		this->_target = copy._target;
	}
	return (*this);
}

/* member functions */

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	std::cout << "* DRRRRRRRIIIIIILLLLLLLLLIIINNNGGGGGG NOOOOIIZZZZZEEEE *" << std::endl;
	if (this->getGradeExecute() < executor.getGrade())
		throw AForm::ExecuteGradeTooLowException();
	else if (getSigned() == false)
		throw AForm::ExecuteNotSignedException();

	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " Robotomized successed!! " << std::endl;
	else
		std::cout << this->_target << " Robotomized failed " << std::endl;
}
