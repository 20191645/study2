/*
	���� 9:
	pe6-6.cpp�� ���� ������ ���Ϸκ��� ������ �򵵷� ����
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct donation {
	string name;
	double money;
};

int main() {
	ifstream inFile;
	inFile.open("Practice9.txt");

	if (inFile.is_open()) {
		int n;
		inFile >> n;
		inFile.get();

		donation* person = new donation[n];
		for (int i = 0; i < n; i++) {
			getline(inFile, person[i].name);
			inFile >> person[i].money;
			inFile.get();
		}

		if (n == 0)
			cout << "����ڰ� �����ϴ�.\n";
		else {
			cout << "-��� �����-" << endl;
			for (int i = 0; i < n; i++) {
				if (person[i].money >= 10000) {
					cout << "�̸�: " << person[i].name << ", "
						<< "��α�: " << person[i].money << endl;
				}
			}

			cout << "-�Ҿ� �����-" << endl;
			for (int i = 0; i < n; i++) {
				if (person[i].money < 10000) {
					cout << "�̸�: " << person[i].name << ", "
						<< "��α�: " << person[i].money << endl;
				}
			}
		}

		delete[]person;
	}
	else {
		cout << "������ �� �� �����ϴ�.\n";
	}

	inFile.close();
	return 0;
}