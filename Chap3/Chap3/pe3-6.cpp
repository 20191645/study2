/*
	���� 6:
	������ �Ÿ��� ����, �ֹ��� ���� �������� �Է¹ް� ������ ���� ���� ����
*/

#include <iostream>

int main() {
	using namespace std;

	int mile, gallon;
	cout << "������ �Ÿ��� ���� ������ �Է��Ͻÿ�: ";
	cin >> mile;
	cout << "�Һ��� �ֹ����� ���� ���� ������ �Է��Ͻÿ�: ";
	cin >> gallon;

	cout << "������ ���� ��: " << (double)mile / gallon << endl;
	
	return 0;
}