/*
	문제 4:
	단리 10% 고객의 투자 가치를 복리 5% 고객의 투자 가치가 초과하는 년 수 계산
*/

#include <iostream>

const double Aratio = 0.10;
const double Bratio = 0.05;

int main() {
	using namespace std;

	double A = 100000;
	double B = 100000;
	int years = 0;

	while (A >= B) {
		A += Aratio * 100000;
		B *= 1.05;
		++years;
	}

	cout << years << "년 후: " << endl;
	cout << "A의 투자 가치: " << A << endl;
	cout << "B의 투자 가치: " << B << endl;

	return 0;
}