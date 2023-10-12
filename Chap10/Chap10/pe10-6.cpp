#include <iostream>
#include "pe10-6.h"

Move::Move(double a, double b) {
	x = a;
	y = b;
}

void Move::showmove() const {
	std::cout << '[' << x << ", " << y << ']' << std::endl;
}

Move Move::add(const Move& m)const {
	double mx = x + m.x;
	double my = x + m.y;
	Move temp(mx, my);
	return temp;
}

void Move::reset(double a, double b) {
	x = a;
	y = b;
}