/*
	문제 2:
	pe13-1을 다시 하되 고정 크기 배열 대신 동적 메모리 대입 사용
*/

#include <iostream>
using namespace std;
#include "pe13-2.h"

void Bravo(const Cd& disk);

int main() {
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	Cd* pcd = &c1;

	cout << "객체를 직접 사용한다:\n";
	c1.Report();
	c2.Report();

	cout << "객체를 지시하는 Cd * 포인터를 사용한다:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "Cd 참조 매개변수를 사용하여 함수를 호출한다:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "대입을 테스트한다:\n";
	Classic copy;
	copy = c2;
	copy.Report();

	return 0;
}

void Bravo(const Cd& disk) {
	disk.Report();
}