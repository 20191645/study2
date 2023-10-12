/*
	문제 7:
	휘발유 소비량을 유럽 스타일로 입력받고, 미국 스타일로 변환
*/

#include <iostream>

int main() {
	using namespace std;

	double liter;
	cout << "휘발유 소비량을 유럽 스타일로 입력하시오: ";
	cin >> liter;

	const double GALLON = 3.875;
	const double MILE = 62.14;

	double gallon = liter / GALLON;
	double mpg = MILE / gallon;

	cout << "미국 스타일로 변환된 휘발유 소비량: " << mpg << endl;

	return 0;
}