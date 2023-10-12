/*
	문제 2:
	double형 array에 최대 10개의 기부금 입력받고
	평균과 평균보다 큰 기부금 개수 출력
*/

#include <iostream>
#include <array>
#include <cctype>

const int ArSize = 10;

int main() {
	using namespace std;

	array<double, 10> arr;
	int i;
	cout << "기부금 최대 10개까지 입력:\n";
	for (i = 0; i < ArSize; i++) {
		if (!(cin >> arr[i]))
			break;
	}

	double avg = 0.0;
	for (int j = 0; j < i; j++)
		avg += arr[j];
	avg /= i;

	int count = 0;
	for (int j = 0; j < i; j++) {
		if (arr[j] > avg)
			++count;
	}

	cout << "입력된 기부금 평균: " << avg << endl;
	cout << "평균보다 큰 기부금 수: " << count << endl;

	return 0;
}