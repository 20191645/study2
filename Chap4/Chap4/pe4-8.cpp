/*
	문제 8:
	pe4-7.cpp와 같은 내용을 new를 사용하여 구조체 대입
*/

#include <iostream>

struct Pizza {
	char name[20];
	double diameter;
	double weight;
};

int main() {
	using namespace std;

	Pizza* pizza = new Pizza;
	cout << "피자의 지름을 입력하시오: ";
	cin >> pizza->diameter;
	cout << "피자 회사의 이름을 입력하시오: ";
	cin.get();
	cin.getline(pizza->name, 19);
	cout << "피자의 중량을 입력하시오: ";
	cin >> pizza->weight;
	cout << endl;

	cout << "피자의 지름: " << pizza->diameter << endl;
	cout << "피자 회사의 이름: " << pizza->name << endl;
	cout << "피자의 중량: " << pizza->weight << endl;
	delete pizza;

	return 0;
}