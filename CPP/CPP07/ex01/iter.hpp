#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, std::size_t length, void (*func)(T &t))
{
	for (std::size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void iter(const T *array, std::size_t length, void(*func)(T const& t))
{
	for (std::size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void print(T const &element)
{
	std::cout << element << " ";
}

template <typename T>
void print_ptr(T const &element)
{
	std::cout << &element << " ";
}

#endif