#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "pe12-1.h"

Cow::Cow() {
	strcpy(name, "name");
	hobby = new char[6];
	strcpy(hobby, "hobby");
	weight = 0.0;
}
Cow::Cow(const char* nm, const char* ho, double wt) {
	std::strcpy(name, nm);
	hobby = new char[std::strlen(ho) + 1];
	std::strcpy(hobby, ho);
	weight = wt;
}
Cow::Cow(const Cow& c) {
	std::strcpy(name, c.name);
	hobby = new char[std::strlen(c.hobby) + 1];
	std::strcpy(hobby, c.hobby);
	weight = c.weight;
}
Cow::~Cow() {
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c) {
	std::strcpy(name, c.name);
	delete[] hobby;
	hobby = new char[std::strlen(c.hobby) + 1];
	std::strcpy(hobby, c.hobby);
	weight = c.weight;
	return *this;
}
void Cow::ShowCow() const {
	using std::cout;
	using std::endl;
	cout << "name: " << name << endl;
	cout << "hobby: " << hobby << endl;
	cout << "weight: " << weight << endl;
}