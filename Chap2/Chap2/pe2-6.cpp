/*
	���� 6:
	�Ÿ��� �Ű������� ���޹޾� õ�� ������ ȯ���Ͽ� �����ϴ� �Լ� �ۼ�
*/

#include <iostream>
using namespace std;

double Years(double);

int main() {
	double light;
	cout << "���� ���� �Է��ϰ� Enter Ű�� �����ʽÿ�: ";
	cin >> light;
	cout << light << " ������ " << Years(light) << " õ�� �����Դϴ�." << endl;

	return 0;
}

double Years(double light) {
	return light * 63240;
}