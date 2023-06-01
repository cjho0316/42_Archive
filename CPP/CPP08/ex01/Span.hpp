#ifndef SPAN_HPP
# define SPAN_HPP

#include <limits>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>

class Span {
	private:
		unsigned int _num;
		std::vector<int> _vec;
	public:
		/* OCF */
		Span();
		Span(unsigned int N);
		Span(Span const &copy);
		~Span();
		Span &operator=(Span const &other);

		/* member functions */
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void addNumber(unsigned int n);
};

#endif