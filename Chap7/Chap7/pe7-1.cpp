/*
	���� 1:
	���� �̷�� �� ���� �ݺ��ؼ� �Է¹ް� ��ȭ��� ���
*/

#include <iostream>

double avg(double, double);

int main() {
	using namespace std;

	double x = 1, y = 1;
	while (x != 0 && y != 0) {
		cout << "���� �̷�� �� ���� �Է��Ͻʽÿ�: ";
		if (!(cin >> x >> y)) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			x = y = 1;
			continue;
		}

		cout << "�� ���� ��ȭ���: " << avg(x, y) << endl;
	}
	cout << "���α׷��� �����մϴ�.\n";

	return 0;
}

double avg(double x, double y) {
	return (2.0 * x * y) / (x + y);
}