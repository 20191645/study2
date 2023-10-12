/*
	���� 2:
	���� ���ھ �ִ� 10������ �Է¹ް� �迭�� ����
*/

#include <iostream>
using namespace std;

int input(double* arr);
void output(double* arr, int size);
double avg(double* arr, int size);

int main() {
	double arr[10];
	int size = input(arr);
	if (size > 0) {
		output(arr, size);
		cout << "��� ���ھ�: " << avg(arr, size) << endl;
	}
	cout << "���α׷��� �����մϴ�.\n";

	return 0;
}

int input(double* arr) {
	int i;
	cout << "���� ���ھ �ִ� 10���� �Է��Ͻʽÿ�: ";
	for (i = 0; i < 10; i++) {
		if (!(cin >> arr[i]) || arr[i] < 0) {
			cout << "�߸��� �Է����� �Է��� ����˴ϴ�.\n";
			break;
		}
	}
	return i;
}

void output(double* arr, int size) {
	cout << "���� ���ھ�: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

double avg(double* arr, int size) {
	double result = 0;
	for (int i = 0; i < size; i++)
		result += arr[i];
	return result / size;
}