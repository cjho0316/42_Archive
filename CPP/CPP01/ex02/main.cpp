#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "stringptr addr : " << stringPTR << std::endl;
	std::cout << "stringref addr : " << &stringREF << std::endl;

	std::cout << "stringptr val : " << *stringPTR << std::endl;
	std::cout << "stringref val : " << stringREF << std::endl;

	return (0);
}