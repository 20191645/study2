/*
	���� 2:
	Ű�� ��Ʈ, ��ġ ������ ���� ü���� �Ŀ�� ������ ���´�
	�̸� ���� BMI�� ����Ͽ� ���
*/

#include <iostream>
#include <cmath>

int main() {
	using namespace std;

	int feet, inch, pound;
	cout << "Ű�� ��Ʈ�� ��ġ ������ �Է��Ͻʽÿ�: ";
	cin >> feet >> inch;
	cout << "ü���� �Ŀ�� ������ �Է��Ͻʽÿ�: ";
	cin >> pound;

	const int INCH = 12;
	const double HEIGHT = 0.0254;
	const double WEIGHT = 2.2;

	double height = (feet * INCH + inch) * HEIGHT;
	double weight = pound / WEIGHT;
	double bmi = weight / pow(height, 2);
	cout << "����� BMI: " << bmi << endl;

	return 0;
}