#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>

int stringToInt(const std::string& str);
std::string intToString(int number);

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		~RPN();
		RPN &operator=(const RPN &other);

		bool isOperator(const std::string &str);
		bool isNumber(const std::string &str);
		std::string operandOperation(const std::string &str, int a, int b);
		std::string rpnCalculation(const std::string &str);
};

#endif
