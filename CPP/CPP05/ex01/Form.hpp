# ifndef FORM_H
#define FORM_H

#include <stdexcept>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string   _name;
		bool                _signed;
        const int           _gradeSign;
        const int           _gradeExecute;

	public:
		/* OCF */
		Form();
        Form(const std::string name, const int gradeSign, const int gradeExecute);
		Form(const Form &copy);
		~Form();
		Form &operator=(const Form &copy);

		/* getter, setter */
		const std::string getName() const;
		bool getSigned() const;
        int getGradeSign() const;
        int getGradeExecute() const;


		/* member fuctions */
        void beSigned(const Bureaucrat &b);

		/* exception class */
		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw(); // return what() for returning "explanation string" 
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &str, Form const &b);

#endif