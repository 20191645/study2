/*
	문제 5:
	하나의 정수를 매개변수로 취해 팩토리얼을 리턴하는 재귀 함수 정의
*/

#include <iostream>

long double factorial(long double n);

int main() {
	using namespace std;

	long double n;

	cout << "값을 입력하십시오: ";
	while (cin >> n && n > -1) {
		cout << n << "!: " << factorial(n) << endl;
		cout << "값을 입력하십시오: ";
	}

	return 0;
}

long double factorial(long double n) {
	if (n < 2)
		return 1;
	return n * factorial(n - 1);
}