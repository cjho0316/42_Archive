#include "BitcoinExchange.hpp"

void BitcoinExchange::parseLine(std::string line, std::map<std::string, float> &dataMap) {
	if (line == "date | value")
		return ;
	if (checkValidData(line)) {
		std::string year = line.substr(0, 4);
		std::string month = line.substr(5, 2);
		std::string day = line.substr(8, 2);
		std::string date = line.substr(0, 10);
		std::string value = line.substr(13);

		// std::cout << "year: " << year << std::endl; // debug
		// std::cout << "month: " << month << std::endl; // debug
		// std::cout << "day: " << day << std::endl; // debug
		// std::cout << "date: " << date << std::endl; // debug
		// std::cout << "value: " << value << std::endl; // debug

		if(!parsingMapKey(year, month, day)) {
			std::cout << "Error: bad input => " << date << std::endl;
			return ;
		}

		std::map<std::string, float>::iterator it_upper = dataMap.upper_bound(date);

		if (it_upper != dataMap.begin() && it_upper->first != date)
			it_upper--;
		float floatValue;
		std::istringstream(value) >> floatValue;
		std::cout << date << " => " << value << " = " << it_upper->second * floatValue << std::endl;
	}
}

int BitcoinExchange::checkValidData(std::string line) {
	std::string before_pipe;
	std::string after_pipe;

	// std::cout << "line: " << line << std::endl; // debug
	if (line.length() < 13 || line[10] != ' ' || line[11] != '|' || line[12] != ' ') {
		std::cout << "Error: bad input => " << line << std::endl;
		return (0);
	}
	before_pipe = line.substr(0, 10);
	after_pipe = line.substr(13);

	// std::cout << "before_pipe: " << before_pipe << std::endl; // debug
	// std::cout << "after_pipe: " << after_pipe << std::endl; // debug
	if (checkValidKey(before_pipe) && checkValidValue(after_pipe))
		return(1);
	return (0);
}

int BitcoinExchange::checkValidKey(std::string line) {
	//check YYYY-MM-DD Datetype
	//check weather '-' is used for seperator
	size_t i = 0;

	// isDigit & '-' checker
	while (i < line.length()) {
		if (i < 4 || (i > 4 && i < 7) || (i > 7 && i < 10)) {
			if (!isdigit(line[i])) {
				std::cerr << "Error: bad input => " << line << std::endl;
				return (0);
			}
		}
		else if(i == 4 || i == 7) {
			if (line[i] != '-') {
				std::cerr << "Error: bad input => " << line << std::endl;
				return (0);
			}
		}
		i++;
	}

	std::string year = line.substr(0, 4);
	std::string month = line.substr(5, 2);
	std::string day = line.substr(8, 2);

	//TODO: "leap year" implementation required
	if (stringToInt(month) > 12 || stringToInt(month) < 1){
		std::cerr << "Error: bad input => " << line << std::endl;
		return (0);
	}
	if (stringToInt(day) < 1 || stringToInt(day) > 31) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return (0);
	}
	return(1);
}

int BitcoinExchange::checkValidValue(std::string line) {
	
	double value = stringToDouble(line);

	// std::cout << "value: " << value << std::endl; // debug
	if (value < 0) {
		std::cerr << "Error: not a positive number" <<std::endl;
		return (0);
	}
	else if (value > 1000) {
		std::cerr << "Error: too large a number" <<std::endl;
		return (0);
	}
	return (1);
}

bool BitcoinExchange::parsingMapKey(std::string paraYear, std::string paraMonth, std::string paraDay)
{
	int year = stringToInt(paraYear);
	int month = stringToInt(paraMonth);
	int day = stringToInt(paraDay);

	if (year < 2009 || 2022 < year || month < 1 || 12 < month || day < 1 || 31 < day)
		return (0);
	if (day > 29 && month == 2)
		return (0);
	if (day == 29 && month == 2 && year % 4 != 0)
		return (0);
	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		return (0);
	return (1);
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

double stringToDouble(const std::string& str) {
    std::istringstream iss(str);
    double result;
    if (!(iss >> result)) {
        std::cerr << "Error: invalid number" << std::endl;
        return 0.0;
    }
    return result;
}