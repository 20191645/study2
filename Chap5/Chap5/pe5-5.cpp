/*
	���� 5:
	int�� �迭�� ���� �Ǹŷ��� �Է¹ް� �迭 ���� �հ� ���
*/

#include <iostream>
#include <string>

int main() {
	using namespace std;

	string months[12] =
	{ "January","February","March","April",
		"May","June","July","August",
		"September","October","November","December" };
	int sales[12];
	int sum = 0;

	for (int i = 0; i < 12; i++) {
		cout << months[i] << ": ";
		cin >> sales[i];
		sum += sales[i];
	}
	cout << "���� �� �Ǹŷ�: " << sum << endl;

	return 0;
}