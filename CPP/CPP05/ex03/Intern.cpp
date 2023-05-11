#include "Intern.hpp"

/* static variable initalization */

const std::string Intern::_classArrayName[3] = {
    "presidential pardon",
    "robotomy request",
    "shrubbery creation"
};

AForm* (Intern::*Intern::func[3])(const std::string&) const = {
    &Intern::newPresidentialPardonForm,
    &Intern::newRobotomyRequestForm,
    &Intern::newShrubberyCreationForm
};

/* OCF */
Intern::Intern() {
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern &copy) {
    (void) copy;
	std::cout << "Intern copied" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destructor" << std::endl;
}

Intern &Intern::operator=(const Intern &copy) {
    (void) copy;
	return (*this);
}

/* member fuctions */
AForm* Intern::makeForm(const std::string &form, const std::string &target) const {
    AForm* ptr = NULL;
    for (int i = 0; i < 3; i++)
    {
        if (form == this->_classArrayName[i])
        {
            ptr = (this->*func[i])(target);
        }
    }
    if (ptr == NULL)
        throw Intern::ClassDoesNotExistException();
    return ptr;
}

AForm* Intern::newPresidentialPardonForm(const std::string &target) const {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::newRobotomyRequestForm(const std::string &target) const {
    return (new RobotomyRequestForm(target));
}

AForm* Intern::newShrubberyCreationForm(const std::string &target) const {
    return (new ShrubberyCreationForm(target));
}

/* exception class */
const char* Intern::ClassDoesNotExistException::what() const throw() {
    return ("error: class does not exist!!!");
};
