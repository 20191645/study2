/*
	문제 9:
	- getinfo(): student 구조체 배열 저장
	- display1(): student 구조체 출력 [매개변수: 구조체]
	- display2(): student 구조체 출력 [매개변수: 구조체 주소]
*/

#include <iostream>
using namespace std;

const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(student* ps);
void display3(student pa[], int n);

int main() {
	cout << "학급의 학생 수를 입력하십시오: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;

	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++) {
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	cout << "프로그램을 종료합니다.\n";
	
	return 0;
}

int getinfo(student pa[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		cout << (i + 1) << "번째 학생:\n";
		cout << "이름: ";
		cin.getline(pa[i].fullname, SLEN);
		if (pa[i].fullname[0] == '\0')
			break;
		cout << "취미: ";
		cin.getline(pa[i].hobby, SLEN);
		cout << "OOP LEVEL: ";
		cin >> pa[i].ooplevel;
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;

	return i;
}

void display1(student st) {
	cout << "이름: " << st.fullname << endl;
	cout << "취미: " << st.hobby << endl;
	cout << "OOP LEVEL: " << st.ooplevel << endl << endl;
}

void display2(student* ps) {
	cout << "이름: " << ps->fullname << endl;
	cout << "취미: " << ps->hobby << endl;
	cout << "OOP LEVEL: " << ps->ooplevel << endl << endl;
}

void display3(student pa[], int n) {
	cout << "전체 학생 정보:\n";
	for (int i = 0; i < n; i++) {
		cout << (i + 1) << "번째 학생:\n";
		cout << "이름: " << pa[i].fullname << endl;
		cout << "취미: " << pa[i].hobby << endl;
		cout << "OOP LEVEL: " << pa[i].ooplevel << endl << endl;
	}
}