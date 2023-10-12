/*
	문제 4:
	회원 명부를 bop 구조체로 정의하고
	bop 구조체 배열을 초기화하여 회원 명부 열람 루프 만들기
*/

#include <iostream>

const int strsize = 30;

// Benevolent Order of Programmers 회원 구조체
struct bop {
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
	// 0 = fullname, 1 = title, 2 = bopname
};

int main() {
	using namespace std;

	bop bop_list[3] = {
		{"Hong Gil Dong","Author 5", "abcd1234",0 },
		{"Chris","title2","id3",1},
		{"Joy","Fantasy","everyone",2}
	};

	cout << "Benevolent Order of Programmers" << endl;
	cout << "a. 실명으로 열람\t\t\t"
		"b. 직함으로 열람" << endl;
	cout << "c. BOP 아이디로 열람\t\t\t"
		"d. 회원이 지정한 것으로 열람" << endl;
	cout << "q. 종료" << endl;

	char ch = 'A';
	int i;
	cout << "원하는 것을 선택하십시오: ";
	while ((ch = cin.get()) && ch != 'q') {
		switch (ch) {
		case 'a':
			for (i = 0; i < 3; i++)
				cout << bop_list[i].fullname << endl;
			break;

		case 'b':
			for (i = 0; i < 3; i++)
				cout << bop_list[i].title << endl;
			break;

		case 'c':
			for (i = 0; i < 3; i++)
				cout << bop_list[i].bopname << endl;
			break;

		case 'd':
			for (i = 0; i < 3; i++) {
				switch (bop_list[i].preference) {
				case 0:
					cout << bop_list[i].fullname << endl;
					break;
				case 1:
					cout << bop_list[i].title << endl;
					break;
				case 2:
					cout << bop_list[i].bopname << endl;
					break;
				}
			}
			break;
		}
		
		cin.get();
		cout << "원하는 것을 선택하십시오: ";
	}
	cout << "프로그램을 종료합니다.\n";

	return 0;
}