#include "ScalarConverter.hpp"

int main(int ac, char **av){
    if (ac == 2)
    {
        ScalarConverter converter;

        converter.convertAll(av[1]);
    }
    return (0);
}