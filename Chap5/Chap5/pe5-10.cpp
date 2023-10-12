/*
	문제 10:
	출력할 행 수를 입력받고 중첩 루프를 사용하여 출력
*/

#include <iostream>

int main() {
	using namespace std;

	int num;
	cout << "출력할 행 수를 입력하십시오: ";
	cin >> num;

	for (int i = 1; i <= num; ++i) {
		for (int j = num; j > i; --j) {
			cout << '.';
		}
		for (int k = 0; k < i; ++k) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}