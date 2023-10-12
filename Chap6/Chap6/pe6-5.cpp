/*
	문제 5:
	소득을 입력하면 내야 할 소득세를 산출
*/

#include <iostream>
int main() {
	using namespace std;

	double tvap;
	double tax;
	cout << "당신의 소득을 트바프 단위로 입력하시오: ";
	while ((cin >> tvap) && tvap >= 0) {
		tax = 0;
		if (tvap > 5000 && tvap <= 15000) {
			tax += (tvap - 5000) * 0.1;
		}
		else if (tvap > 15000 && tvap <= 35000) {
			tax += 10000 * 0.1;
			tvap -= 15000;
			tax += tvap * 0.15;
		}
		else if (tvap > 35000) {
			tax += 10000 * 0.1;
			tax += 20000 * 0.15;
			tvap -= 35000;
			tax += tvap * 0.2;
		}
		cout << "당신의 소득세: " << tax << endl;
		cout << "당신의 소득을 트바프 단위로 입력하시오: ";
	}

	cout << "프로그램을 종료합니다.\n";
	return 0;
}