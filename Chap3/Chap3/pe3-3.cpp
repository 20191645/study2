/*
	���� 3:
	������ ��, ��, �� ������ ��û�Ͽ� 10���� �������� ���
*/

#include <iostream>

int main() {
	using namespace std;

	int degree, minute, second;
	cout << "������ ��, ��, �� ������ �Է��Ͻÿ�: \n";
	cout << "����, ������ �Է��Ͻÿ�: ";
	cin >> degree;
	cout << "������, �а��� �Է��Ͻÿ�: ";
	cin >> minute;
	cout << "������, �ʰ��� �Է��Ͻÿ�: ";
	cin >> second;

	const double RADIAN = 60.0;
	double radian = degree + (minute / RADIAN) + (second / RADIAN / RADIAN);
	cout << degree << "��, " << minute << "��, " << second << "�� = " << radian << "��\n";

	return 0;
}