# ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <stdexcept>
#include <iostream>
#include <string>
#include <fstream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"


class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;

	public:
		/* OCF */
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

		/* member fuctions */
		void execute(Bureaucrat const &executor) const;

		/* exception class */
		class ShrubberyFileOpenFailure : public std::exception {
			public:
				const char* what() const throw(); // return what() for returning "explanation string" 
		};
};

#endif