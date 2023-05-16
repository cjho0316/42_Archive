#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void) {
	std::srand(time(NULL));
	int i = rand() % 3;
	if (i == 0) {
		std::cout << "A generated" << std::endl;
		return new A;
	}
	else if (i == 1) {
		std::cout << "B generated" << std::endl;
		return new B;
	}
	else {
		std::cout << "C generated" << std::endl;
		return new C;
	}
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A &>(p);
	}
	catch (std::bad_cast &bc) {
		std::cout << "A instance" << std::endl;
	}

	try {
		(void)dynamic_cast<B &>(p);
	}
	catch (std::bad_cast &bc) {
		std::cout << "B instance" << std::endl;
	}

	try {
		(void)dynamic_cast<C &>(p);
	}
	catch (std::bad_cast &bc) {
		std::cout << "C instance" << std::endl;
	}
}

