#include <iostream>
#include "pe11-6.h"

Stonewt::Stonewt(double lbs) {
	pounds = lbs;
	stone = (int)pounds / Lps_per_stn;
	pds_left = (int)pounds % Lps_per_stn;
}
Stonewt::Stonewt(int stn, double lbs) {
	stone = stn;
	pds_left = lbs;
	pounds = pds_left + stone * Lps_per_stn;
}
Stonewt::Stonewt() {
	stone = pds_left = pounds = 0;
}
Stonewt::~Stonewt() {

}

void Stonewt::show_lbs() const {
	std::cout << pounds << "�Ŀ��\n";
}
void Stonewt::show_stn() const {
	std::cout << stone << "����, " << pds_left << "�Ŀ��\n";
}