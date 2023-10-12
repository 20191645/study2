/*
	���� 4:
	���� ���� �ý����� �·� ���
*/

#include <iostream>

long double probability(unsigned numbers, unsigned picks);

int main() {
	using namespace std;

	double total, choices;
	double result;

	cout << "��ü ���� ������ ���� ���� ������ �Է��Ͻʽÿ�: ";
	while (!(cin >> total >> choices) || choices > total) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "��ü ���� ������ ���� ���� ������ �Է��Ͻʽÿ�: ";
	}
	result = probability(total, choices);

	cout << "�ް� ���� ������ ���� ���� ������ �Է��Ͻʽÿ�: ";
	while (!(cin >> total >> choices) || choices > total) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "�ް� ���� ������ ���� ���� ������ �Է��Ͻʽÿ�: ";
	}
	result *= probability(total, choices);

	cout << "�·��� " << result << "�� �� �� ���Դϴ�.\n";
	cout << "���α׷��� �����մϴ�.\n";

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