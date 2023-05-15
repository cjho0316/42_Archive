# ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <stdexcept>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

class ScalarConverter {
	private:
	public:
        enum {CHAR, INT, FLOAT, DOUBLE};
		
        /* OCF */
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &copy);

		/* member fuctions */
        static int determineType(const std::string &str);
        static void convert2Char(std::string &str);
        static void convert2Int(std::string &str);
        static void convert2Float(std::string &str);
        static void convert2Double(std::string &str);        
        // static void merge(std::string)

        /* error exception class */

        class InvalidTypeException: public std::exception {
            public:
                const char * what() const throw();
        };

};

#endif
