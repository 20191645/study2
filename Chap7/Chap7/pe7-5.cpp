/*
	���� 5:
	�ϳ��� ������ �Ű������� ���� ���丮���� �����ϴ� ��� �Լ� ����
*/

#include <iostream>

long double factorial(long double n);

int main() {
	using namespace std;

	long double n;

	cout << "���� �Է��Ͻʽÿ�: ";
	while (cin >> n && n > -1) {
		cout << n << "!: " << factorial(n) << endl;
		cout << "���� �Է��Ͻʽÿ�: ";
	}

	return 0;
}

long double factorial(long double n) {
	if (n < 2)
		return 1;
	return n * factorial(n - 1);
}