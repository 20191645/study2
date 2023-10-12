#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "pe10-3.h"

Golf::Golf(const char* name, int hc) {
	strcpy(fullname, name);
	handicap = hc;
}

int Golf::setgolf() {
	using namespace std;

	char name[Len];
	int hc;

	cout << "이름을 입력하십시오: ";
	if (!cin.getline(name, Len)) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	if (name[0] == '\0')
		return 0;

	cout << "핸디캡을 입력하십시오: ";
	cin >> hc;
	cin.get();

	Golf temp(name, hc);
	*this = temp;

	return 1;
}

void Golf::update(int hc) {
	handicap = hc;
}

void Golf::showgolf() const {
	using namespace std;
	cout << "이름: " << fullname << endl;
	cout << "핸디캡: " << handicap << endl;
}