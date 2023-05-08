#include "Bureaucrat.hpp"

int	main(void)
{
	{
		try
		{
			std::cout << "CASE0 : set grade too low" << std::endl;
			{
				Bureaucrat test("test", 151);
				std::cout << test << std::endl;
				// ignore every line before exception
				test.decrementGrade();
				std::cout << test << std::endl;
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;	
	{
		try
		{
			std::cout << "CASE1 : grade too low" << std::endl;
			{
				Bureaucrat test("test", 150);
				std::cout << test << std::endl;
				test.decrementGrade();
				std::cout << test << std::endl;
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
			std::cout << "CASE2 : set grade too high" << std::endl;
			{
				Bureaucrat test("test", -1);
				std::cout << test << std::endl;
				// ignore every line before exception
				test.decrementGrade();
				std::cout << test << std::endl;
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			std::cout << "CASE3 : grade too low" << std::endl;
			{
				Bureaucrat test("test", 1);
				std::cout << test << std::endl;
				test.incrementGrade();
				std::cout << test << std::endl;
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
