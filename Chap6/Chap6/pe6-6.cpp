/*
	문제 6:
	동적으로 대입된 구조체 배열을 이용하여 기부금을 추적하는 프로그램
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
	cout << "기부할 사람이 몇 명입니까? ";
	cin >> n;
	cin.get();

	donation* person = new donation[n];
	for (int i = 0; i < n; i++) {
		cout << (i + 1) << "번째 사람:\n";
		cout << "이름: ";
		getline(cin, person[i].name);
		cout << "기부금: ";
		cin >> person[i].money;
		cin.get();
	}

	if (n == 0)
		cout << "기부자가 없습니다.\n";
	else {
		cout << "-고액 기부자-" << endl;
		for (int i = 0; i < n; i++) {
			if (person[i].money >= 10000) {
				cout << "이름: " << person[i].name << ", " 
					<< "기부금: " << person[i].money << endl;
			}
		}

		cout << "-소액 기부자-" << endl;
		for (int i = 0; i < n; i++) {
			if (person[i].money < 10000) {
				cout << "이름: " << person[i].name << ", "
					<< "기부금: " << person[i].money << endl;
			}
		}
	}

	delete[]person;
	return 0;
}