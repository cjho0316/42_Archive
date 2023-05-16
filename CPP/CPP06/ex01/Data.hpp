# ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>

struct Data {
	int _value;
	std::string _name;

	Data(int value, const std::string &name): _value(value), _name(name) {};
};

#endif