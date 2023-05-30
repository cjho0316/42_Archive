#include "BitcoinExchange.hpp"

std::map<std::string, float> csvToMap(std::string path) {
	std::ifstream file(path.c_str(), std::ifstream::in);
	if (!file.is_open()) {
		std::cerr << "Error: Invalid File Open" << std::endl;
		std::exit(1); ;
	}
	std::map<std::string, float> result;
	std::string line;
	while (!file.eof()) {
		std::getline(file, line);
		if (line == "date,exchange_rate")
			continue;
		size_t before_comma_idx = line.find(',');
		// size_t after_comma_idx = line.find(',', before_comma_idx + 1);
		// std::cout << "before_comma_idx: " << before_comma_idx << std::endl;
		// std::cout << "after_comma_idx: " << after_comma_idx << std::endl;

		std::string before_comma = line.substr(0, before_comma_idx);		
		std::string after_comma = line.substr(before_comma_idx + 1);

		// std::cout << "before_comma: " << before_comma << std::endl;
		// std::cout << "after_comma: " << after_comma << std::endl;
		std::istringstream(after_comma) >> result[before_comma];
	}
	file.close();
	return (result);
}

int main(int ac, char **av) {
	BitcoinExchange exchange;
	if (ac < 2) {
		std::cerr << "Error: could not open file" << std::endl;
		return 0;
	}
	std::map<std::string, float> dataMap = csvToMap("./data.csv");

	/* bring arguments files */
	std::string filename = av[1];
	std::ifstream file(filename.c_str(), std::ifstream::in);
	if (!file.is_open()) {
		std::cerr << "Error: Invalid File Open" << std::endl;
		return 0;
	}
	while (!file.eof()) {
		std::string line;
		std::getline(file, line);
		
		// std::cout << "line_numbers " << line << std::endl;
		exchange.parseLine(line, dataMap); 	// insert parsed map
	}
	file.close();
	return 0;
};