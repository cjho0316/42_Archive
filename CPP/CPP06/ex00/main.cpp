#include "ScalarConverter.hpp"

int main(int ac, char **av){
    if (ac == 2)
    {
        ScalarConverter converter;
        std::cout << converter.determineType(av[1]) << std::endl;
    }
    return (0);
}