/*
	문제 9:
	pe4-6.cpp와 같은 내용을 배열 선언에서 new를 사용
*/

#include <iostream>

struct CandyBar {
	char name[20];
	double weight;
	int kalorie;
};

int main() {
	using namespace std;

	CandyBar* snacks = new CandyBar[3];
	snacks[0] = { "A", 10, 100 };
	snacks[1] = { "B",20,200 };
	snacks[2] = { "C",30,300 };

	cout << "snacks[0]: " << snacks[0].name << ", " << snacks[0].weight << ", " << snacks[0].kalorie << endl;
	cout << "snacks[1]: " << snacks[1].name << ", " << snacks[1].weight << ", " << snacks[1].kalorie << endl;
	cout << "snacks[2]: " << snacks[2].name << ", " << snacks[2].weight << ", " << snacks[2].kalorie << endl;

	delete[] snacks;

	return 0;
}