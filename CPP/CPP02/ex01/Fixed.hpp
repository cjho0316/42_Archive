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
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		Fixed(Fixed const &copy);
		Fixed& operator=(Fixed const &copy);
		int getRawBits() const;
		void setRawBits(int const raw);

		float toFloat() const;
		int toInt() const;
};

std::ostream &operator<<(std::ostream &str, Fixed const &fp);

#endif