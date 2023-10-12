/*
	���� 8:
	array Ŭ������ ������� �ʰ� �ۼ�
*/

#include <iostream>
#include <string>
#include <array>

const int Seasons = 4;
const char* Sname[4] = { "Spring","Summer","Fall","Winter" };

struct expense {
	double exp[4];
};

void fill(expense*);
void show(expense);

int main() {
	expense temp;
	fill(&temp);
	show(temp);

	return 0;
}

void fill(expense* temp) {
	using namespace std;

	for (int i = 0; i < Seasons; i++) {
		cout << Sname[i] << "�� �ҿ�Ǵ� ���: ";
		cin >> temp->exp[i];
	}
}

void show(expense temp) {
	using namespace std;

	double total = 0.0;
	cout << "\n������ ���\n";
	for (int i = 0; i < Seasons; i++) {
		cout << Sname[i] << " : $" << temp.exp[i] << endl;
		total += temp.exp[i];
	}
	cout << "�� ��� : $" << total << endl;
}