#include "Harl.hpp"

int main(int ac, char **av)
{
	
	Harl harlmoney;

	if (ac == 2)
		harlmoney.complainSwitch(av[1]);
	else
		harlmoney.stfu();

	return (0);
}