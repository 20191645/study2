/*
	문제 1:
	- 기초 클래스 Cd에 char형 배열을 추가하여 Classic 클래스 파생
	- 클래스 Cd, Classic 메서드 구현
*/

#include <iostream>
using namespace std;
#include "pe13-1.h"

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