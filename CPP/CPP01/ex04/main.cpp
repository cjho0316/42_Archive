#include <iostream>
#include "Sed.hpp"

int	main(int argc,	char **argv) {
	if (argc != 4) {
		std::cout << "error: bad arguments" << std::endl;
		return 1;
	}
	Sed	sed(argv);
	sed.change();
	return 0;
}