#include "contact.hpp"
#include "phonebook.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string userinput;
	while (true)
	{
		std::cout << "What Would you like to do? (ADD / SEARCH / EXIT)" << std::endl;
		std::getline(std::cin, userinput);
		if (userinput == "EXIT")
		{
			std::cout << "Terminate the program" << std::endl;
			break;
		}
		else if (userinput == "ADD")
		{
			phonebook.Add();
		}
		else if (userinput == "SEARCH")
		{
			phonebook.Search();
		}
	}
}
