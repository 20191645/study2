/*
	���� 5:
	���� �µ��� �Ű������� ���޹޾� ȭ�� �µ��� ȯ���Ͽ� �����ϴ� �Լ� �ۼ�
*/

#include <iostream>
using namespace std;

double CelToFah(double);

int main() {
	double celsius;
	cout << "���� �µ��� �Է��ϰ� Enter Ű�� �����ʽÿ�: ";
	cin >> celsius;
	cout << "���� �µ��� ȭ���� " << CelToFah(celsius) << "�Դϴ�" << endl;

	return 0;
}

double CelToFah(double cel)
{
	return 1.8 * cel + 32.0;
}