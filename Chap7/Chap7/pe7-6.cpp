/*
	문제 6:
	Fill_array(): double형 배열 입력
	Show_array(): double형 배열 출력
	Reverse_array(): double형 배열 값 순서 뒤집기
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

	cout << "배열의 원소를 최대 " << size << "개까지 입력하십시오: ";
	while (cin >> arr[i] && i < size) {
		++i;
	}

	return i;
}

void Show_array(double arr[], int size) {
	cout << "배열의 원소: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void Reverse_array(double arr[], int size) {
	cout << "-배열 뒤집기-" << endl;
	double temp;
	for (int i = 0; i < size / 2; i++) {
		temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
}