/*
	문제 3:
	main()을 포함하여 3개의 사용자 정의 함수 사용
*/

#include <iostream>
using namespace std;

void PrintOne() {
	cout << "Three blind mice" << endl;
}

void PrintTwo() {
	cout << "See how they run" << endl;
}

int main() {
	PrintOne();
	PrintOne();
	PrintTwo();
	PrintTwo();

	return 0;
}