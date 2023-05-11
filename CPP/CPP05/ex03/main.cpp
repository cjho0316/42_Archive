#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern intern;

	std::cout << "------------------------------------------------------------------------" << std::endl;
	{
		std::cout << "CASE0: InvalidErrorException" << std::endl;
		Bureaucrat bureau1("jang-cho", 1);
		AForm* form1 = intern.makeForm("Invalid form", "jincpark");
		try
		{
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
		std::cout << "CASE1: ShrubberyCreationForm" << std::endl;
		Bureaucrat bureau1("jang-cho", 1);
		AForm* form2 = intern.makeForm("shrubbery creation", "jincpark");
		try
		{
			form2->beSigned(bureau1);	// if not getSigned throw 'ExecuteNotSignedException'
			bureau1.signForm(*form2);
			bureau1.executeForm(*form2);			
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete form2;
	}
	std::cout << "------------------------------------------------------------------------" << std::endl;
	{
		std::cout << "CASE2: Presidential PardonForm" << std::endl;
		Bureaucrat bureau1("jang-cho", 1);
		AForm* form3 = intern.makeForm("presidential pardon", "jincpark");
		try
		{		
			form3->beSigned(bureau1);	// if not getSigned throw 'ExecuteNotSignedException'
			bureau1.signForm(*form3);
			bureau1.executeForm(*form3);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete form3;
	}
	std::cout << "------------------------------------------------------------------------" << std::endl;
	{
		std::cout << "CASE3: RobotomyRequestForm" << std::endl;
		Bureaucrat bureau1("jang-cho", 1);
		AForm* form4 = intern.makeForm("robotomy request", "jincpark");
		try
		{
			form4->beSigned(bureau1);	// if not getSigned throw 'ExecuteNotSignedException'
			bureau1.signForm(*form4);
			bureau1.executeForm(*form4);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete form4;
	}
	return 0;
}