/*
	���� 1:
	������ �о� ȭ�鿡 �ٽ� ����ϴµ� ������ �� �ܰ辿 ���� ����
*/

#include <iostream>

int main() {
	using namespace std;
	
	char firstName[20], lastName[20];
	char grade;
	int age;

	cout << "���� �۽�Ʈ ����(�̸�): ";
	cin.getline(firstName, 19);
	cout << "���� ��Ʈ ����(��): ";
	cin.getline(lastName, 19);
	cout << "�л��� ���ϴ� ����: ";
	cin >> grade;
	grade += 1;
	cout << "����: ";
	cin >> age;

	cout << "����: " << lastName << ", " << firstName << endl;
	cout << "����: " << grade << endl;
	cout << "����: " << age << endl;

	return 0;
}