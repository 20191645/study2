/*
	���� 2:
	char�� �迭 ��� string Ŭ���� �̿�
*/

#include <iostream>
#include <string>

int main() {
	using namespace std;

	cout << "���� ��ô� ����Ʈ�� ���� �����ϼ̽��ϱ�?\n";
	int year;
	cin >> year;

	cout << "��ô� ���ø� ������ �ֽðڽ��ϱ�?\n";
	string address;
	cin.get();
	getline(cin, address);

	cout << "����Ʈ ���� ����: " << year << endl;
	cout << "����: " << address << endl;
	cout << "����� �Ϸ�Ǿ����ϴ�!\n";

	return 0;
}