/*
	���� 1:
	- �Է¿��� $�� ���� �������� ���� �� ī��Ʈ
	- $�� �Է� ��Ʈ���� ���� �α�
*/

#include <iostream>
#include <string>

int main() {
	using namespace std;

	string str;
	cout << "���ڿ��� �Է��Ͻʽÿ�: ";
	getline(cin, str, '$');
	int count = str.size();
	cin.putback('$');

	cout << "�Է��� ���ڿ�: " << str << endl;
	cout << "$�� ������ �������� ���� ��: " << count << endl;

	return 0;
}