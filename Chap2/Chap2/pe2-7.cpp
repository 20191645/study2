/*
	���� 7:
	�ð�, �� ���� �Է¹޾� ����ϱ�
*/

#include <iostream>
using namespace std;

void ShowTime(int, int);

int main() {
	int hour;
	cout << "�ð� ���� �Է��Ͻÿ�: ";
	cin >> hour;
	int minute;
	cout << "�� ���� �Է��Ͻÿ�: ";
	cin >> minute;
	ShowTime(hour, minute);
}

void ShowTime(int h, int m) {
	cout << "�ð�: " << h << ':' << m << endl;
}