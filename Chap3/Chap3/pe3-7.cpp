/*
	���� 7:
	�ֹ��� �Һ��� ���� ��Ÿ�Ϸ� �Է¹ް�, �̱� ��Ÿ�Ϸ� ��ȯ
*/

#include <iostream>

int main() {
	using namespace std;

	double liter;
	cout << "�ֹ��� �Һ��� ���� ��Ÿ�Ϸ� �Է��Ͻÿ�: ";
	cin >> liter;

	const double GALLON = 3.875;
	const double MILE = 62.14;

	double gallon = liter / GALLON;
	double mpg = MILE / gallon;

	cout << "�̱� ��Ÿ�Ϸ� ��ȯ�� �ֹ��� �Һ�: " << mpg << endl;

	return 0;
}