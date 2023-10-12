/*
	문제 7:
	Plorg 클래스 선언 및정의
*/

#include "pe10-7.h"

int main() {
	Plorg p1;
	p1.show();
	p1.setCi(20);
	p1.show();

	Plorg p2("Happy");
	p2.show();

	return 0;
}