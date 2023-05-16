#include "ScalarConverter.hpp"


/* OCF */
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) { (void)copy; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
    (void)copy;
    return (*this);
}

// /* member functions */
void ScalarConverter::convert2Char(const std::string &str) {
	double num;
	std::string result;

	num = atof(str.c_str());
	if (num < std::numeric_limits<char>::min() || num > std::numeric_limits<char>::max())
		result = "impossible1";
	else if (std::isnan(num) || std::isinf(num))
		result = "impossible2";
	else if (num < 32 || num > 126)
		result = "Non displayable";
	else if (std::isprint(static_cast<char>(num)))
		result = static_cast<char>(num);

	std::cout << result << std::endl;
}

void ScalarConverter::convert2Int(const std::string &str) {
	double num;
	std::string result;

	num = atof(str.c_str());
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		result = "impossible1";
	else if (std::isnan(num) || std::isinf(num))
		result = "impossible2";
	else if (str.length() == 1 && !std::isdigit(str[0]))
		result = std::to_string(static_cast<int>(str[0]));
	else
		result = std::to_string(static_cast<int>(num));

	std::cout << result << std::endl;
}

void ScalarConverter::convert2Float(const std::string &str) {
	float num;
	std::ostringstream result;

	num = atof(str.c_str());
	if (std::isnan(num))
	{
		result << "nanf";
		std::cout << result.str() << std::endl;
		return ;
	}
	else if(str.length() == 1 && !std::isdigit(str[0]) && !std::isinf(num))
		result << static_cast<int>(str[0]) << ".0f";
	else 
	{
		result << num;
		if (!strchr(result.str().c_str(), '.') && !std::isinf(num))
			result << ".0f";
	}
	std::cout << result.str() << std::endl;
}

void ScalarConverter::convert2Double(const std::string &str) {
	double num;
	std::ostringstream result;

	num = atof(str.c_str());
	if (std::isnan(num))
		result << "nan";
	else if (str.length() == 1 && !std::isdigit(str[0]) && !std::isinf(num))
	{
		result << static_cast<int>(str[0]) << ".0";
		std::cout << result.str() << std::endl;
		return ;
	}
	else 
	{
		result << num;
		if (!strchr(result.str().c_str(), '.') && !std::isinf(num))
		{
			result << ".0";
			std::cout << result.str() << std::endl;
			return ;
		}
	}
	std::cout << result.str() << std::endl;
}

void ScalarConverter::convertAll(const std::string &str) {
	std::cout << "char: ";
	ScalarConverter::convert2Char(str);

	std::cout << "int: ";
	ScalarConverter::convert2Int(str);

	std::cout << "float: ";
	ScalarConverter::convert2Float(str);

	std::cout << "double: ";
	ScalarConverter::convert2Double(str);
}
