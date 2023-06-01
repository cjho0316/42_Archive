#include "Span.hpp"

/* OCF */
Span::Span(): _num(0) {}
Span::Span(unsigned int N): _num(N) {}
Span::Span(Span const &copy) { *this = copy; }
Span::~Span() {}
Span &Span::operator=(Span const &other) {
	if (this != &other) {
		_num = other._num;
		_vec = other._vec;
	}
	return (*this);
}

/* member functions */
unsigned int Span::shortestSpan() {
	int tmp = INT_MAX;
	if (_vec.size() < 2)
		throw std::runtime_error("Not enough numbers in the container");
	std::sort(_vec.begin(), _vec.end());
	for (unsigned int i = 0; i < _num - 1; i++) {
		if (_vec[i + 1] - _vec[i] < tmp)
			tmp = _vec[i + 1] - _vec[i];
	}
	return (tmp);
}

unsigned int Span::longestSpan() {
	if (_vec.size() < 2)
		throw std::runtime_error("Not enough numbers in the container");
	std::sort(_vec.begin(), _vec.end());
	return (_vec[_vec.size() - 1] - _vec[0]);
}

void Span::addNumber(unsigned int number) {
	if (_vec.size() == _num)
		throw std::runtime_error("Container is full");
	_vec.push_back(number);
}