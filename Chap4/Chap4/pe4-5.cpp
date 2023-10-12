/*
	문제 5:
	CandyBar 구조체 변수를 선언, 초기화, 출력
*/

#include <iostream>

struct CandyBar {
	char name[20];
	double weight;
	int kalorie;
};

int main() {
	using namespace std;

	CandyBar snack = { "Mocha Munch", 2.3,350 };
	cout << "Name: " << snack.name << endl;
	cout << "Weight: " << snack.weight << endl;
	cout << "Kalorie: " << snack.kalorie << endl;

	return 0;
}