/*
	문제 6:
	CandyBar 구조체 배열을 선언, 초기화, 출력
*/

#include <iostream>

struct CandyBar {
	char name[20];
	double weight;
	int kalorie;
};

int main() {
	using namespace std;

	CandyBar snacks[3] = {
		{"A",10,100},
		{"B",20,200},
		{"C",30,300}
	};

	cout << "snacks[0]: " << snacks[0].name << ", " << snacks[0].weight << ", " << snacks[0].kalorie << endl;
	cout << "snacks[1]: " << snacks[1].name << ", " << snacks[1].weight << ", " << snacks[1].kalorie << endl;
	cout << "snacks[2]: " << snacks[2].name << ", " << snacks[2].weight << ", " << snacks[2].kalorie << endl;

	return 0;
}