/*
	문제 1:
	2개의 정수를 입력받고 그 사이에 있는 정수들의 합을 계산, 출력
*/

#include <iostream>

int main() {
	using namespace std;

	int a, b;
	cout << "첫 번째 정수를 입력하시오: ";
	cin >> a;
	cout << "두 번째 정수를 입력하시오: ";
	cin >> b;

	int sum = 0;
	for (int i = a; i <= b; i++)
		sum += i;
	cout << "모든 정수의 합: " << sum << endl;

	return 0;
}