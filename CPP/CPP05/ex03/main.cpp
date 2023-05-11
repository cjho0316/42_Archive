#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern intern;

	std::cout << "------------------------------------------------------------------------" << std::endl;
	{
		try
		{
			std::cout << "CASE0: InvalidErrorException" << std::endl;
			Bureaucrat bureau1("jang-cho", 1);
			AForm* form1 = intern.makeForm("Invalid form", "jincpark");

			form1->beSigned(bureau1);	// if not getSigned throw 'ExecuteNotSignedException'
			bureau1.signForm(*form1);
			bureau1.executeForm(*form1);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "------------------------------------------------------------------------" << std::endl;
	{
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
	}
	std::cout << "------------------------------------------------------------------------" << std::endl;
	{
		try
		{		
			std::cout << "CASE2: Presidential PardonForm" << std::endl;
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
	}
	std::cout << "------------------------------------------------------------------------" << std::endl;
	{
		try
		{
			std::cout << "CASE3: RobotomyRequestForm" << std::endl;
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
	}
	return 0;
}