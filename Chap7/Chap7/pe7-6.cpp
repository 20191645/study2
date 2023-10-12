/*
	���� 6:
	Fill_array(): double�� �迭 �Է�
	Show_array(): double�� �迭 ���
	Reverse_array(): double�� �迭 �� ���� ������
*/

#include <iostream>
using namespace std;

const int ArSize = 6;

int Fill_array(double[], int);
void Show_array(double[], int);
void Reverse_array(double[], int);

int main() {
	double arr[ArSize];
	int size = Fill_array(arr, ArSize);
	Show_array(arr, size);
	Reverse_array(arr, size);
	Show_array(arr, size);

	return 0;
}

int Fill_array(double arr[], int size) {
	int i = 0;

	cout << "�迭�� ���Ҹ� �ִ� " << size << "������ �Է��Ͻʽÿ�: ";
	while (cin >> arr[i] && i < size) {
		++i;
	}

	return i;
}

void Show_array(double arr[], int size) {
	cout << "�迭�� ����: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void Reverse_array(double arr[], int size) {
	cout << "-�迭 ������-" << endl;
	double temp;
	for (int i = 0; i < size / 2; i++) {
		temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
}