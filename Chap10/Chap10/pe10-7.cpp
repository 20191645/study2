#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "pe10-7.h"

Plorg::Plorg() {
	strcpy(name, "Plorga");
	ci = 50;
}

Plorg::Plorg(const char* nm) {
	strcpy(name, nm);
	ci = 50;
}

void Plorg::setCi(int n) {
	ci = n;
}

void Plorg::show() const {
	std::cout << "ÀÌ¸§: " << name << std::endl;
	std::cout << "CI: " << ci << std::endl;
}