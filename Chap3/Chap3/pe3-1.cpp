/*
	���� 1:
	- Ű�� ��Ƽ���� ������ �Է¹ް� ���Ϳ� ��Ƽ���� ������ ��ȯ
	- ȯ�� �μ��� const ��ȣ ��� ���
*/

#include <iostream>

int main() {
	using namespace std;

	int centimeter;
	cout << "Ű�� ������ ��Ƽ���� ������ �Է��Ͻÿ�: ___\b\b\b";
	cin >> centimeter;

	const double CtoM = 100.0;
	double meter = centimeter / CtoM;
	cout << "���ͷ� ��ȯ�� Ű: " << meter;

	return 0;
}