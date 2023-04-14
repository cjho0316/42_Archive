#include "Harl.hpp"

int main(int ac, char **av)
{
	(void)ac;
	Harl harlmoney;

	std::cout << "Whining level : (DEBUG / INFO / WARNING / ERROR)" << std::endl;
	harlmoney.complain(av[1]);

	return (0);
}