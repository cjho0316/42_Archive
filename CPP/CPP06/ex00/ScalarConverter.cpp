#include "ScalarConverter.hpp"


/* OCF */
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) { (void)copy; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
    (void)copy;
    return (*this);
}

/* member functions */

int ScalarConverter::determineType(const std::string& str) {
    char *endPtr;
    size_t len = str.length();
    long intVal = std::strtol(str.c_str(), &endPtr, 10);
    
    if (len == 1 && std::isprint(str[0]))
        return ScalarConverter::CHAR;
    else if (*endPtr == '\0' && std::to_string(intVal) == str)
        return ScalarConverter::INT;
    else if (len > 1 && str[len-1] == 'f')
        return ScalarConverter::FLOAT;
    else
        return ScalarConverter::DOUBLE;
}





/* error exception class */

const char *ScalarConverter::InvalidTypeException::what() const throw() {
    return ("Invalid Type have been thrown");
}