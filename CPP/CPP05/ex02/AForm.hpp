# ifndef AFORM_H
#define AFORM_H

#include <stdexcept>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string   _name;
		bool                _signed;
        const int           _gradeSign;
        const int           _gradeExecute;

	public:
		/* OCF */
		AForm();
        AForm(const std::string name, const int gradeSign, const int gradeExecute);
		AForm(const AForm &copy);
		virtual ~AForm();
		AForm &operator=(const AForm &copy);

		/* getter, setter */
		const std::string getName() const;
		bool getSigned() const;
        int getGradeSign() const;
        int getGradeExecute() const;


		/* member fuctions */
        void beSigned(const Bureaucrat &b);
		virtual void execute(Bureaucrat const &executor) const = 0;

		/* exception class */
		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw(); // return what() for returning "explanation string" 
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class ExecuteNotSignedException : public std::exception{
			public:
				const char* what() const throw();
		};

		class ExecuteGradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &str, AForm const &b);

#endif