#include "BitcoinExchange.hpp"

void BitcoinExchange::parseLine(std::string line, std::map<std::string, float> dataMap) {
	if (checkValidData(line)) {

	}
}

int BitcoinExchange::checkValidData(std::string line) {
	std::string before_pipe;
	std::string after_pipe;

	//if statements seperated for debug purpose, merging required
	if (line.length() < 13)
		return (0);
	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		return (0);
	before_pipe = line.substr(0, 9);
	after_pipe = line.substr(10);
	if (checkValidKey(before_pipe) && checkValidValue(after_pipe)) {
		
	}
}

int BitcoinExchange::checkValidKey(std::string line) {
	//check YYYY-MM-DD Datetype
	//check weather '-' is used for seperator

	int year;
	int month;
	int day;

	//isDigit checker
	while (i < line.length()) {
		// need to merge after debug
		if (i == 4 && line[4] != '-')
			return (0);
		if (i == 7 && line[7] != '-')
			return (0);
		if (!isdigit(line[i]))
			return (0);
		i++;
	}
	year = line.substr(0, 3);
	month = line.substr(5, 2);
	day = line.substr(8, 2);
	//TODO: "leap year" implementation required
	if (stringToInt(month) > 12 || stringToInt(month) < 1)
		return (0);
	if (stringToInt(day) < 0 || stringToInt(day) > 31)
		return (0);


	return(1);
}

int BitcoinExchange::checkValidValue(std::string line) {
	//check correct value info
	//range (1, 1000)
	line 
}


int stringToInt(const std::string& str) {
    int result = 0;
    int sign = 1;
    size_t i = 0;

    if (str[0] == '+' || str[0] == '-') {
        if (str[0] == '-')
            sign = -1;
        i++;
    }
    for (; i < str.length(); ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            return 0;
        }
    }
    return result * sign;
}