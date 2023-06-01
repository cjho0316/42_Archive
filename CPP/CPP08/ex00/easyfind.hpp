#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <stdexcept>
#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int n)
{
	typename T::iterator finder = std::find(container.begin(), container.end(), n);
	if (finder == container.end())
		throw std::runtime_error("error_occured");
	return finder;
}

#endif

