/*
	���� 1:
	ȸ�� �˻��ϴ� �Լ� �����ϵ� ��ҹ��� ����, ��ĭ, ������ �Ű澲�� �ʴ´�
*/

#include <iostream>
#include <string>
using namespace std;

bool palindrome(string& str);

int main() {
	string str;
	cout << "ȸ�� �˻縦 ������ ���ڿ��� �Է��Ͻʽÿ�(�������� quit):\n";
	while (cin >> str && str != "quit") {
		if (palindrome(str))
			cout << "�ش� ���ڿ��� ȸ���Դϴ�.\n";
		else
			cout << "�ش� ���ڿ��� ȸ���� �ƴմϴ�.\n";

		cout << "ȸ�� �˻縦 ������ ���ڿ��� �Է��Ͻʽÿ�(�������� quit):\n";
	}

	return 0;
}

bool palindrome(string& str) {
	string temp = str;
	// ���ڿ��� ������ �Լ�
	reverse(temp.begin(), temp.end());

	if (str == temp)
		return true;
	else
		return false;
}