/*
	문제 9:
	pe6-6.cpp와 같은 내용을 파일로부터 정보를 얻도록 수정
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
	}
	else {
		cout << "파일을 열 수 없습니다.\n";
	}

	inFile.close();
	return 0;
}