/*
	문제 6:
	- 6개의 관계 연산자 오버로딩
	- Stonewt 객체 배열 선언하여 값 비교
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
		cout << (i + 1) << "번째 Stonewt 객체:\n";
		cout << "스톤값을 입력하십시오: ";
		cin >> stone;
		cout << "부동소수점 파운드를 입력하십시오: ";
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

	cout << "최대 원소의 무게: ";
	max.show_lbs();
	cout << "최소 원소의 무게: ";
	min.show_stn();
	cout << "11스톤보다 크거나 같은 원소의 개수: " << number << endl;

	return 0;
}