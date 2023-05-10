# ifndef INTERN_H
#define INTERN_H

#include <stdexcept>
#include <iostream>
#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	private:

	public:
		/* OCF */
		Intern();
		Intern(const std::string name, int grade);
		Intern(const Intern &copy);
		~Intern();
		Intern &operator=(const Intern &copy);

		/* getter, setter */

		/* member fuctions */
        void makeForm(std::string &form, std::string target);

};

std::ostream &operator<<(std::ostream &str, Intern const &b);

#endif