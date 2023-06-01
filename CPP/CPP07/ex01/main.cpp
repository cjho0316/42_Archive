#include "iter.hpp"

int main(void)
{
	int int_array[] = { 1, 2, 3, 4, 5 };
	std::string string_array[] = { "Hello", "World", "!" };

	std::cout << "int_array: ";
	iter(int_array, 5, print);
	std::cout << std::endl;

	std::cout << "string_array: ";
	iter(string_array, 3, print);
	std::cout << std::endl;

	std::cout << "-----------------------------------------" << std::endl;

	std::cout << "int_array: ";
	iter(int_array, 5, print_ptr);
	std::cout << std::endl;

	std::cout << "string_array: ";
	iter(string_array, 3, print_ptr);
	std::cout << std::endl;


	return (0);

}