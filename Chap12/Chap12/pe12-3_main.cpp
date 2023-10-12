/*
	문제 3:
	Stock 클래스 개선
	- string 클래스 객체 대신 동적 대입 메모리 사용
	- Show() 멤버 함수를 오버로딩된 operator<<()로 대체
*/

#include <iostream>
#include "pe12-3.h"

const int STKS = 4;

int main() {
	Stock stocks[STKS] = {
		Stock("NanoSmart",12,20.0),
		Stock("Boffo Objects",200,2.0),
		Stock("Monolithic Obelisks",130,3.25),
		Stock("Fleep Enterprises",60,6.5)
	};

	std::cout << "보유 주식 리스트:\n";
	int i;
	for (i = 0; i < STKS; i++)
		std::cout << stocks[i];

	const Stock* top = &stocks[0];
	for (i = 1; i < STKS; i++)
		top = &top->topval(stocks[i]);

	std::cout << "\n최고 가치의 주식:\n";
	std::cout << *top;

	return 0;
}