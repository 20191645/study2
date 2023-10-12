/*
	문제 2:
	CandyBar 구조체의 멤버를 설정, 출력하는 함수
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct CandyBar {
	char name[40];
	double weight;
	int calorie;
};

void set(CandyBar& candy, const char* name = "Milennium Munch", double weight = 2.85, int calorie = 350);
void print(const CandyBar& candy);

int main() {
	CandyBar candy;
	set(candy);
	print(candy);
	set(candy, "Candy1");
	print(candy);
	set(candy, "Candy2", 3.50);
	print(candy);
	set(candy, "Candy3", 4.50, 500);
	print(candy);

	return 0;
}

void set(CandyBar& candy, const char* name, double weight, int calorie) {
	strcpy(candy.name, name);
	candy.weight = weight;
	candy.calorie = calorie;
}

void print(const CandyBar& candy) {
	cout << "이름: " << candy.name << endl;
	cout << "종량: " << candy.weight << endl;
	cout << "칼로리: " << candy.calorie << endl;
	cout << endl;
}