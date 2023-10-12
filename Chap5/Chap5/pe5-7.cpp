/*
	문제 7:
	- '제작업체, 제작년도'를 보관하는 car 구조체 설계
	- new를 사용하여 car 구조체 동적 배열 만든다
*/

#include <iostream>

struct car {
	char name[20];
	int year;
};

int main() {
	using namespace std;

	int n;
	cout << "몇 대의 차를 목록으로 관리하겠습니까? ";
	cin >> n;
	car* cars = new car[n];
	
	for (int i = 0; i < n; i++) {
		cin.get();
		cout << "자동차 #" << (i + 1) << ":\n";
		cout << "제작업체: ";
		cin.getline(cars[i].name, 20);
		cout << "제작년도: ";
		cin >> cars[i].year;
	}

	cout << "현재 귀하가 보유하고 있는 자동차 목록은 다음과 같습니다.\n";
	for (int i = 0; i < n; i++) {
		cout << cars[i].year << "년형 " << cars[i].name << endl;
	}

	delete[]cars;

	return 0;
}