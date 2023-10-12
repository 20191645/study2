/*
	���� 2:
	pe16-1�� ���� ������ Ǯ�� ��ҹ���, ��ĭ, ������ ���� ������
*/

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

bool palindrome(string& str);

int main() {
	string str;
	cout << "ȸ�� �˻縦 ������ ���ڿ��� �Է��Ͻʽÿ�(�������� quit):\n";
	while (getline(cin, str) && str != "quit") {
		if (palindrome(str))
			cout << "�ش� ���ڿ��� ȸ���Դϴ�.\n";
		else
			cout << "�ش� ���ڿ��� ȸ���� �ƴմϴ�.\n";

		cout << "ȸ�� �˻縦 ������ ���ڿ��� �Է��Ͻʽÿ�(�������� quit):\n";
	}

	return 0;
}

bool palindrome(string& str) {
	// ��ҹ���, ��ĭ, ������ �� ó��
	string::iterator it = copy_if(str.begin(), str.end(), str.begin(), isalpha);
	str.erase(it, str.end());
	transform(str.begin(), str.end(), str.begin(), tolower);

	// str�� ������ ���ڿ� ����
	string rts = str;
	reverse(rts.begin(), rts.end());

	if (rts == str)
		return true;
	else
		return false;
}