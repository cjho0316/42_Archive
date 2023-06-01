#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T *_array;
		size_t _size;
	public:
		Array(void) : _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(Array const &other) : _array(NULL), _size(0) { *this = other; }
		~Array(void) { delete [] _array; }

		Array &operator=(Array const &other)
		{
			if (this != &other)
			{
				delete [] _array;
				_size = other._size;
				_array = new T[_size];
				for (size_t i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
			return (*this);
		}

		T &operator[](size_t index)
		{
			if (index >= _size)
				throw std::runtime_error("Index out of range");
			return (_array[index]);
		}

		T const &operator[](size_t index) const
		{
			if (index >= _size)
				throw std::runtime_error("Index out of range");
			return (_array[index]);
		}

		size_t size(void) const { return (_size); }	
};

#endif
