#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << "------------------------------------------------------------------------" << std::endl;
	{
		try
		{
			std::cout << "CASE1: PresidentialPardonForm" << std::endl;
			{
				Bureaucrat bureau1("jang-cho", 25);
				Bureaucrat bureau2("sechung", 5);
				AForm*	form1 = new PresidentialPardonForm("jincpark");

				std::cout << bureau1 << std::endl;
				std::cout << bureau2 << std::endl;

				form1->beSigned(bureau1); // if not getSigned throw 'ExecuteNotSignedException'
				bureau1.signForm(*form1);
				bureau2.executeForm(*form1);
				delete form1;
			}
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
			std::cout << "CASE2: RobotomyRequestForm" << std::endl;
			{
				Bureaucrat bureau1("jang-cho", 72);
				Bureaucrat bureau2("sechung", 45);
	
				AForm* form1 = new RobotomyRequestForm("jincpark");
				
				std::cout << bureau1 << std::endl;
				std::cout << bureau2 << std::endl;
				form1->beSigned(bureau1);	// if not getSigned throw 'ExecuteNotSignedException'
				bureau1.signForm(*form1);
				bureau2.executeForm(*form1);
				delete form1;
			}
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
			std::cout << "CASE3: ShrubberyCreationForm" << std::endl;
			{
				Bureaucrat bureau1("jang-cho", 145);
				Bureaucrat bureau2("sechung", 137);
				AForm*	form1 = new ShrubberyCreationForm("jincpark");

				std::cout << bureau1 << std::endl;
				std::cout << bureau2 << std::endl;

				form1->beSigned(bureau1); // if not getSigned throw 'ExecuteNotSignedException'
				bureau1.signForm(*form1);
				bureau2.executeForm(*form1);
				delete form1;
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}