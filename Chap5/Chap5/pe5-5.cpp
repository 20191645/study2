/*
	문제 5:
	int형 배열에 월간 판매량을 입력받고 배열 내용 합계 계산
*/

#include <iostream>
#include <string>

int main() {
	using namespace std;

	string months[12] =
	{ "January","February","March","April",
		"May","June","July","August",
		"September","October","November","December" };
	int sales[12];
	int sum = 0;

	for (int i = 0; i < 12; i++) {
		cout << months[i] << ": ";
		cin >> sales[i];
		sum += sales[i];
	}
	cout << "연간 총 판매량: " << sum << endl;

	return 0;
}