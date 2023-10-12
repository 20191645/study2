/*
	문제 6:
	pe14-5의 클래스들의 데이터를 이용하여 표준 C++ 입출력과 파일 입출력을 사용
*/

#include <iostream>
#include <fstream>
#include "pe17-6.h"

const int MAX = 10;

int main(int argc, char* argv[]) {
	using namespace std;
	
	employee* pc[MAX];
	int classtype;
	char ch;
	int i = 0;

	ifstream fin("pe17-06.txt");
	if (fin.is_open()) {
		while ((fin >> classtype).get(ch)) {
			switch (classtype) {
			case Employee: pc[i] = new employee;	break;
			case Manager: pc[i] = new manager;	break;
			case Fink: pc[i] = new fink;	break;
			case Highfink: pc[i] = new highfink;	break;
			}
			
			pc[i++]->GetAll(fin);
		}
	}
	fin.close();
	
	for (i; i < MAX; i++) {
		cout << "생성할 객체형을 선택하십시오:\n";
		cout << "1. employee\t 2. manager\n"
			<< "3. fink\t 4. highfink\n"
			<< "나머지 키 입력 시 입력 종료\n";
		
		if (!(cin >> classtype).get()) {
			cout << "입력을 종료합니다.\n";
			break;
		}
		if (classtype != Employee && classtype != Manager &&
			classtype != Fink && classtype != Highfink) {
			cout << "입력을 종료합니다.\n";
			break;
		}

		switch (classtype) {
		case Employee: pc[i] = new employee;	break;
		case Manager: pc[i] = new manager;	break;
		case Fink: pc[i] = new fink;	break;
		case Highfink: pc[i] = new highfink;	break;
		}
		pc[i]->SetAll();
	}

	int index = i;
	ofstream fout("pe17-06.txt");
	for (i = 0; i < index; i++) {
		pc[i]->WriteType(fout);
		pc[i]->WriteAll(fout);
		pc[i]->ShowAll();
		cout << endl;
	}
	fout.close();

	return 0;
}