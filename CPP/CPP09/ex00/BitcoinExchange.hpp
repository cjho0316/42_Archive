#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

static int stringToInt(const std::string& str);

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
		void parseLine(std::string line, std::map<std::string, float>);
		int checkValidData(std::string line);
		int checkValidKey(std::string line);
		int checkValidValue(std::string line);

};

#endif

/*
//TODO
1. 파싱해서 파이프 로 구분자 던져주는 



*/