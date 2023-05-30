#include "RPN.hpp"

RPN::RPN() {};
RPN::RPN(const RPN &other) { *this = other; };
RPN::~RPN() {};
RPN &RPN::operator=(const RPN &other) { (void)other; return *this; };

bool RPN::isOperator(const std::string &str) {
	return (str == "+" || str == "-" || str == "*" || str == "/" || str == "%");
}

bool RPN::isNumber(const std::string &str) {
	return (str >= "0" && str <= "9");
}

std::string RPN::operandOperation(const std::string &str, int a, int b) {
	if (str == "+")
		return intToString(a + b);
	else if (str == "-")
		return intToString(a - b);
	else if (str == "*")
		return intToString(a * b);
	else if (str == "/")
		return intToString(a / b);
	else if (str == "%")
		return intToString(a % b);
	else
		return (0);
}

std::string RPN::rpnCalculation(const std::string &str) {
	std::stack<std::string> _stack;
	std::istringstream ss(str);
	std::string token;

	while (ss >> token) {
		if (isNumber(token))
			_stack.push(token.c_str());
		else if (isOperator(token)) {
			if (_stack.size() < 2) {
				std::cout << "Error: Insufficient tokens" << std::endl;
				return (0);
			}
			int operand2 = stringToInt(_stack.top());
			_stack.pop();
			int operand1 = stringToInt(_stack.top());
			_stack.pop();

			std::string result = operandOperation(token, operand1, operand2);
			_stack.push(result);
		}
		else {
			std::cerr << "Error: Invalid token" << std::endl;
			exit (0);
		}
	}
	return (_stack.top());
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

std::string intToString(int number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
}