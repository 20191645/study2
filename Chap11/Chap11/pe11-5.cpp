#include <iostream>
#include "pe11-5.h"

Stonewt::Stonewt(double lbs) {
	pounds = lbs;
	stone = (int)pounds / Lps_per_stn;
	pds_left = (int)pounds % Lps_per_stn;

	type = POUND;
}
Stonewt::Stonewt(int stn, double lbs) {
	stone = stn;
	pds_left = lbs;
	pounds = pds_left + stone * Lps_per_stn;

	type = STONE;
}
Stonewt::Stonewt() {
	stone = pds_left = pounds = 0.0;

	type = STONE;
}
Stonewt::~Stonewt() {

}

Stonewt Stonewt::operator+(const Stonewt& st) {
	Stonewt sum(pounds + st.pounds);
	if (type == STONE)
		sum.type = STONE;
	return sum;
}

Stonewt Stonewt::operator-(const Stonewt& st) {
	Stonewt diff(pounds - st.pounds);
	if (type == STONE)
		diff.type = STONE;
	return diff;
}

Stonewt Stonewt::operator*(double n) const {
	Stonewt mul(pounds * n);
	if (type == STONE)
		mul.type = STONE;
	return mul;
}

std::ostream& operator<<(std::ostream& os, const Stonewt& st) {
	if (st.type == Stonewt::POUND)
		std::cout << st.pounds << "파운드\n";
	else
		std::cout << st.stone << "스톤, " << st.pds_left << "파운드\n";
	return os;
}