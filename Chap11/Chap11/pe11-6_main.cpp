/*
	���� 6:
	- 6���� ���� ������ �����ε�
	- Stonewt ��ü �迭 �����Ͽ� �� ��
*/

#include <iostream>
using namespace std;
#include "pe11-6.h"

int main() {
	Stonewt arr[6] = {
		Stonewt(154),
		Stonewt(153.99),
		Stonewt(154.1)
	};

	int stone;
	double pds_left;
	for (int i = 3; i < 6; i++) {
		cout << (i + 1) << "��° Stonewt ��ü:\n";
		cout << "���氪�� �Է��Ͻʽÿ�: ";
		cin >> stone;
		cout << "�ε��Ҽ��� �Ŀ�带 �Է��Ͻʽÿ�: ";
		cin >> pds_left;
		arr[i] = Stonewt(stone, pds_left);
	}

	int number = 0;
	Stonewt temp = 154;
	Stonewt max = arr[0];
	Stonewt min = arr[0];
	for (int i = 0; i < 6; i++) {
		if (arr[i] >= temp)
			number++;
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] < min)
			min = arr[i];
	}

	cout << "�ִ� ������ ����: ";
	max.show_lbs();
	cout << "�ּ� ������ ����: ";
	min.show_stn();
	cout << "11���溸�� ũ�ų� ���� ������ ����: " << number << endl;

	return 0;
}