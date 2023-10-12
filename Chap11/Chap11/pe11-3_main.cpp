/*
	���� 3:
	pe11-1���� N�� �õ����� ���� �ְ�, ����, ��� ���� �� ����
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "pe11-3.h"

int main() {
	using std::cout;
	using std::cin;
	using std::endl;
	using VECTOR::Vector;

	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	// �߰�
	int n;
	double max = 0.0;
	double min = DBL_MAX;
	double avg = 0.0;

	cout << "�õ� Ƚ���� �Է��Ͻʽÿ�: ";
	cin >> n;
	cout << "��ǥ �Ÿ��� �Է��Ͻʽÿ�: ";
	cin >> target;
	cout << "������ �Է��Ͻʽÿ�: ";
	cin >> dstep;

	for (int i = 0; i < n; i++) {
		while (result.magval() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}

		if (steps > max)
			max = steps;
		if (steps < min)
			min = steps;
		avg += steps;

		steps = 0;
		result.reset(0.0, 0.0);
	}

	cout << "�ְ� ���� ��: " << max << endl;
	cout << "���� ���� ��: " << min << endl;
	cout << n << "�� �õ����� �� ��� ���� ��: " << avg / n << endl;

	cout << "���α׷��� �����մϴ�.\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	return 0;
}