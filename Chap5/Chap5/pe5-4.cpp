/*
	���� 4:
	�ܸ� 10% ���� ���� ��ġ�� ���� 5% ���� ���� ��ġ�� �ʰ��ϴ� �� �� ���
*/

#include <iostream>

const double Aratio = 0.10;
const double Bratio = 0.05;

int main() {
	using namespace std;

	double A = 100000;
	double B = 100000;
	int years = 0;

	while (A >= B) {
		A += Aratio * 100000;
		B *= 1.05;
		++years;
	}

	cout << years << "�� ��: " << endl;
	cout << "A�� ���� ��ġ: " << A << endl;
	cout << "B�� ���� ��ġ: " << B << endl;

	return 0;
}