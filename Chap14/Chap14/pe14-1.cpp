/*
	문제 1:
	Pair, Wine 클래스 구현
*/

#include <iostream>
#include "pe14-1.h"

int main() {
	using std::cin;
	using std::cout;
	using std::endl;

	char lab[50];
	cout << "와인 이름을 입력하십시오: ";
	cin.getline(lab, 50);

	int yrs;
	cout << "수확 년도 개수를 입력하십시오: ";
	cin >> yrs;

	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = { 1993,1995,1998 };
	int b[YRS] = { 48,60,72 };

	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << more.Label() << " 전체 수량"
		<< ": " << more.sum() << endl;

	cout << "프로그램을 종료합니다.\n";
	return 0;
}