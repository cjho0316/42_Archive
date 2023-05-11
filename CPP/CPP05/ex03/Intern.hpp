# ifndef INTERN_H
#define INTERN_H

#include <stdexcept>
#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;
class Intern {
	private:
        static const std::string _classArrayName[3];
        static AForm* (Intern::*func[3])(const std::string&) const;

	public:
		/* OCF */
		Intern();
		Intern(const std::string name, int grade);
		Intern(const Intern &copy);
		~Intern();
		Intern &operator=(const Intern &copy);

		/* member fuctions */
        AForm* makeForm(const std::string &form, const std::string &target) const;
        AForm* newPresidentialPardonForm(const std::string &target) const;
        AForm* newRobotomyRequestForm(const std::string &target) const;
        AForm* newShrubberyCreationForm(const std::string &target) const;

		/* exception class */
		class ClassDoesNotExistException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &str, Intern const &b);

#endif