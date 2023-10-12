#include <iostream>
#include "pe11-7.h"

complex::complex(double r, double i) {
	real = r;
	imaginary = i;
}

complex complex::operator+(const complex& com) const {
	return complex(real + com.real, imaginary + com.imaginary);
}
complex complex::operator-(const complex& com) const {
	return complex(real - com.real, imaginary - com.imaginary);
}
complex complex::operator*(const complex& com) const {
	double r = real * com.real - imaginary * com.imaginary;
	double i = real * com.imaginary + imaginary * com.real;
	return complex(r, i);
}
complex complex::operator*(double n) const {
	return complex(n * real, n * imaginary);
}
complex complex::operator~() const {
	return complex(real, -imaginary);
}

std::ostream& operator<<(std::ostream& os, const complex& com) {
	os << '(' << com.real << ',' << com.imaginary << "i)";
	return os;
}
std::istream& operator>>(std::istream& is, complex& com) {
	std::cout << "실수부: ";
	if (is >> com.real) {
		std::cout << "허수부: ";
		is >> com.imaginary;
	}
	return is;
}