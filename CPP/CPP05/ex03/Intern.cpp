#include "Intern.hpp"

const std::string Intern::_classArrayName[3] = {
    "presidential pardon",
    "robotomy request",
    "shrubbery createion"
};

/* OCF */
Intern::Intern() {
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern &copy) {
    (void)copy;
	std::cout << "Intern copied" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destructor" << std::endl;
}

Intern &Intern::operator=(const Intern &copy) {
	return (*this);
}

/* member fuctions */

AForm*	(Intern::*func[3])(const std::string &) const = {
	&Intern::newShrubberyCreationForm,
	&Intern::newRobotomyRequestForm,
	&Intern::newPresidentialPardonForm
};

AForm* Intern::newPresidentialPardonForm(const std::string &target) {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::newRobotomyRequestForm(const std::string &target) {
    return (new RobotomyRequestForm(target));
}

AForm* Intern::newShrubberyCreationForm(const std::string &target) {
    return (new ShrubberyCreationForm(target));
}

/* exception class */
const char* Intern::ClassDoesNotExist::what() const throw() {
    return ("error: class does not exist!!!");
};

// std::ostream& operator<< (std::ostream &str, Intern const &b) {
// 	str << b.getName() << " bureaucrat grade " << b.getGrade() << std::endl;
// 	return str;
// }