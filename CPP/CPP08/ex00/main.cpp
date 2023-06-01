#include "easyfind.hpp"
#include <vector>

int main(void){
	std::vector<int> v;

	for (int i = 0; i < 10; i++)
		v.push_back(i);

	for (int i = 0; i < 10; i++)
		std::cout << v[i] << " ";
	
	std::cout << std::endl;
	std::cout << "-----------------------------------------" << std::endl;

	try{
		std::vector<int>::iterator finder1 = easyfind(v, 0);
		std::vector<int>::iterator finder2 = easyfind(v, 5);
		std::vector<int>::iterator finder3 = easyfind(v, 8);
		std::vector<int>::iterator finder4 = easyfind(v, 9);
		std::cout << "Success Case: " << std::endl;
		std::cout << *finder1 << std::endl;
		std::cout << *finder2 << std::endl;
		std::cout << *finder3 << std::endl;
		std::cout << *finder4 << std::endl;

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Failure Case: " << std::endl;
		std::vector<int>::iterator finder5 = easyfind(v, 99);
		std::cout << *finder5 << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}