/*
	���� 1:
	2���� ������ �Է¹ް� �� ���̿� �ִ� �������� ���� ���, ���
*/

#include <iostream>

int main() {
	using namespace std;

	int a, b;
	cout << "ù ��° ������ �Է��Ͻÿ�: ";
	cin >> a;
	cout << "�� ��° ������ �Է��Ͻÿ�: ";
	cin >> b;

	int sum = 0;
	for (int i = a; i <= b; i++)
		sum += i;
	cout << "��� ������ ��: " << sum << endl;

	return 0;
}