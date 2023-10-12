#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "pe10-2.h"

Person::Person(const string& ln, const char* fn) {
	lname = ln;
	strcpy(fname, fn);
}

void Person::Show() const {
	using namespace std;
	cout << fname << " " << lname << endl;
}

void Person::FormalShow() const {
	using namespace std;
	cout << lname << ", " << fname << endl;
}