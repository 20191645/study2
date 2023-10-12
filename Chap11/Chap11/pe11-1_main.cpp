/*
	���� 1:
	- ������ Vector Ŭ������ �̿��Ͽ� ��ǥ �Ÿ��� ������ �������� ���� ���� ���� ��ġ�� ����
	- �������� ��ġ�� ���Ͽ� ���
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "pe11-1.h"

int main() {
	using namespace std;
	using VECTOR::Vector;

	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	// ���� �Է��� ���� �߰� �κ�
	ofstream os;
	os.open("randwalk1.txt");

	cout << "��ǥ �Ÿ��� �Է��Ͻʽÿ�(�������� q): ";
	while (cin >> target) {
		cout << "������ �Է��Ͻʽÿ�: ";
		if (!(cin >> dstep))
			break;

		os << "��ǥ �Ÿ�: " << target << ", ����: " << dstep << endl;
		os << steps << ": " << result << endl;

		while (result.magval() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			os << steps << ": " << result << endl;
		}

		os << steps << " ������ ���� �� ������ ���� ��ġ:\n";
		os << result << endl;
		result.polar_mode();
		os << " �Ǵ�\n" << result << endl;
		os << "������ ��տ��� ��� ��� �Ÿ� = "
			<< result.magval() / steps << endl;

		steps = 0;
		result.reset(0.0, 0.0);
		cout << "��ǥ �Ÿ��� �Է��Ͻʽÿ�(�������� q): ";
	}
	cout << "���α׷��� �����մϴ�.\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	os.close();

	return 0;
}