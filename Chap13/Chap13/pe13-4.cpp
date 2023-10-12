#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "pe13-4.h"
using namespace std;


// Port 메서드
Port::Port(const char* br, const char* st, int b) {
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strncpy(style, st, 19);
	bottles = b;
}
Port::Port(const Port& p) {
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}

Port& Port::operator=(const Port& p) {
	if (this == &p)
		return *this;
	delete[] brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}
Port& Port::operator+= (int b) {
	bottles += b;
	return *this;
}
Port& Port::operator-=(int b) {
	if (bottles >= b)
		bottles -= b;
	return *this;
}

void Port::Show() const {
	cout << "브랜드: " << brand << endl;
	cout << "스타일: " << style << endl;
	cout << "수량: " << bottles << endl;
}
ostream& operator<<(ostream& os, const Port& p) {
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}



// VintagePort 메서드
VintagePort::VintagePort()
	:Port()
{
	nickname = new char[5];
	strcpy(nickname, "none");
	year = 0;
}
VintagePort::VintagePort(const char* br, int b, const char* nn, int y)
	:Port(br, "vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}
VintagePort::VintagePort(const VintagePort& vp)
	:Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp) {
	if (this == &vp)
		return *this;
	delete[] nickname;
	Port::operator=(vp);
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
	return *this;
}
void VintagePort::Show() const {
	Port::Show();
	cout << "닉네임: " << nickname << endl;
	cout << "포도 수확 년도: " << year << endl;
}
ostream& operator<<(ostream& os, const VintagePort& vp) {
	os << (const Port&)vp << endl;
	os << vp.nickname << ", " << vp.year;
	return os;
}