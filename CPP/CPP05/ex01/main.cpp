#include "Bureaucrat.hpp"

int	main(void)
{
	{
		try
		{
			std::cout << "CASE0 : Form's grade is out of bound" << std::endl;
			{
				Form form1("test1", 1, 150);
				std::cout << form1 << std::endl;

				Form form2("test2", 0, 151);
				std::cout << form2 << std::endl;
				// ignore every line before exception
				std::cout << form1 << std::endl;
				std::cout << form2 << std::endl;
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
			std::cout << "CASE1 : Form's grade is out of bound" << std::endl;
			Form form1("test1", 1, 150);
			std::cout << form1 << std::endl;

			Form form2("test2", 0, 151);
			std::cout << form2 << std::endl;
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
			std::cout << "CASE2 : bureau 'sechung' tries to beSigned higher grade form" << std::endl;
			Form form1("test1", 42, 150);
			Bureaucrat bureau1("jang-cho", 24);
			Bureaucrat bureau2("sechung", 43);			

			std::cout << form1 << std::endl;
			std::cout << bureau1 << std::endl;
			std::cout << bureau2 << std::endl;
			
			form1.beSigned(bureau2); //'sechung' can't beSigned because of his grade lower than form

			//exception error will catch, can't go any further

			form1.beSigned(bureau1); // 'jang-cho' can sign because his grade is higher than form

			bureau1.signForm(form1);
			bureau2.signForm(form1);

			std::cout << form1 << std::endl;
			std::cout << bureau1 << std::endl;
			std::cout << bureau2 << std::endl;

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
			std::cout << "CASE3 : bureau 'jang-cho' beSigned the form" << std::endl;
			Form form1("test1", 42, 150);
			Bureaucrat bureau1("jang-cho", 24);
			Bureaucrat bureau2("sechung", 43);

			std::cout << form1 << std::endl;
			std::cout << bureau1 << std::endl;
			std::cout << bureau2 << std::endl;
			
			form1.beSigned(bureau1); // 'jang-cho' can sign because his grade is higher than form
			bureau2.signForm(form1);
			bureau2.incrementGrade();
			bureau2.signForm(form1);

			std::cout << form1 << std::endl;
			std::cout << bureau1 << std::endl;
			std::cout << bureau2 << std::endl;

		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}

// 	{
// 		try
// 		{
// 			std::cout << "*** case1 : form's grade too high ***" << std::endl;
// 			{
// 				Form test1("test1", 1, 100);
// 				std::cout << test1 << std::endl;

// 				Form test2("test2", 0, 100);
// 				std::cout << test2 << std::endl;
// 			}
// 		}
// 		catch (const std::exception& e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 	}
// 	std::cout << std::endl;
// 	{
// 		try
// 		{
// 			std::cout << "*** case2 : form's grade too low ***" << std::endl;
// 			{
// 				Form test1("test1", 150, 100);
// 				std::cout << test1 << std::endl;

// 				Form test2("test1", 151, 100);
// 				std::cout << test1 << std::endl;
// 			}
// 		}
// 		catch (const std::exception& e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 	}
// 	std::cout << std::endl;
// 	{
// 		try
// 		{
// 			std::cout << "*** case3 : testing beSigned() ***" << std::endl;
// 			{
// 				Bureaucrat boss("boss", 101);
// 				std::cout << boss << std::endl;

// 				Form form1("form1", 130, 100);
// 				std::cout << form1 << std::endl;
// 				form1.beSigned(boss);
// 				std::cout << "signing success" << std::endl;

// 				Form form2("form2", 100, 100);
// 				form2.beSigned(boss);
// 				std::cout << form2 << std::endl;
// 			}
// 		}
// 		catch (const std::exception& e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 	}
// 	std::cout << std::endl;
// 	{
// 		std::cout << "*** case4 : testing signForm() ***" << std::endl;
// 		Bureaucrat boss("boss", 101);
// 		try
// 		{
// 			{
// 				std::cout << boss << std::endl;
// 				Form form1("form1", 101, 100);
// 				std::cout << form1 << std::endl;
// 				boss.signForm(form1);
// 				form1.beSigned(boss);
// 				boss.signForm(form1);

// 				Form form2("form2", 100, 100);
// 				std::cout << form2 << std::endl;
// 				boss.signForm(form2);
// 				form2.beSigned(boss);
// 				boss.signForm(form2);
// 			}
// 		}
// 		catch (const std::exception& e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 		try
// 		{
// 			Form form3("form3", 149, 100);
// 			std::cout << form3 << std::endl;
// 			form3.beSigned(boss);
// 			Bureaucrat jack("jack", 150);
// 			jack.signForm(form3);
// 		}
// 		catch (const std::exception& e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 	}
// 	return 0;
// }

