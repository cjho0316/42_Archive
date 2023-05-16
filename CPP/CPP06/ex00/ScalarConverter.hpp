# ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <sstream>

class ScalarConverter {
	private:
	public:
        // enum {CHAR, INT, FLOAT, DOUBLE};
		
        /* OCF */
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &copy);

		/* member fuctions */
        // static int determineType(const std::string &str);
        static void convert2Char(const std::string &str);
        static void convert2Int(const std::string &str);
        static void convert2Float(const std::string &str);
        static void convert2Double(const std::string &str);

		static void convertAll(const std::string &str);

};

#endif
