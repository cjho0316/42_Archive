# ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <stdexcept>
#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;

	public:
		/* OCF */
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &copy);

		/* getter, setter */
		const std::string getName() const;
		int getGrade() const;

		/* member fuctions */
		void incrementGrade();
		void decrementGrade();
		void signForm(const Form& f) const;

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

std::ostream &operator<<(std::ostream &str, Bureaucrat const &b);

#endif