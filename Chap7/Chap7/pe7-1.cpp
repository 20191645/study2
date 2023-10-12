/*
	문제 1:
	쌍을 이루는 두 수를 반복해서 입력받고 조화평균 계산
*/

#include <iostream>

double avg(double, double);

int main() {
	using namespace std;

	double x = 1, y = 1;
	while (x != 0 && y != 0) {
		cout << "쌍을 이루는 두 수를 입력하십시오: ";
		if (!(cin >> x >> y)) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			x = y = 1;
			continue;
		}

		cout << "두 수의 조화평균: " << avg(x, y) << endl;
	}
	cout << "프로그램을 종료합니다.\n";

	return 0;
}

double avg(double x, double y) {
	return (2.0 * x * y) / (x + y);
}