/*
	문제 2:
	골프 스코어를 최대 10개까지 입력받고 배열에 저장
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
		cout << "평균 스코어: " << avg(arr, size) << endl;
	}
	cout << "프로그램을 종료합니다.\n";

	return 0;
}

int input(double* arr) {
	int i;
	cout << "골프 스코어를 최대 10까지 입력하십시오: ";
	for (i = 0; i < 10; i++) {
		if (!(cin >> arr[i]) || arr[i] < 0) {
			cout << "잘못된 입력으로 입력이 종료됩니다.\n";
			break;
		}
	}
	return i;
}

void output(double* arr, int size) {
	cout << "골프 스코어: ";
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