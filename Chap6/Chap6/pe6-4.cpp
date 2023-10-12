/*
	���� 4:
	ȸ�� ��θ� bop ����ü�� �����ϰ�
	bop ����ü �迭�� �ʱ�ȭ�Ͽ� ȸ�� ��� ���� ���� �����
*/

#include <iostream>

const int strsize = 30;

// Benevolent Order of Programmers ȸ�� ����ü
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
	cout << "a. �Ǹ����� ����\t\t\t"
		"b. �������� ����" << endl;
	cout << "c. BOP ���̵�� ����\t\t\t"
		"d. ȸ���� ������ ������ ����" << endl;
	cout << "q. ����" << endl;

	char ch = 'A';
	int i;
	cout << "���ϴ� ���� �����Ͻʽÿ�: ";
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
		cout << "���ϴ� ���� �����Ͻʽÿ�: ";
	}
	cout << "���α׷��� �����մϴ�.\n";

	return 0;
}