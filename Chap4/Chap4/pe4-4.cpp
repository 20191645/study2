/*
	���� 4:
	pe4-3.cpp�� ���� ������ string ��ü�� �̿��Ͽ� ����
*/

#include <iostream>
#include <string>

int main() {
	using namespace std;

	string firstName, lastName, name;

	cout << "�۽�Ʈ ����(�̸�)�� �Է��Ͻÿ�: ";
	getline(cin, firstName);
	cout << "��Ʈ ����(��)�� �Է��Ͻÿ�: ";
	getline(cin, lastName);
	name = lastName;
	name += ", ";
	name += firstName;
	cout << "�ϳ��� ���ڿ��� �����: " << name << endl;

	return 0;
}