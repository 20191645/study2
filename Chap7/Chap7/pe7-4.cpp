/*
	문제 4:
	변형 복권 시스템의 승률 계산
*/

#include <iostream>

long double probability(unsigned numbers, unsigned picks);

int main() {
	using namespace std;

	double total, choices;
	double result;

	cout << "전체 수의 개수와 뽑을 수의 개수를 입력하십시오: ";
	while (!(cin >> total >> choices) || choices > total) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "전체 수의 개수와 뽑을 수의 개수를 입력하십시오: ";
	}
	result = probability(total, choices);

	cout << "메가 수의 개수와 뽑을 수의 개수를 입력하십시오: ";
	while (!(cin >> total >> choices) || choices > total) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "메가 수의 개수와 뽑을 수의 개수를 입력하십시오: ";
	}
	result *= probability(total, choices);

	cout << "승률은 " << result << "번 중 한 번입니다.\n";
	cout << "프로그램을 종료합니다.\n";

	return 0;
}

long double probability(unsigned numbers, unsigned picks) {
	long double result = 1.0;
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--) {
		result = result * n / p;
	}

	return result;
}