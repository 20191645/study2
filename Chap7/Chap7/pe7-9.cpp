/*
	���� 9:
	- getinfo(): student ����ü �迭 ����
	- display1(): student ����ü ��� [�Ű�����: ����ü]
	- display2(): student ����ü ��� [�Ű�����: ����ü �ּ�]
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
	cout << "�б��� �л� ���� �Է��Ͻʽÿ�: ";
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
	cout << "���α׷��� �����մϴ�.\n";
	
	return 0;
}

int getinfo(student pa[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		cout << (i + 1) << "��° �л�:\n";
		cout << "�̸�: ";
		cin.getline(pa[i].fullname, SLEN);
		if (pa[i].fullname[0] == '\0')
			break;
		cout << "���: ";
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
	cout << "�̸�: " << st.fullname << endl;
	cout << "���: " << st.hobby << endl;
	cout << "OOP LEVEL: " << st.ooplevel << endl << endl;
}

void display2(student* ps) {
	cout << "�̸�: " << ps->fullname << endl;
	cout << "���: " << ps->hobby << endl;
	cout << "OOP LEVEL: " << ps->ooplevel << endl << endl;
}

void display3(student pa[], int n) {
	cout << "��ü �л� ����:\n";
	for (int i = 0; i < n; i++) {
		cout << (i + 1) << "��° �л�:\n";
		cout << "�̸�: " << pa[i].fullname << endl;
		cout << "���: " << pa[i].hobby << endl;
		cout << "OOP LEVEL: " << pa[i].ooplevel << endl << endl;
	}
}