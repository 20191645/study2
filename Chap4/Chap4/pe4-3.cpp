/*
	���� 3:
	�̸�, ���� �Է¹޾� "��, �̸�" ������ ��3�� ���ڿ��� �����Ͽ� ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

int main() {
	using namespace std;

	char firstName[20], lastName[20], name[40];

	cout << "�۽�Ʈ ����(�̸�)�� �Է��Ͻÿ�: ";
	cin.getline(firstName, 19);
	cout << "��Ʈ ����(��)�� �Է��Ͻÿ�: ";
	cin.getline(lastName, 19);
	strcpy(name, lastName);
	strcat(name, ", ");
	strcat(name, firstName);
	cout << "�ϳ��� ���ڿ��� �����: " << name << endl;

	return 0;
}