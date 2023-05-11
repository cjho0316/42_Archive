#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "------------------------------------------------------------------------" << std::endl;
	{
		Intern intern;
		try
		{
			std::cout << "CASE1: ShrubberyCreationForm" << std::endl;
			Bureaucrat bureau1("jang-cho", 1);
			AForm* form1 = intern.makeForm("shrubbery creation", "jincpark");

			form1->beSigned(bureau1);	// if not getSigned throw 'ExecuteNotSignedException'
			bureau1.signForm(*form1);
			bureau1.executeForm(*form1);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete form1;
	}
	std::cout << "------------------------------------------------------------------------" << std::endl;
	{
		Intern intern;
		try
		{		
			std::cout << "CASE2: RobotomyRequestForm" << std::endl;
			Bureaucrat bureau1("jang-cho", 1);
			AForm* form1 = intern.makeForm("robotomy request", "jincpark");

			form1->beSigned(bureau1);	// if not getSigned throw 'ExecuteNotSignedException'
			bureau1.signForm(*form1);
			bureau1.executeForm(*form1);	
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete form1;
	}
	std::cout << "------------------------------------------------------------------------" << std::endl;
	{
		Intern intern;
		try
		{
			std::cout << "CASE3: Presidentia lPardonForm" << std::endl;
			Bureaucrat bureau1("jang-cho", 1);
			AForm* form1 = intern.makeForm("presidential pardon", "jincpark");

			form1->beSigned(bureau1);	// if not getSigned throw 'ExecuteNotSignedException'
			bureau1.signForm(*form1);
			bureau1.executeForm(*form1);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete form1;
	}
	return 0;
}