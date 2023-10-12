#include <iostream>
#include "pe11-4.h"

Time::Time() {
	hours = 0;
	minutes = 0;
}
Time::Time(int h, int m) {
	hours = h;
	minutes = m;
}

void Time::AddMin(int m) {
	minutes += m % 60;
	hours += m / 60;
}
void Time::AddHr(int h) {
	hours += h;
}
void Time::Reset(int h, int m) {
	hours = h;
	minutes = m;
}
void Time::show() const {
	std::cout << hours << "시간, " << minutes << "분";
}

Time operator-(const Time& t1, const Time& t2) {
	Time diff;
	diff.hours = t1.hours - t2.hours;
	if (t2.minutes > t1.minutes) {
		diff.hours--;
		diff.minutes += 60;
	}
	diff.minutes += t1.minutes - t2.minutes;
	return diff;
}
Time operator+(const Time& t1, const Time& t2) {
	Time sum;
	sum.minutes = t1.minutes + t2.minutes;
	sum.hours = t1.hours + t2.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
Time operator*(const Time& t1, double mult) {
	Time result;
	long totalminutes = t1.hours * mult * 60 + t1.minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

std::ostream& operator<<(std::ostream& os, const Time& t) {
	os << t.hours << "시간, " << t.minutes << "분";
	return os;
}