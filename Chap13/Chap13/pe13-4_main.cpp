/*
	문제 4:
	Port, VintagePort 클래스 메서드 구현
*/

#include <iostream>
#include "pe13-4.h"

int main() {
	using std::cout;
	using std::endl;

	Port pt1("brand1", "style1", 10);
	pt1.Show();
	cout << endl;

	pt1 += 5;
	cout << pt1 << endl << endl;

	pt1 -= 10;
	cout << pt1 << endl << endl;

	Port pt3(pt1);
	cout << pt3 << endl << endl;

	VintagePort vpt1;
	vpt1.Show();
	cout << endl;

	vpt1 = VintagePort("brand2", 10, "Old velvet", 1960);
	cout << vpt1 << endl << endl;

	vpt1 += 3;
	vpt1.Show();

	return 0;
}