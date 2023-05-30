#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

int stringToInt(const std::string& str);
double stringToDouble(const std::string& str);

class BitcoinExchange {
	public:
		/* OCF */
		BitcoinExchange(void) {}
		BitcoinExchange(BitcoinExchange const &other) { *this = other; }
		~BitcoinExchange(void) {}
		BitcoinExchange &operator=(BitcoinExchange const &other) {
			(void)other;
			return *this;
		}

		/* member functions */
		void parseLine(std::string line, std::map<std::string, float> &dataMap);
		bool parsingMapKey(std::string paraYear, std::string paraMonth, std::string paraDay);
		int checkValidData(std::string line);
		int checkValidKey(std::string line);
		int checkValidValue(std::string line);

};

#endif
