#ifndef PE11_7_H_
#define PE11_7_H_

#include <iostream>

class complex {
private:
	double real;
	double imaginary;

public:
	complex(double r = 0.0, double i = 0.0);
	~complex() {}

	complex operator+(const complex& com) const;
	complex operator-(const complex& com) const;
	complex operator*(const complex& com) const;
	complex operator*(double n) const;
	complex operator~() const;

	friend complex operator*(double n, const complex& com) { return com * n; }
	friend std::ostream& operator<<(std::ostream& os, const complex& com);
	friend std::istream& operator>>(std::istream& is, complex& com);
};

#endif