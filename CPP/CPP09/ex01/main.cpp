#include "RPN.hpp"

int main(int argc, char** av) {
	RPN rpn;

    if (argc != 2) {
        std::cout << "Error: Invalid number of arguments." << std::endl;
        return (0);
    }

    std::string expression = av[1];
    std::string result = rpn.rpnCalculation(expression);
    std::cout << result << std::endl;

    return (0);
}