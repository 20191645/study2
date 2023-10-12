/*
	문제 1:
	- 키를 센티미터 단위로 입력받고 미터와 센티미터 단위로 변환
	- 환산 인수로 const 기호 상수 사용
*/

#include <iostream>

int main() {
	using namespace std;

	int centimeter;
	cout << "키를 정수형 센티미터 단위로 입력하시오: ___\b\b\b";
	cin >> centimeter;

	const double CtoM = 100.0;
	double meter = centimeter / CtoM;
	cout << "미터로 변환된 키: " << meter;

	return 0;
}