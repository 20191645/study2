/*
	���� 3:
	string ��ü�� ������ �빮�ڷ� ��ȯ�ϴ� �Լ�
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void up(string& str);

int main() {
	string str;
	cout << "���ڿ��� �Է��Ͻÿ� (�������� q): ";
	while (getline(cin, str) && str != "q") {
		up(str);
		cout << str << endl;
		cout << "���� ���ڿ��� �Է��Ͻÿ� (�������� q): ";
	}
	cout << "��.\n";

	return 0;
}

void up(string& str) {
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
}