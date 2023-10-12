/*
	문제 7:
	'피자 회사 이름, 피자 지름, 피자 중량'을 기록하는 구조체 템플릿 설계
*/

#include <iostream>

struct Pizza {
	char name[20];
	double diameter;
	double weight;
};

int main() {
	using namespace std;

	Pizza pizza;
	cout << "피자 회사의 이름을 입력하시오: ";
	cin.getline(pizza.name, 19);
	cout << "피자의 지름을 입력하시오: ";
	cin >> pizza.diameter;
	cout << "피자의 중량을 입력하시오: ";
	cin >> pizza.weight;
	cout << endl;

	cout << "피자 회사의 이름: " << pizza.name << endl;
	cout << "피자의 지름: " << pizza.diameter << endl;
	cout << "피자의 중량: " << pizza.weight << endl;

	return 0;
}