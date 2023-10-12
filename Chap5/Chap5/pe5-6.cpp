/*
	문제 6:
	pe5-5.cpp를 수정하여 3년 간의 월간 판매량을 2차원 배열에 저장
*/

#include <iostream>

int main() {
	using namespace std;

	string months[12] =
	{ "January","February","March","April",
		"May","June","July","August",
		"September","October","November","December" };
	int sales[3][12];
	int sum[3] = { 0 };

	for (int i = 0; i < 3; i++) {
		cout << (i + 1) << "년째 판매량: " << endl;
		for (int j = 0; j < 12; j++) {
			cout << months[j] << ": ";
			cin >> sales[i][j];
			sum[i] += sales[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++)
		cout << (i + 1) << "년째 연간 판매량: " << sum[i] << endl;
	
	cout << endl;
	cout << "2년째 누적 판매량: " << sum[0] + sum[1] << endl;
	cout << "3년째 누적 판매량: " << sum[0] + sum[1] + sum[2] << endl;

	return 0;
}