/*
	���� 4:
	�� ���� ���� ������ �Է¹ް� ��, ��, ��, �ʷ� ����ϱ�
*/

#include <iostream>

int main() {
	using namespace std;

	long seconds;
	cout << "�� ���� �Է��Ͻÿ�: ";
	cin >> seconds;

	const int DAY = 24;
	const int HOUR = 60;
	const int MINUTE = 60;

	int second = seconds % MINUTE;
	int minute = (seconds / MINUTE) % HOUR;
	int hour = (seconds / MINUTE / HOUR) % DAY;
	int day = seconds / MINUTE / HOUR / DAY;

	cout << seconds << "�� = " << day << "��, " << hour << "�ð�, ";
	cout << minute << "��, " << second << "��" << endl;

	return 0;
}