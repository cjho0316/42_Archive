#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: Invalid Input arguments" << std::endl;
		return 0;
	}
	std::string filename = av[1];
	std::ifstream file(filename.c_str(), std::ifstream::in);
	if (!file.is_open()) {
		std::cerr << "Error: Invalid File Open" << std::endl;
		return 0;
	}
	while (!file.eof()) {
		std::string line;
		std::getline(file, line);
		
		std::map<std::string, float> dataMap;
		parseLine(line, dataMap); 	// parse and insert into map

		std::cout << line << std::endl;
	}



	file.close();
	return 0;
};