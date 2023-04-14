# ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _fixed;
		static const int _frac;

	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &copy);
		Fixed& operator=(Fixed const &copy);
		Fixed(const int value);
		Fixed(const float value);

		float toFloat() const;
		int toInt() const;
		/* 6 comparison operators */
		bool operator>(Fixed const &copy) const;
		bool operator<(Fixed const &copy) const;
		bool operator>=(Fixed const &copy) const;
		bool operator<=(Fixed const &copy) const;
		bool operator==(Fixed const &copy) const;
		bool operator!=(Fixed const &copy) const;

		/* 4 arithmetic operators */
		Fixed operator+(Fixed const &copy);
		Fixed operator-(Fixed const &copy);
		Fixed operator*(Fixed const &copy);
		Fixed operator/(Fixed const &copy);

		/* post, pre increment and decrement operators */
		Fixed &operator++();
		Fixed &operator--();

		Fixed operator++(int);
		Fixed operator--(int);

		/* min,max function overloading */
		static Fixed& min(Fixed &value1, Fixed &value2);
		static Fixed& max(Fixed &value1, Fixed &value2);
		static const Fixed& min(const Fixed& value1, const Fixed& value2);
		static const Fixed& max(const Fixed& value1, const Fixed& value2);

		int getRawBits() const;
		void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &str, Fixed const &fp);

#endif