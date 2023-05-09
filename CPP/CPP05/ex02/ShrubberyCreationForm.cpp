#include "ShrubberyCreationForm.hpp"

/* OCF */
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target(NULL) {
	std::cout << "ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm w/ name and grade(Sign, Execute) created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExecute()), _target(copy._target) {
	std::cout << "ShrubberyCreationForm copied" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	if (this != &copy) {
		this->_target = copy._target;
	}
	return (*this);
}

/* exception class */

const char *ShrubberyCreationForm::ShrubberyFileOpenFailure::what() const throw() {
	return ("error : file open is failed");
}

/* member functions */

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
	if (this->getGradeExecute() < executor.getGrade())
		throw AForm::ExecuteGradeTooLowException();
	else if (getSigned() == false)
		throw AForm::ExecuteNotSignedException();
	
	std::ofstream ofs;
	ofs.open(_target + "_shrubbery");
	if (ofs.is_open() == false)
		throw ShrubberyCreationForm::ShrubberyFileOpenFailure();
	
	ofs << "\n\
	                              # #### ####\n\
                                ### \\/#|### |/####\n\
                           ##\\/#/ \\||/##/_/##/_#\n\
                             ###  \\/###|/ \\/ # ###\n\
                           ##_\\_#\\_\\## | #/###_/_####\n\
                          ## #### # \\ #| /  #### ##/##\n\
                           __#_--###`  |{,###---###-~\n\
                                     \\ }{\n\
                                      }}{\n\
                                      }}{\n\
                                      {{}\n\
                                , -=-~{ .-^- _\n\
                                      `}\n\
                                       {\n"
	<< std::endl;

	ofs.close();
}