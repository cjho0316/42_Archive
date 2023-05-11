#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << "------------------------------------------------------------------------" << std::endl;
	{
		std::cout << "CASE1: PresidentialPardonForm" << std::endl;
		Bureaucrat bureau1("jang-cho", 25);
		Bureaucrat bureau2("sechung", 5);
		AForm*	form1 = new PresidentialPardonForm("jincpark");
		try
		{
			{
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
		delete form1;
	}
	std::cout << "------------------------------------------------------------------------" << std::endl;
	{
		std::cout << "CASE2: RobotomyRequestForm" << std::endl;
		Bureaucrat bureau1("jang-cho", 72);
		Bureaucrat bureau2("sechung", 45);

		AForm* form2 = new RobotomyRequestForm("jincpark");
		try
		{
			{
				std::cout << bureau1 << std::endl;
				std::cout << bureau2 << std::endl;
				form2->beSigned(bureau1);	// if not getSigned throw 'ExecuteNotSignedException'
				bureau1.signForm(*form2);
				bureau2.executeForm(*form2);
				delete form2;
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete form2;
	}
	std::cout << "------------------------------------------------------------------------" << std::endl;
	{
		Bureaucrat bureau1("jang-cho", 145);
		Bureaucrat bureau2("sechung", 137);
		AForm*	form3 = new ShrubberyCreationForm("jincpark");
		try
		{
			std::cout << "CASE3: ShrubberyCreationForm" << std::endl;
			{

				std::cout << bureau1 << std::endl;
				std::cout << bureau2 << std::endl;

				form3->beSigned(bureau1); // if not getSigned throw 'ExecuteNotSignedException'
				bureau1.signForm(*form3);
				bureau2.executeForm(*form3);
				delete form3;
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete form3;
	}
	return 0;
}