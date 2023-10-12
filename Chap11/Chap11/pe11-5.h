#ifndef PE11_5_H_
#define PE11_5_H_

#include <iostream>

class Stonewt {
private:
	enum { Lps_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;

	// 스톤 형식, 부동소수점 파운드 형식 해석 결정
	enum { STONE, POUND };
	int type;

public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();

	// 연산자 오버로딩, friend 함수
	Stonewt operator+(const Stonewt& st);
	Stonewt operator-(const Stonewt& st);
	Stonewt operator*(double n) const;

	friend std::ostream& operator<<(std::ostream& os, const Stonewt& st);
	friend Stonewt operator*(double n, const Stonewt& st) { return st * n; }
};

#endif