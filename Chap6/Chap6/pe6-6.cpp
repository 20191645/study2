/*
	���� 6:
	�������� ���Ե� ����ü �迭�� �̿��Ͽ� ��α��� �����ϴ� ���α׷�
*/

#include <iostream>
#include <string>
using namespace std;

struct donation {
	string name;
	double money;
};

int main() {
	int n;
	cout << "����� ����� �� ���Դϱ�? ";
	cin >> n;
	cin.get();

	donation* person = new donation[n];
	for (int i = 0; i < n; i++) {
		cout << (i + 1) << "��° ���:\n";
		cout << "�̸�: ";
		getline(cin, person[i].name);
		cout << "��α�: ";
		cin >> person[i].money;
		cin.get();
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
	return 0;
}