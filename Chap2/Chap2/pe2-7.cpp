/*
	문제 7:
	시간, 분 값을 입력받아 출력하기
*/

#include <iostream>
using namespace std;

void ShowTime(int, int);

int main() {
	int hour;
	cout << "시간 값을 입력하시오: ";
	cin >> hour;
	int minute;
	cout << "분 값을 입력하시오: ";
	cin >> minute;
	ShowTime(hour, minute);
}

void ShowTime(int h, int m) {
	cout << "시간: " << h << ':' << m << endl;
}