/*
	���� 2:
	double�� array�� �ִ� 10���� ��α� �Է¹ް�
	��հ� ��պ��� ū ��α� ���� ���
*/

#include <iostream>
#include <array>
#include <cctype>

const int ArSize = 10;

int main() {
	using namespace std;

	array<double, 10> arr;
	int i;
	cout << "��α� �ִ� 10������ �Է�:\n";
	for (i = 0; i < ArSize; i++) {
		if (!(cin >> arr[i]))
			break;
	}

	double avg = 0.0;
	for (int j = 0; j < i; j++)
		avg += arr[j];
	avg /= i;

	int count = 0;
	for (int j = 0; j < i; j++) {
		if (arr[j] > avg)
			++count;
	}

	cout << "�Էµ� ��α� ���: " << avg << endl;
	cout << "��պ��� ū ��α� ��: " << count << endl;

	return 0;
}