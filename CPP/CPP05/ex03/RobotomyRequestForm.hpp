# ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <stdexcept>
#include <iostream>
#include <string>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"


class RobotomyRequestForm : public AForm {
	private:
		std::string _target;

	public:
		/* OCF */
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

		/* member fuctions */
		void execute(Bureaucrat const &executor) const;

};

#endif